/****************************************************************************** 
Toni Klopfenstein @ SparkFun Electronics
September 2015
https://github.com/sparkfun/CAN-Bus_Shield

This example sketch works with the CAN-Bus shield from SparkFun Electronics.

It reads the joystick for user inputs. 

Based off of joystick_demo.pde by Sukkin Pang.
Original file available at http://skpang.co.uk/catalog/arduino-canbus-shield-with-usd-card-holder-p-706.html

This code is beerware; if you see me (or any other SparkFun employee) at the local, 
and you've found our code helpful, please buy us a round!

For the official license, please check out the license file included with the library.

Distributed as-is; no warranty is given.
********************************************************************************/


/* Define Joystick connection pins */
#define UP     A1
#define DOWN   A3
#define LEFT   A2
#define RIGHT  A5
#define CLICK  A4


void setup() {
  //Initialize analog pins as inputs
  pinMode(UP,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(LEFT,INPUT);
  pinMode(RIGHT,INPUT);
  pinMode(CLICK,INPUT);
  
  //Pull analog pins high to enable reading of joystick movements
  digitalWrite(UP, HIGH);
  digitalWrite(DOWN, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RIGHT, HIGH);
  digitalWrite(CLICK, HIGH);
 
 //Initialize serial terminal connection
  Serial.begin(9600);
  Serial.println("Joystick Demo");

}



void loop() {
  
  //Scan analog pins. If pin reads low, print the corresponding joystick movement.
   if (digitalRead(UP) == 0) {
     Serial.println("Up");}
      
   if (digitalRead(DOWN) == 0) {
      Serial.println("Down");}
      
   if (digitalRead(LEFT) == 0) {
       Serial.println("Left");}
   
   if (digitalRead(RIGHT) == 0) {
       Serial.println("Right");}

   if (digitalRead(CLICK) == 0) {
       Serial.println("Click");}      
       delay(250);

}

