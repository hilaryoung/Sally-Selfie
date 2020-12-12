#define trigPin 10
#define echoPin 9
#define led 13 //green
#define led2 12 //yellow
#define led3 11 //red

//2nd sensor
#define trigPin_two 5
#define echoPin_two 4
#define led_two 8 //green
#define led2_two 7 //yellow
#define led3_two 6 //red

//servo control set uo
#include <Servo.h>

int sensorPin = A0;
int servoPin  = 3;

int sensorValue = 0;
int servoGrad = 90;
int tolerance = 40;

Servo myservo;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

//2nd sensor
  pinMode(trigPin_two, OUTPUT);
  pinMode(echoPin_two, INPUT);
  pinMode(led_two, OUTPUT);
  pinMode(led2_two, OUTPUT);
  pinMode(led3_two, OUTPUT);

 //motor
  pinMode( sensorPin, INPUT);
  myservo.attach( servoPin );
  myservo.write( servoGrad );


}

void loop() {

//motor
  sensorValue = analogRead(sensorPin);
  if ( sensorValue < (512-tolerance) )
  {
    if (servoGrad < 180) servoGrad++;
  }

  if ( sensorValue > (512+tolerance) )
  {
    if (servoGrad > 0) servoGrad--;
  }

  myservo.write( servoGrad );

  delay(1);


//ultrasound
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

//1st led
  if (distance <= 10) {
    digitalWrite(led, HIGH);
}
  else {
    digitalWrite(led,LOW);
  }

  //2nd led
  if (distance < 20) {
      digitalWrite(led2, HIGH);
}
  else {
      digitalWrite(led2, LOW);
  }

  //3rd led
  if (distance < 40) {
      digitalWrite(led3, HIGH);
}
  else {
    digitalWrite(led3, LOW);
  }

  //out of range
  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }



  //2nd sensor
  digitalWrite(trigPin_two, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin_two, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin_two, LOW);

  duration = pulseIn(echoPin_two, HIGH);
  distance = (duration/2) / 29.1;

//1st led
  if (distance <= 10) {
    digitalWrite(led_two, HIGH);
}
  else {
    digitalWrite(led_two,LOW);
  }

  //2nd led
  if (distance < 20) {
      digitalWrite(led2_two, HIGH);
}
  else {
      digitalWrite(led2_two, LOW);
  }

  //3rd led
  if (distance < 40) {
      digitalWrite(led3_two, HIGH);
}
  else {
    digitalWrite(led3_two, LOW);
  }

  //out of range
  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(10);
}
