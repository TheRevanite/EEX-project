#define RED 1
#define YELLOW 2
#define GREEN 3

//Should be in a folder called sketch, according to Arduino IDE

void setup() {
pinMode(RED, OUTPUT);
pinMode(YELLOW, OUTPUT);
pinMode(GREEN, OUTPUT);
digitalWrite(RED, LOW);
digitalWrite(YELLOW, LOW);
digitalWrite(GREEN, LOW);
Serial.begin(9600);
Serial.setTimeout(3000);
Serial.println("Waiting for match percentage... \n");
}

void loop() {
while (Serial.available()>0) {
int match = Serial.parseInt();
Serial.println("Received match percentage: ");
Serial.println(match);
digitalWrite(RED, HIGH);
delay(2000);
digitalWrite(RED, LOW);
digitalWrite(YELLOW, HIGH);
delay(1000);
digitalWrite(YELLOW, LOW);
digitalWrite(GREEN, HIGH);
if (match < 20) delay(6000);
else if (match >= 20 && match < 50) delay(4000);
else if (match >= 50 && match < 75) delay(3000);
else if (match >= 75 && match <= 100) delay(2000);
digitalWrite(GREEN,LOW);
}
}
