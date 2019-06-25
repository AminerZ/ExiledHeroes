#include "EndianOStream.h"
#include "Core/Util/Endianness.h"

using namespace ExiledHeroes;

EndianOStream::EndianOStream(std::ostream& stream)
	: stream(stream) {}

void EndianOStream::write(std::string& str, std::streamsize count) {
	write(&str[0], count, false);
}

void EndianOStream::put(char ch) {
	write(&ch, sizeof(char), false);
}

void EndianOStream::write(char* str, std::streamsize count, bool check) {
	if (!check) {
		stream.write(str, count);
		return;
	}

	if (!Endianness::isLittleEndian())
		Endianness::swapEndianness(str, count);
	stream.write(str, count);
}

/*int EndianOStream::peek() {
	return stream.peek();
}*/

/*void EndianOStream::ignore(const std::streamsize count) {
	stream.ignore(count);
}*/