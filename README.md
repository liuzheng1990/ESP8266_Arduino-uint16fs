# A trivial wrapper for reading/writing integers (file, Serial, and more)

## and a playground for Arduino/ESP8266 beginners

Welcome to use "uint16fs", a thin wrapper for reading/writing integers. The built-in read/write methods enable the users
to read and write byte arrays. Since everything is made of bytes, these generic functions, in principle, can handle all
read/write tasks, to files, to Serial ports, and to any other objects which inherites the read and write methods from the 
"Stream" class.

However, when I was writing codes to read/write integers (in the binary form, not printed as a string and use `toInt` to parse),
every time I have to assemble my own integers out of 2 or 4 bytes (depending on whether it's a short integer or a long integer).
It was a good practice to do it once or twice, but soon it became awkard to repeat this task. That's why I wanted to wrote these
two functions in this library. (Yes, this libary really just contains two functions!)

Besides, this libary is a playground for Arduino/ESP8266 beginners (like me). For example, I only realized the read/write 
functions for **unsigned short integers** (integers in the range 0~65535) because I was using it in a small home project. 
I encourage the Arduino/ESP8266 beginners (like me) to fork the repo, and add your own converting functions to other types of
integers. Please share with me your work, and you are warmly welcome to make a pull request to this original repo!

## Installation

The installation of this libray is the same as any other Arduino library. Make sure you have the Arduino IDE on your computer,
and you have familiarized yourself with the IDE by at least running the `blinking` example.

1. Download/clone the codes in the repo, and unzip it.
2. Rename the unzipped directory to `unit16fs`, and put it to `<your home folder>/Arduino/libraries`.
3. Restart the Arduino IDE, and click `Sketch` in the menu bar. Choose `Include Library` andyou'll find `unit16fs` library
in the list. At the same time, click `File` in the menu bar and then `Examples`. You'll also find `uint16fs` there.

## Using the library

The functions were originally written to read/write `files` for the ESP8266/Arduino filesystem (with the `FS.h` library).
Very soon, I generalized it to any Stream objects. This well includes the `Serial` object, making it easier to send and 
receive uint16_t integers via the serial communication.

1. **To read n short integers from serial communication**, make sure you have initialized the `Serial` object (possibly in
the `setup` function). Then you can call the `read_uint16` function when you need data.

```
#include <uint16fs.h>
...
Serial.begin(115200); // initialize the Serial somewhere in your codes.
... // do other things

uint16_t buff [10]; // Let's say you want to read 10 short integers from Serial.
while(Serial.available()<20); // wait until the serial buffer got 10 short integers (20 bytes)
size_t integers_received = read_uint16(&Serial, buff, 10); // returns the actual amount of short integers retrieved. 
...
```

2. **To write n short integers to the serial communication**, make sure of the same initialization as above, and prepare the
data you are going to send into an array, and take notes of the actual size. Then use `write_uint16`.

```
#include <uint16fs.h>
...
uint16_t buff[10] = {9000, 4500, 560, 560, 560, 1680}; // as an example, this is the first several numbers in a raw data
                                                        // sequence of a typical NEC infrared signal.
size_t data_size = 6; // Send 6 integers
size_t data_sent = write_uint16(&Serial, buff, data_size); // return the actual data sent out.
...
```

3. **To read data from a file**, replace the `&Serial` at the first argument of `read_uint16` function by the corresponding
file handler. Let's use the example of the ESP8266/Arduino filesystem.

```
#include <FS.h>
#include <uint16fs.h>
...
SPIFFS.begin(); // make sure to begin the SPIFFS somewhere in your code.
File f = SPIFFS.open(<your filename>, "r");

uint16_t buff[20];
size_t data_len_received = read_uint16(&f, buff, 20); // Let's say we want to read at most 20 short integers from the file.
                                                      // You may get less than 15 if your file contains only 15 integers, for exmaple.
                                                      // the returned value thus tell you the actual number of integers received.
```

4. **To write data to a file**, combine Steps 2 and 3. It's left as an exercise.

## Contributors

Original Author: Thales, Liu Zheng, Nov. 18th, 2018

Contributors: 

Please feel free to give me any feedback or suggestion. Everyone is free to download, use and modify the codes. You are very
welcome to raise a pull request if you have any improvement or extension to the library.

Happy coding!
