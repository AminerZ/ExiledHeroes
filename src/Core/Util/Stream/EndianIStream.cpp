#include "EndianIStream.h"
#include "Core/Util/Endianness.h"

using namespace ExiledHeroes;

EndianIStream::EndianIStream(std::istream& stream)
	: stream(stream) {}

void EndianIStream::read(std::string& str, std::streamsize count) {
	read(&str[0], count, false);
}

void EndianIStream::read(char* str, std::streamsize count, bool check) {
	stream.read(str, count);
	if (!check) return;
	if (!Endianness::isLittleEndian())
		Endianness::swapEndianness(str, count);
}

int EndianIStream::peek() {
	return stream.peek();
}

void EndianIStream::ignore(const std::streamsize count) {
	stream.ignore(count);
}