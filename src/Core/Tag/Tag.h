#pragma once
#include <iostream>
#include <string>

#include "Core/Util/Stream/EndianIStream.h"
#include "Core/Util/Stream/EndianOStream.h"
#define TYPE_NAME(x) typeid(x).name()

namespace ExiledHeroes {
	enum TagType : int8_t {
		End		 = 0x0,
		Byte	 = 0x1,
		Short	 = 0x2,
		Int		 = 0x3,
		Long	 = 0x4,
		Float	 = 0x5,
		Double	 = 0x6,
		String	 = 0x7,
		Compound = 0x8
	};

	class Tag {
	private:
		TagType type;
		std::string name;
	public:
		Tag(TagType type, std::string name = "");
		virtual ~Tag();

		void read(EndianIStream input);
		void write(EndianOStream output);

		TagType getType();
		std::string getName();

		template<class T>
		TagType getPrimitiveType();

	private:
		void readType(EndianIStream& input);
		void writeType(EndianOStream& output);

		void readName(EndianIStream& input);
		void writeName(EndianOStream& output);
	
	protected:
		virtual void readPayload(EndianIStream& input);
		virtual void writePayload(EndianOStream& output);
	};
	
	template<class T>
	TagType Tag::getPrimitiveType() {
		const char* type = TYPE_NAME(T);
		if		(type == TYPE_NAME(int8_t))   return TagType::Byte;
		else if (type == TYPE_NAME(int16_t))  return TagType::Short;
		else if (type == TYPE_NAME(int32_t))  return TagType::Int;
		else if (type == TYPE_NAME(int64_t))  return TagType::Long;
		else if (type == TYPE_NAME(float_t))  return TagType::Float;
		else if (type == TYPE_NAME(double_t)) return TagType::Double;
		else {
			throw "No Primitive types found";
			return TagType::End;
		}
	}
}