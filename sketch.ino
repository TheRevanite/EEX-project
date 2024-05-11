#define RED1 1
#define YELLOW1 3
#define GREEN1 2
#define RED2 4
#define YELLOW2 5
#define GREEN2 6
#define RED3 16
#define YELLOW3 17
#define GREEN3 18
#define RED4 22
#define YELLOW4 26
#define GREEN4 27

void setup()
{
  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(RED3, OUTPUT);
  pinMode(YELLOW3, OUTPUT);
  pinMode(GREEN3, OUTPUT);
  pinMode(RED4, OUTPUT);
  pinMode(YELLOW4, OUTPUT);
  pinMode(GREEN4, OUTPUT);
  digitalWrite(RED1, HIGH);
  digitalWrite(RED2, HIGH);
  digitalWrite(RED3, HIGH);
  digitalWrite(RED4, HIGH);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(YELLOW3, LOW);
  digitalWrite(YELLOW4, LOW);
  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(GREEN3, LOW);
  digitalWrite(GREEN4, LOW);
  Serial.begin(9600);
  Serial.setTimeout(3000);
}

void lights1() {
  while (Serial.available()>0) {
    int match1 = Serial.parseInt();
    Serial.println("Received match1 percentage from first camera: ");
    Serial.println(match1);
    digitalWrite(RED1, HIGH);
    delay(2000);
    digitalWrite(RED1, LOW);
    digitalWrite(YELLOW1, HIGH);
    delay(1000);
    digitalWrite(YELLOW1, LOW);
    digitalWrite(GREEN1, HIGH);
    if (match1 < 20) delay(6000);
    else if (match1 >= 20 && match1 < 50) delay(4000);
    else if (match1 >= 50 && match1 < 75) delay(3000);
    else if (match1 >= 75 && match1 <= 100) delay(2000);
    digitalWrite(GREEN1, LOW);
    delay(1000);
    digitalWrite(YELLOW1, HIGH);
    Serial.println("TRUE");
    delay(2000);
    digitalWrite(YELLOW1, LOW);
    digitalWrite(RED1, HIGH);
  }
}

void lights2() {
  while (Serial.available()>0) {
    int match2 = Serial.parseInt();
    Serial.println("Received match1 percentage from second camera: ");
    Serial.println(match2);
    digitalWrite(RED2, HIGH);
    delay(2000);
    digitalWrite(RED2, LOW);
    digitalWrite(YELLOW2, HIGH);
    delay(1000);
    digitalWrite(YELLOW2, LOW);
    digitalWrite(GREEN2, HIGH);
    if (match2 < 20) delay(6000);
    else if (match2 >= 20 && match2 < 50) delay(4000);
    else if (match2 >= 50 && match2 < 75) delay(3000);
    else if (match2 >= 75 && match2 <= 100) delay(2000);
    digitalWrite(GREEN2, LOW);
    delay(1000);
    digitalWrite(YELLOW2, HIGH);
    Serial.println("TRUE");
    delay(2000);
    digitalWrite(YELLOW2, LOW);
    digitalWrite(RED2, HIGH);
  }
}

void lights3() {
  while (Serial.available()>0) {
    int match3 = Serial.parseInt();
    Serial.println("Received match1 percentage from third camera: ");
    Serial.println(match3);
    digitalWrite(RED3, HIGH);
    delay(2000);
    digitalWrite(RED3, LOW);
    digitalWrite(YELLOW3, HIGH);
    delay(1000);
    digitalWrite(YELLOW3, LOW);
    digitalWrite(GREEN3, HIGH);
    if (match3 < 20) delay(6000);
    else if (match3 >= 20 && match3 < 50) delay(4000);
    else if (match3 >= 50 && match3 < 75) delay(3000);
    else if (match3 >= 75 && match3 <= 100) delay(2000);
    digitalWrite(GREEN3, LOW);
    delay(1000);
    digitalWrite(YELLOW3, HIGH);
    Serial.println("TRUE");
    delay(2000);
    digitalWrite(YELLOW3, LOW);
    digitalWrite(RED3, HIGH);
  }
}

void lights4() {
  while (Serial.available()>0) {
    int match4 = Serial.parseInt();
    Serial.println("Received match1 percentage from fourth camera: ");
    Serial.println(match4);
    digitalWrite(RED4, HIGH);
    delay(2000);
    digitalWrite(RED4, LOW);
    digitalWrite(YELLOW4, HIGH);
    delay(1000);
    digitalWrite(YELLOW4, LOW);
    digitalWrite(GREEN4, HIGH);
    if (match4 < 20) delay(6000);
    else if (match4 >= 20 && match4 < 50) delay(4000);
    else if (match4 >= 50 && match4 < 75) delay(3000);
    else if (match4 >= 75 && match4 <= 100) delay(2000);
    digitalWrite(GREEN4, LOW);
    delay(1000);
    digitalWrite(YELLOW4, HIGH);
    Serial.println("TRUE");
    delay(2000);
    digitalWrite(YELLOW4, LOW);
    digitalWrite(RED4, HIGH);
  }
}

void loop()
{
  lights1();
  lights2();
  lights3();
  lights4();
}
