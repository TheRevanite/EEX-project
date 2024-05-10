import cv2
import numpy as np
import serial
import time

#the images have not been uploaded - the code below is just the logical implementation of the edge detection part of our project.

def compute_match_percentage(image1, image2):
    # Load images
    img1 = cv2.imread(image1, cv2.IMREAD_GRAYSCALE)
    img2 = cv2.imread(image2, cv2.IMREAD_GRAYSCALE)

    # Initiate ORB detector
    orb = cv2.ORB_create()

    # Find keypoints and descriptors
    kp1, des1 = orb.detectAndCompute(img1, None)
    kp2, des2 = orb.detectAndCompute(img2, None)

    # Create BFMatcher object
    bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)

    # Match descriptors
    matches = bf.match(des1, des2)

    # Sort them in the order of their distance
    matches = sorted(matches, key=lambda x: x.distance)

    # Compute match percentage
    num_good_matches = len(matches)
    total_matches = min(len(kp1), len(kp2))
    match_percentage = (num_good_matches / total_matches) * 100

    return match_percentage

def preprocess_image(image_path):
    # Read the original image
    img = cv2.imread(image_path) 

    # Convert to grayscale
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Blur the image for better edge detection
    img_blur = cv2.GaussianBlur(img_gray, (3,3), 0) 
    
    # Canny Edge Detection
    edges = cv2.Canny(image=img_blur, threshold1=100, threshold2=200)

    return edges

def send_match_percentage(match_percentage):
    # Initialize serial connection
    ser = serial.Serial("COM4", 9600)
    # Wait for serial port to open
    time.sleep(2)

    # Send match percentage over serial port
    match_percentage_int=int(match_percentage)
    ser.write(str(match_percentage_int).encode())
    # Close serial connection
    ser.close()

def receive_signal():
    # Initialize serial connection
    ser = serial.Serial("COM4", 9600)
    # Wait for serial port to open
    time.sleep(2)

    # Read data from serial port
    while True:
        signal = ser.readline().decode().strip()
        if signal == "TRUE":
            print("Received signal to process next image.")
            # Close serial connection
            ser.close()
            # Process next image
            return True
        else:
            return False

def main():
    # Preprocess reference image
    #cv2.imshow('Canny Edge Detection', reference_edges)

    og_ref_images=['og_reference1.jpg','og_reference2.jpg','og_reference3.jpg','og_reference4.jpg']
    og_images=['og_image1.jpg','og_image2.jpg','og_image3.jpg','og_image4.jpg']

    for i in og_ref_images:
        x=1
        reference_edge=preprocess_image(i)
        cv2.imwrite(f'reference{x}.jpg')
        x+=1

    ref_images_array=['reference1.jpg','reference2.jpg','reference3.jpg','reference4.jpg']
    # Paths to the images you want to compare
    default=1
    while default==1:
        for i in range(4):
            image_edge=preprocess_image(og_images[i])
            cv2.imwrite('final_image.jpg')
            referencepath = ref_images_array[i]
            imagepath = 'final_image.jpg'
            # Compute match percentage
            match_percentage = compute_match_percentage(referencepath, imagepath)
            print("Match Percentage:", match_percentage)

            # Send match percentage over serial port
            send_match_percentage(match_percentage)

            # Receive signal from Arduino to process next image
            receive_signal()
            if receive_signal():
                continue
            else:
                print("Did not receive a signal to continue, stopping the process...")
                break
        default=int(input(("Press 1 to continue processing, or 0 to end...")))
    if default==0:
        exit(0)
    #cv2.waitKey(0)
    #cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
