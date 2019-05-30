#pragma once
#include <iostream>
#include <string>

#include "Core/Tag/Tag.h"

namespace ExiledHeroes {

	class TagString : public Tag {
	private:
		std::string value;
	public:
		TagString()
			: Tag(TagType::String) {}

		TagString(std::string name)
			: Tag(TagType::String, name) {}

		std::string getValue() {
			return value;
		}

		void setValue(std::string val) {
			value = val;
		}

	private:
		void readPayload(std::istream& input) override {
			int16_t valueSizeBuffer;
			input.read((char*)& valueSizeBuffer, sizeof(int16_t));

			std::string valueBuffer(valueSizeBuffer, '\0');
			input.read(&valueBuffer[0], valueSizeBuffer * sizeof(char));
			
			setValue(valueBuffer);
		}

		void writePayload(std::ostream& output) override {
			int16_t valueSizeBuffer = (int16_t)value.size();
			output.write((char*)& valueSizeBuffer, sizeof(int16_t));

			output.write(&value[0], valueSizeBuffer * sizeof(char));
		}
	};
}