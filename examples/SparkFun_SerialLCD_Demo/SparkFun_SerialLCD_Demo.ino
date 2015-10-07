/****************************************************************************
 SparkFun Serial LCD example 1
Clear the display and say "Hello World!"

This sketch is for Arduino versions 1.0 and later
If you're using an Arduino version older than 1.0, use
the other example code available on the tutorial page.

Modified:
	
Toni Klopfenstein @ SparkFun Electronics
September 2015
https://github.com/sparkfun/CAN-Bus_Shield

This code is beerware; if you see me (or any other SparkFun employee) at the local, 
and you've found our code helpful, please buy us a round!

For the official license, please check out the license file included with the library.

Distributed as-is; no warranty is given.
*************************************************************************/
#include <SoftwareSerial.h> //LCD screen connects via Software Serial to 
							//prevent display corruption

// Attach the serial display's RX line to digital pin 6 for connection 
//on the CAN-Bus shield

SoftwareSerial mySerial(3,6); // pin 6 = TX, pin 3 = RX (unused)


void setup()
{
  mySerial.begin(9600); // set up serial port for 9600 baud
  delay(500); // wait for display to boot up
}

void loop()
{
  mySerial.write(254); // move cursor to beginning of first line
  mySerial.write(128);

  mySerial.write("                "); // clear display
  mySerial.write("                ");

  mySerial.write(254); // move cursor to beginning of first line
  mySerial.write(128);
 
  mySerial.write("Hello, world!");

  while(1); // wait forever
}

