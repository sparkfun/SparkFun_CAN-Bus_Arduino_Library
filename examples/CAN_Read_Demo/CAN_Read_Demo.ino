/****************************************************************************
CAN Read Demo for the SparkFun CAN Bus Shield. 

Written by Stephen McCoy. 
Original tutorial available here: http://www.instructables.com/id/CAN-Bus-Sniffing-and-Broadcasting-with-Arduino
Used with permission 2016. License CC By SA. 

Distributed as-is; no warranty is given.
*************************************************************************/

#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

tCAN message;

void setup() {
  Serial.begin(9600); // For debug use
  Serial.println("CAN Read - Testing receival of CAN Bus message");

  delay(1000);

  if (Canbus.init(CANSPEED_500)) {
    Serial.println("CAN Init ok");
  } else {
    Serial.println("Can't init CAN");
  }

  delay(1000);
}

void loop() {

  if (!mcp2515_check_message()) {
    return;
  }

  memset(&message, 0, sizeof(message))

  if (!mcp2515_get_message(&message)) {
    return;
  }

  /* uncomment when you want to filter
  if(message.id == 0x620 and message.data[2] != 0xFF) { 
    return;
  }
  */

  Serial.print("ID: ");
  Serial.print(message.id,HEX);
  Serial.print(", ");
  Serial.print("Data: ");
  Serial.print(message.header.length,DEC);

  for(int i = 0; i < message.header.length; i++) {
    Serial.print(message.data[i], HEX);
    Serial.print(" ");
  }

  Serial.println();
}
