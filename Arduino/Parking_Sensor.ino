
#define echoPin 10
#define trigPin 9
#define greenPin 2
#define amberPin 3
#define redPin 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(amberPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin, LOW); //turn off trig pin
  delayMicroseconds(2); // Wait
  digitalWrite(trigPin, HIGH); // Turn on Trig Pin
  delayMicroseconds(10); //Wait
  digitalWrite(trigPin, LOW); //Turn off trig pin
  duration = pulseIn(echoPin, HIGH); //Waits for echo pin to be high
  distance = (duration/2) / 29.1; //Calculation to find distance travelled by wave using time

  //LEDs on/off
  if (distance <= 10) { //distance less than or equal to 10cm
    digitalWrite(redPin,HIGH);
    digitalWrite(amberPin,LOW);
    digitalWrite(greenPin, LOW);
  }

  if (distance >= 20) { // >= 20cm
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(amberPin, LOW);
  }

  if (distance >10 && distance <20) {
    digitalWrite(amberPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
  }

  if (distance >=200 && distance <= 0) {
    Serial.println("Out of range"); 
  }

  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500); //wait 500ms
}
