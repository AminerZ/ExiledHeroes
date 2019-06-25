#pragma once
#include <string>

#include "Core/Tag/Tag.h"
#include "Core/Tag/TagUtil.h"

namespace ExiledHeroes {

	template<class T>
	class TagPrimitive : public Tag {
	private:
		T value;
	public:
		TagPrimitive()
			: Tag(TagUtil::getPrimitiveType<T>()) {}

		TagPrimitive(std::string name)
			: Tag(TagUtil::getPrimitiveType<T>(), name) {}

		T getValue() {
			return value;
		}

		void setValue(T val) {
			value = val;
		}

	private:
		void readPayload(EndianIStream& input) override {
			input.read<T>(&value);
		}

		void writePayload(EndianOStream& output) override {
			output.write<T>(&value);
		}
	};

	typedef TagPrimitive<int8_t> TagByte;
	typedef TagPrimitive<int16_t> TagShort;
	typedef TagPrimitive<int32_t> TagInt;
	typedef TagPrimitive<int64_t> TagLong;
	typedef TagPrimitive<float_t> TagFloat;
	typedef TagPrimitive<double_t> TagDouble;
}