#include <math.h>
int frequency;
float X;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  frequency = 10;
}

void loop() {
  // put your main code here, to run repeatedly:
  X = 200*cos(2*3.14*frequency*millis());
  if (X>=0){
    analogWrite(9,X);
    digitalWrite(10,0);
  }
  if (X<0){
    digitalWrite(9,0);
    analogWrite(10,abs(X));
  }
  Serial.println(X);
}
