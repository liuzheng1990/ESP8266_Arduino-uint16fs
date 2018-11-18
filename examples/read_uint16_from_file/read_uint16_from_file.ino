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
// This example read the unsigned short integers to `data`
// from a file called `int_test.txt`.

// Make sure you have run the `write_uint16_from_file` example
// before running this example.

void setup()
{
  uint16_t data[8] = {0};
  uint8_t number = 0;
  SPIFFS.begin();
  Serial.begin(115200);
  File f = SPIFFS.open("/int_test.txt", "r");
  if (!f)
    Serial.println("\nError in opening file!");
  number = read_uint16(&f, data, 6);
  f.close();
  Serial.println("\nFinished writing data!");
  for (int i=0; i<number; i++)
  {
    Serial.print(data[i]);
    Serial.print("\t");
  }
  Serial.println("");
}


void loop()
{
  
}
