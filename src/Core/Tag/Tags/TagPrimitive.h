#pragma once
#include <iostream>
#include <string>

#include "Core/Tag/Tag.h"

namespace ExiledHeroes {

	template<class T>
	class TagPrimitive : public Tag {
	private:
		T value;
	public:
		TagPrimitive()
			: Tag(getPrimitiveType<T>()) {}

		TagPrimitive(std::string name)
			: Tag(getPrimitiveType<T>(), name) {}

		T getValue() {
			return value;
		}

		void setValue(T val) {
			value = val;
		}

	private:
		void readPayload(std::istream& input) override {
			input.read((char*)& value, sizeof(T));
		}

		void writePayload(std::ostream& output) override {
			output.write((char*)& value, sizeof(T));
		}
	};

	typedef TagPrimitive<int8_t> TagByte;
	typedef TagPrimitive<int16_t> TagShort;
	typedef TagPrimitive<int32_t> TagInt;
	typedef TagPrimitive<int64_t> TagLong;
	typedef TagPrimitive<float_t> TagFloat;
	typedef TagPrimitive<double_t> TagDouble;
}