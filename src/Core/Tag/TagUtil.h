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
	};

	// Factory
	template<class T>
	static std::unique_ptr<T> TagUtil::makeTag(std::string name) {
		static_assert(std::is_base_of<Tag, T>(), "T base is not a Tag");
		return std::make_unique<T>(name);
	}
}