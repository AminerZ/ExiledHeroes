#pragma once
#include <istream>

namespace ExiledHeroes {
	class EndianIStream {
	private:
		std::istream& stream;
	public:
		EndianIStream(std::istream& stream);

		void read(std::string& str, std::streamsize size);
		
		template<typename T> // Primitive Types
		void read(T* t);


		void read(char* rsc, std::streamsize size, bool check = true);

		int peek();
		void ignore(const std::streamsize count);
	};

	template<typename T> // Primitive Types
	void EndianIStream::read(T* t) {
		read((char*)t, sizeof(T));
	}
}