#include <AFMotor.h>  
#include <Servo.h>

Servo myservo;
Servo myservo1;
int dtime=700;
int dtime1=200;
int pos=10;
#define FA  A2
#define BA A0
#define LE A3
#define RI A1
#define relais  A5

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
int speedCar = 180;
int def=70;
int def1=250;
int maxe=85;
int mine1=0;
int maxe1=90;
int mine=0;
int speedSet = 0;
void setup() {
   pinMode(relais, OUTPUT); 
   digitalWrite(relais,HIGH);
myservo.attach(9);  
  myservo1.attach(10); 
  for (pos = mine; pos <= maxe; pos += 1) { 
    myservo1.write(pos);  
      myservo.write(pos);
      delay(10);                                   
  } 
  for (pos = maxe; pos >= mine; pos -= 1) { 
   myservo1.write(pos);  
      myservo.write(pos);
      delay(10);    
  }
    for (pos = mine; pos <= maxe; pos += 1) { 
    myservo1.write(pos);  
      myservo.write(pos);
      delay(10);                                   
  } 
  for (pos = maxe; pos >= mine; pos -= 1) { 
   myservo1.write(pos);  
      myservo.write(pos);
      delay(10);    
  }
  delay(4000);
   pinMode(FA, INPUT);
    pinMode(BA, INPUT);
     pinMode(LE, INPUT);
    pinMode(RI, INPUT);
     pinMode(relais, OUTPUT);
   
}

void loop() {
 int farw = analogRead(FA);
int back = analogRead(BA);
 int lef = analogRead(LE);
int rig = analogRead(RI);
int fb= farw-back;
fb=abs(fb);
int lr=lef-rig;
lr=abs(lr);
 if  ( fb <=def1){
if  (lr <=def){
    delay(10);   
stp();
delay(dtime);
  }
else if (lef>rig){
  if(farw<400){
    delay(10); 
     forward(); 
    }
     else  {
      delay(10); 
     right();
      
      }

  }
  else if (rig>lef){
    if(farw<400){
    delay(10); 
     forward(); 
    }else{
      delay(10);   
    left(); 
      }
     
}
   else  {
    stp();
    delay(dtime);
  }
}
else if (farw-back>275){
    delay(10);   
   tourn();
  }
else if ((back+200)>farw){
  if((farw<=900)&&(farw>=100)) {
    delay(10);   
   forward();
   }
    else if(farw<100){
          delay(10);  
    stp();
     delay(dtime1);
     servo();
      delay(dtime);
    }     
    
      else{
      delay(10);   
      stp();
    } 
  }
  else{
      delay(10);   
      stp();
    }

  }
  void forward()
{
     motor1.run(BACKWARD);
  motor4.run(BACKWARD);
    motor1.setSpeed(speedCar-25);
    motor4.setSpeed(speedCar-25);
    delay(900);
    
    }

void tourn()
{

      motor4.run(BACKWARD);
  motor1.run(FORWARD);
  motor1.setSpeed(speedCar-25);
  motor4.setSpeed(speedCar-25);
    delay(800);
}



void right()
{
  motor4.run(BACKWARD);
  motor1.run(RELEASE);
  motor4.setSpeed(speedCar);
}
void left()
{
  motor1.run(BACKWARD);
  motor4.run(RELEASE);
   motor1.setSpeed(speedCar);
}
void stp()
{
  motor4.run(RELEASE);
  motor1.run(RELEASE);
}
void servo(){
 digitalWrite(relais,LOW);
    for (pos = mine1; pos <= maxe1; pos += 1) { 
     // myservo1.write(pos);
      myservo.write(pos);
      delay(4);                                   
  } 
  for (pos = maxe1; pos >= mine1; pos -= 1) { 
    myservo1.write(5);   
      myservo.write(pos);
      delay(4);    
  }
    for (pos = mine1; pos <= maxe1; pos += 1) { 
      myservo1.write(15);
      myservo.write(pos);
      delay(4);                                   
  } 
  for (pos = maxe1; pos >= mine1; pos -= 1) { 
    myservo1.write(25);   
      myservo.write(pos);
      delay(4);    
  }
   for (pos = mine1; pos <= maxe1; pos += 1) { 
      myservo1.write(35);
      myservo.write(pos);
      delay(4);                                   
  } 
  for (pos = maxe1; pos >= mine1; pos -= 1) { 
    myservo1.write(30);   
      myservo.write(pos);
      delay(4);    
  }
   for (pos = mine1; pos <= maxe1; pos += 1) { 
      myservo1.write(22);
      myservo.write(pos);
      delay(4);                                   
  } 
  for (pos = maxe1; pos >= mine1; pos -= 1) { 
    myservo1.write(12);   
      myservo.write(pos);
      delay(4);    
  }
   for (pos = mine1; pos <= maxe1; pos += 1) { 
      myservo1.write(8);
      myservo.write(pos);
      delay(4);                                   
  } 
  for (pos = maxe1; pos >= mine1; pos -= 1) { 
    myservo1.write(0);   
      myservo.write(pos);
      delay(4);    
  }
     
 digitalWrite(relais,HIGH);
  }
