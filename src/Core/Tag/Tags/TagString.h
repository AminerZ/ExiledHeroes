#pragma once
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
		void readPayload(EndianIStream& input) override {
			int16_t valueSizeBuffer;
			input.read<int16_t>(&valueSizeBuffer);

			std::string valueBuffer(valueSizeBuffer, '\0');
			input.read(valueBuffer, valueSizeBuffer);
			
			setValue(valueBuffer);
		}

		void writePayload(EndianOStream& output) override {
			int16_t valueSizeBuffer = (int16_t)value.size();
			output.write<int16_t>(&valueSizeBuffer);

			output.write(value, valueSizeBuffer);
		}
	};
}