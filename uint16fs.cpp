#include "uint16fs.h"
#include <FS.h>
#include <Stream.h>

// Functions reading and writing unsigned short integers
// from/to ESP8266's filesystem.
//
// Author: Thales Liu
// Nov. 18th, 2018
//
// You can use and modify this library for any legal purpose.
// Just make sure to give credits to all authors and contributors.
//
// A thin wrapper functions supplementing FS::File class,
// reading and writing unsigned short integers from and to
// a uint16_t buffer.
//
//
// size_t read_uint16(File *f, uint16_t *buff, size_t len);
//
// size_t write_uint16(File *f, uint16_t *buff, size_t len);



size_t read_uint16(Stream *f, uint16_t *buff, size_t len)
{
	// what if we got odd number of bytes in the end of a file?
	if (len == 0)
		return 0;

	int read_bytes = f->readBytes((uint8_t *)buff, 2*len);
	if (read_bytes < 0 || read_bytes & 1) // odd number of bytes. Let's return -1 for now.
		return 0;
	return (size_t)(read_bytes/2);

}

size_t write_uint16(Stream *f, const uint16_t *buff, size_t len)
{
	if (len == 0)
		return 0;

	size_t write_bytes = f->write((uint8_t *)buff, 2*len);
	if (write_bytes & 1)
		return 0;
	return write_bytes/2;


}
