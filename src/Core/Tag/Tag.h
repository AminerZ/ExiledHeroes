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

	private:
		void readType(EndianIStream& input);
		void writeType(EndianOStream& output);

		void readName(EndianIStream& input);
		void writeName(EndianOStream& output);
	
	protected:
		virtual void readPayload(EndianIStream& input);
		virtual void writePayload(EndianOStream& output);
	};
}