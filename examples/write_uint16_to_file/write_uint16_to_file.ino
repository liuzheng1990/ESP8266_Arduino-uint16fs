#include <uint16fs.h>

// Functions reading and writing unsigned short integers
// from/to ESP8266's filesystem.
//
// Author: Thales Liu
// Nov. 18th, 2018
//
// You can use and modify this library for any legal purpose.
// Just make sure to give credits to all authors and contributors.
//
//
// This example writes the unsigned short integers in `data`
// to a file called `int_test.txt`.

// After finishing running this, you can try the other example
// to read them back.

void setup()
{
  uint16_t data[8] = {9000, 4500, 1230, 440, 660, 0, 1000, 4323};
  uint8_t number = 0;
  SPIFFS.begin();
  Serial.begin(115200);
  File f = SPIFFS.open("/int_test.txt", "w");
  if (!f)
    Serial.println("\nError in opening file!");
  number = write_uint16(&f, data, 8);
  f.close();
  Serial.println("\nFinished writing data!");
}


void loop()
{
  
}
