#include <Servo.h>      // Thư viện điều khiển servo

// Khai báo đối tượng myservo dùng để điều khiển servo
Servo myservo;          
int servoPin = 9;       // Khai báo chân điều khiển servo
char Input[20];
int idx=0;
int goc;
unsigned long time;
void setup ()
{
    // Cài đặt chức năng điều khiển servo cho chân servoPin
    myservo.attach(servoPin); 
    myservo.write(0);
    Serial.begin(250000);
}
 
void loop ()
{
    while(Serial.available())
    {
      char c = Serial.read();
      if(c != '\n'){
        if (idx<19){
          Input[idx] = c;
          idx++;
        }
      }
      else
      {
        goc = atoi(Input);
        memset(Input,0,20);
        idx = 0;
        Serial.println(goc);
      }
    }
    time = millis();
    myservo.write(goc);
    if((millis()-time)>=5){
    Serial.println(millis()-time);}
}
