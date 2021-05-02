#include <Adafruit_NeoPixel.h>
#define PIN 11 // the pin your strip is connected to 
#define COUNT 8 // how many led's are on that strip  

Adafruit_NeoPixel strip = Adafruit_NeoPixel(COUNT, PIN, NEO_GRB + NEO_KHZ800); //defines the strips properties
int R;
int G;
int B;

#define trigPin1 7
#define echoPin1 4
#define trigPin2 6
#define echoPin2 3
#define trigPin3 5
#define echoPin3 2

#define greenPin 12
#define amberPin 9
#define redPin 10

void setColor(int Pixel, int R2, int G2, int B2) {
  uint32_t color = strip.Color(R2, G2, B2); // make a color
  strip.setPixelColor(Pixel, color); //set a single pixel color
  strip.show(); //update the colors
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(amberPin, OUTPUT);

  strip.begin(); // start the strip
  strip.show(); // set the strip to black (because we havent told it to do anything yet)
  Serial.begin(9600);
  Serial.println("ready to change color");
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration1, distance1, duration2, distance2, duration3, distance3;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //define sensor read ins
  //sensor1
  digitalWrite(trigPin1, LOW); //turn off trig pin
  delayMicroseconds(2); // Wait
  digitalWrite(trigPin1, HIGH); // Turn on Trig Pin
  delayMicroseconds(10); //Wait
  digitalWrite(trigPin1, LOW); //Turn off trig pin
  duration1 = pulseIn(echoPin1, HIGH); //Waits for echo pin to be high
  distance1 = (duration1 / 2) / 29.1; //Calculation to find distance travelled by wave using time

  //sensor2
  digitalWrite(trigPin2, LOW); //turn off trig pin
  delayMicroseconds(2); // Wait
  digitalWrite(trigPin2, HIGH); // Turn on Trig Pin
  delayMicroseconds(10); //Wait
  digitalWrite(trigPin2, LOW); //Turn off trig pin
  duration2 = pulseIn(echoPin2, HIGH); //Waits for echo pin to be high
  distance2 = (duration2 / 2) / 29.1; //Calculation to find distance travelled by wave using time

  //sensor3
  digitalWrite(trigPin3, LOW); //turn off trig pin
  delayMicroseconds(2); // Wait
  digitalWrite(trigPin3, HIGH); // Turn on Trig Pin
  delayMicroseconds(10); //Wait
  digitalWrite(trigPin3, LOW); //Turn off trig pin
  duration3 = pulseIn(echoPin3, HIGH); //Waits for echo pin to be high
  distance3 = (duration3 / 2) / 29.1; //Calculation to find distance travelled by wave using time

  //////////////////////////////////////////////////////////////////////////////////////////////////////////
  //LEDs for the sensors
  //LEDs on/off for sensor 1
  if (distance1 <= 60 || distance2 <= 60 || distance3 <= 60) { //distance less than or equal to 10cm
    for (int i = 0; i < 8; i++) setColor(i, 255, 0, 0);
    Serial.print("distance1: ");
    Serial.print(distance1);
    Serial.println("cm");
    Serial.print("distance2: ");
    Serial.print(distance2);
    Serial.println("cm");
    Serial.print("distance3: ");
    Serial.print(distance3);
    Serial.println("cm");
    Serial.println();
    
  }
  else {
    for (int i = 0; i < 8; i++) setColor(i, 0, 0, 0);
  }

  delay(500); //wait 500ms
}
