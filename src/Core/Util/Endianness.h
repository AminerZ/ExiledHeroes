#pragma once
#include <cstdint>

namespace ExiledHeroes {
	class Endianness {
	public:
		static bool isLittleEndian() {
			uint16_t number = 0x1;
			return ((char*)& number)[0];
		}

		static void swapEndianness(char* str, const std::streamsize count) {
			std::reverse(str, str + count);
		}
	};
}