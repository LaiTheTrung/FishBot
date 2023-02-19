#include <Servo.h>      // Thư viện điều khiển servo
#include <math.h>
// Khai báo đối tượng myservo dùng để điều khiển servo
Servo myservo;          
float servoPin = 9;       // Khai báo chân điều khiển servo
int frequency;          // max = 5 Hz for A = 100 degree
long goc;
char Input[5];
int idx=0;
void setup ()
{
    // Cài đặt chức năng điều khiển servo cho chân servoPin
    myservo.attach(servoPin); 
    myservo.write(0);
    Serial.begin(9600);
    frequency = 5;
    
}
 
void loop ()
{
    while(Serial.available())
    {
      char c = Serial.read();
      if(c != '\n'){
        if (idx<4){
          Input[idx] = c;
          idx++;
        }
      }
      else
      {
        frequency = atof(Input);
        memset(Input,0,5);
        idx = 0;
        Serial.println(frequency);
      }
    }
    goc = 50*cos(2*3.14*frequency*millis())+100;
    myservo.write(goc);
    Serial.println(goc);
   
}
