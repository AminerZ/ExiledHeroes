#pragma once
#include <ostream>

namespace ExiledHeroes {
	class EndianOStream {
	private:
		std::ostream& stream;
	public:
		EndianOStream(std::ostream& stream);

		void write(std::string& str, std::streamsize size);

		template<typename T> // Primitive Types
		void write(T* t);

		void put(char ch);

		/**
		* Default Endianness is Little endian and any Big Endianness System will swap the bytes
		*/
		void write(char* str, std::streamsize size, bool check = true);

		//int peek();
		//void ignore(const std::streamsize count);
	};

	template<typename T> // Primitive Types
	void EndianOStream::write(T* t) {
		write((char*)t, sizeof(T));
	}
}