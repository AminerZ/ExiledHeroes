#pragma once
#include <memory>
#include <string>

#include "Tag.h"

namespace ExiledHeroes {
	class TagCompound;
	struct TagUtil {
		// Factory
		static std::unique_ptr<Tag> makeTag(TagType type, std::string name = "");

		template<class T>
		static std::unique_ptr<T> makeTag(std::string name = "");

		// I/O
		static std::unique_ptr<TagCompound> fromFile(std::string path);

		// Util
		template<class T>
		static TagType getPrimitiveType();
	};

	// Factory
	template<class T>
	static std::unique_ptr<T> TagUtil::makeTag(std::string name) {
		static_assert(std::is_base_of<Tag, T>(), "T base is not a Tag");
		return std::make_unique<T>(name);
	}

	// Util
	template<class T>
	static TagType TagUtil::getPrimitiveType() {
		const char* type = TYPE_NAME(T);
		if (type == TYPE_NAME(int8_t))   return TagType::Byte;
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