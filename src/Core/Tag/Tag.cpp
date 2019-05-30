#include "Tag.h"

using namespace ExiledHeroes;

Tag::Tag(TagType type, std::string name)
	: type(type), name(name) {}

Tag::~Tag() {}

void Tag::read(std::istream& input) {
	readType(input);
	readName(input);
	readPayload(input);
}

void Tag::write(std::ostream& output) {
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

void Tag::readType(std::istream& input) {
	input.read((char*)& type, sizeof(int8_t));
}

void Tag::writeType(std::ostream& output) {
	output.write((char*)& type, sizeof(int8_t));
}

void Tag::readName(std::istream& input) {
	int16_t nameSizeBuffer;
	input.read((char*)& nameSizeBuffer, sizeof(int16_t));
	
	std::string nameBuffer(nameSizeBuffer, '\0');
	input.read(&nameBuffer[0], nameSizeBuffer * sizeof(char));

	name = nameBuffer;
}

void Tag::writeName(std::ostream& output) {
	int16_t nameSizeBuffer = (int16_t) name.size();
	output.write((char*)& nameSizeBuffer, sizeof(int16_t));

	output.write(&name[0], nameSizeBuffer * sizeof(char));
}

void Tag::readPayload(std::istream& input) {}

void Tag::writePayload(std::ostream& output) {}