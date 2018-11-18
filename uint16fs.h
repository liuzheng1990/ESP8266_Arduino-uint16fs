#ifndef UNIT16FS_H
#define UNIT16FS_H

#include <FS.h>
#include <Arduino.h>

// Functions reading and writing unsigned short integers
// from/to ESP8266's filesystem.
//
// Author: Thales Liu
// Nov. 18th, 2018
//
// You can use and modify this library for any legal purpose.
// Just make sure to give credits to all authors and contributors.
//
// A thin wrapper functions supplementing FS::File class of 
// ESP8266/Arduino, reading and writing unsigned short integers
// from and to a uint16_t buffer.
//
//
// size_t read_uint16(File *f, uint16_t *buff, size_t len);
//
// size_t write_uint16(File *f, uint16_t *buff, size_t len);



extern size_t read_uint16(Stream *f, uint16_t *buff, size_t len);
extern size_t write_uint16(Stream *f, const uint16_t *buff, size_t len);

#endif
