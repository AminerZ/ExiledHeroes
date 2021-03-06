#pragma once
#include <memory>
#include <unordered_map>
#include <iostream>
#include <string>

#include "Core/Tag/Tag.h"
#include "Core/Tag/TagUtil.h"

namespace ExiledHeroes {

	class TagCompound : public Tag {
	private:
		std::unordered_map<std::string, std::unique_ptr<Tag>> tags;
	public:
		TagCompound()
			: Tag(TagType::Compound) {}

		TagCompound(std::string name)
			: Tag(TagType::Compound, name) {}

		void add(std::unique_ptr<Tag>& tag) {
			tags.insert({ tag->getName(), std::move(tag) });
		}

		void remove(std::string name) {
			tags.erase(name);
		}
	private:
		void readPayload(std::istream& input) override{
			while (input.peek() != TagType::End) {
				TagType type = (TagType) input.peek(); // Peek element type from stream
				std::cout << getName() + "::Reading Tag Type " << (char)(type+48) << std::endl;

				std::unique_ptr<Tag> tag = TagUtil::makeTag(type);

				tag->read(input); // Read Tag Data to tag
				add(tag);
			}
			input.ignore(sizeof(TagType::End));
		}

		void writePayload(std::ostream& output) override {
			for (auto& tag : tags)
				tag.second->write(output);
			output.put(TagType::End); // Write an End Tag at the end of Compound
		}
	};
}