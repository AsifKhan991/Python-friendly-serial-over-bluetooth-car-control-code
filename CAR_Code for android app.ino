// this version is for the android app called Bluetooth Rc controller
#include <Servo.h>
Servo steer; // servo used for steering 
char t;

int steer_angle=100; // steer angle may vary for cars , for mine it was 40 to 160 degree while 100 degree being the center
int directed_speed=100; // range is -255 to 255

void setup() {
  Serial.begin(9600); // a good baud rate for the application, by default HC-05 has 9600 baud rate, change if you want
  steer.attach(10);
  pinMode(3,OUTPUT);// forward pwm
  pinMode(5,OUTPUT);// reverse pwm
  pinMode(4,INPUT_PULLUP); // for reading HC-05 bluetooth module's connection state
}

void drive(int spd){  //function for driving rear motor forward or backward using pin 3 pwm for reverse drive and pin 5 pwm for forward drive
  if(spd<0){
    analogWrite(5,abs(spd)); // negative speed values for reverse drive
    analogWrite(3,0);
  }else{
    analogWrite(5,0);
    analogWrite(3,spd);
  }
}

void loop() { 
  
  if(digitalRead(4)==HIGH){ // if bluetooth link is disrupted then stop the car immidiately , HC-05 bt module is used here which has a state pin that is connected to arduino pin 4 for digital read
     if(Serial.available()){
        t = Serial.read();
      }
      if(t=='F'){
        drive(directed_speed);
        steer.write(100);
      }else if(t=='B'){
        drive(-directed_speed);
        steer.write(100);
      }else if(t=='L'){
        steer.write(40);
      }else if(t=='R'){
        steer.write(160);
      }else if(t=='I'){
        drive(directed_speed);
        steer.write(160);
      }else if(t=='G'){
        drive(directed_speed);
        steer.write(40);
      }else if(t=='J'){
        drive(-directed_speed);
        steer.write(160);
      }else if(t=='H'){
        drive(-directed_speed);
        steer.write(40);
      }else if(t=='3'){
        directed_speed=75;
      }else if(t=='4'){
        directed_speed=100;
      }else if(t=='5'){
        directed_speed=125;
      }else if(t=='6'){
        directed_speed=150;
      }else if(t=='7'){
        directed_speed=175;
      }else if(t=='8'){
        directed_speed=200;
      }else if(t=='9'){
        directed_speed=225;
      }else if(t=='q'){
        directed_speed=255;
      }else if(t=='S'){
        steer.write(100);
        drive(0);
      }
  }else{
    steer.write(100);
    drive(0);
    delay(10);
  }
}
