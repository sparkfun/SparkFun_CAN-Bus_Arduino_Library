/*
 created 24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe
 
 modified 18 Sep 2014
 by Bobby Chan @ SparkFun Electronics Inc.
 
 Modified by Toni Klopfenstein @ SparkFun Electronics
	September 2015
	https://github.com/sparkfun/CAN-Bus_Shield
 
 SD Card Datalogger
 
 This example is based off an example code from Arduino's site
 http://arduino.cc/en/Tutorial/Datalogger and it shows how to 
 log data from three analog sensors with a timestamp based on when
 the Arduino began running the current program to an SD card using
 the SD library https://github.com/greiman/SdFat by William 
 Greiman. This example code also includes an output to the 
 Serial Monitor for debugging.
 	
 The circuit:
 * analog sensors on analog pins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (Ethernet Shield)
 ** CS - pin 9 (CAN-Bus Shield)
 
 This example code is in the public domain.
 */

#include <SPI.h>
#include <SD.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int hwChipSelect = 10;

// Chip Select pin is tied to pin 9 on the SparkFun CAN-Bus Shield
const int chipSelect = 9;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(hwChipSelect, OUTPUT);
  pinMode(chipSelect, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect))
  {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
  // make a string for assembling the data to log:
  String dataString = "";

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  // This opens the file and appends to the end of file;
  // if the file does not exist, this will create a new file.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile)
  {
    unsigned int timeStamp = millis();

    // add a timestamp to the log string
    dataString += timeStamp;
    dataString += " ms";

    // read three sensors on A0, A1, and A2 while appending to the string:
    for (int analogPin = 0; analogPin < 3; analogPin++)
    {
      int sensorVal = analogRead(analogPin);

      // add analog data point to the log string
      dataString += ", ";
      dataString += "Analog Pin A";
      dataString += analogPin;
      dataString += " = ";
      dataString += sensorVal;
    }

    dataFile.println(dataString); //create a new row to read data more clearly
    dataFile.close();             //close file
    Serial.println(dataString);   //print to the serial port too:
  }
  // if the file isn't open, pop up an error:
  else
  {
    Serial.println("error opening datalog.txt");
  }
}
