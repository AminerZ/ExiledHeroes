#include "Tag.h"

using namespace ExiledHeroes;

Tag::Tag(TagType type, std::string name)
	: type(type), name(name) {}

Tag::~Tag() {}

void Tag::read(EndianIStream input) {
	readType(input);
	readName(input);
	readPayload(input);
}

void Tag::write(EndianOStream output) {
	writeType(output);
	writeName(output);
	writePayload(output);
}

TagType Tag::getType() {
	return type;
}

std::string Tag::getName() {
	return name;
}

void Tag::readType(EndianIStream& input) {
	input.read<TagType>(&type);
}

void Tag::writeType(EndianOStream& output) {
	output.write<TagType>(&type);
}

void Tag::readName(EndianIStream& input) {
	int16_t nameSizeBuffer;
	input.read<int16_t>(&nameSizeBuffer);
	
	std::string nameBuffer(nameSizeBuffer, '\0');
	input.read(nameBuffer, nameSizeBuffer);

	name = nameBuffer;
}

void Tag::writeName(EndianOStream& output) {
	int16_t nameSizeBuffer = (int16_t) name.size();
	output.write<int16_t>(&nameSizeBuffer);

	output.write(name, nameSizeBuffer);
}

void Tag::readPayload(EndianIStream& input) {}

void Tag::writePayload(EndianOStream& output) {}