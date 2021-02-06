#include <Servo.h>
Servo steer; // servo used for steering 

String val = "";    // to store string read from serial 
int comma;
int semicomma;
int steer_angle=100; // steer angle may vary for cars , for mine it was 40 to 160 degree while 100 degree being the center
int directed_speed=0; // range is -255 to 255

void setup() {
  Serial.begin(57600); // a good baud rate for the application, by default HC-05 has 9600 baud rate, change if you want
  steer.attach(10);
  pinMode(3,OUTPUT);// forward pwm
  pinMode(5,OUTPUT);// reverse pwm
  pinMode(4, INPUT_PULLUP); // for reading HC-05 bluetooth module's connection state
}

void drive(int spd){  //function for driving rear motor forward or backward using pin 3 pwm for reverse drive and pin 5 pwm for forward drive
  if(spd<0){
    analogWrite(3,abs(spd)); // negative speed values for reverse drive
    analogWrite(5,0);
  }else{
    analogWrite(3,0);
    analogWrite(5,spd);
  }
}

void loop() { 
  while (Serial.available() > 0) {  // WARNING: Serial data flow from pc must be continiuous, no delay is allowed , otherwise the control will be a disaster!
    int inChar = Serial.read();
    val += (char)inChar;
   
    if (inChar == '\n') {
    comma=val.indexOf(",");
    semicomma=val.indexOf(";");
    steer_angle=(val.substring(0,comma)).toInt();//converts string to int for steering value
    directed_speed=(val.substring(comma+1,semicomma)).toInt();//converts string to int for speed value
    steer.write(steer_angle);
    drive(directed_speed);
    val = "";
    }
  }
  if(digitalRead(4)==LOW){ // if bluetooth link is disrupted then stop the car immidiately , HC-05 bt module is used here which has a state pin that is connected to arduino pin 4 for digital read
     steer_angle=100;
     directed_speed=0;
  }
  steer.write(steer_angle);
  drive(directed_speed);    
}


