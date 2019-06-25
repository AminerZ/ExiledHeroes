#pragma once
#include <memory>
#include <vector>

#include "Core/Tag/Tag.h"
#include "Core/Tag/Tags/TagCompound.h"

namespace ExiledHeroes {

	class TagCompoundList : public Tag {
	private:
		 std::vector<std::unique_ptr<TagCompound>> tags;
	public:
		TagCompoundList()
			: Tag(TagType::CompoundList) {}

		TagCompoundList(std::string name)
			: Tag(TagType::CompoundList, name) {}

		TagCompound* at(int index) {
			return tags.at(index).get();
		}

		TagCompound* operator[] (int index) {
			return tags[index].get();
		}

		void add(std::unique_ptr<TagCompound> tag) {
			tags.push_back(std::move(tag));
		}

		int getSize() {
			return static_cast<int>(tags.size());
		}

	private:
		void readPayload(EndianIStream& input) override {
			int16_t tagsSizeBuffer;
			input.read<int16_t>(&tagsSizeBuffer);

			tags.reserve(tagsSizeBuffer);
			for (int i = 0; i < tagsSizeBuffer; i++) {
				std::unique_ptr<TagCompound> tag = std::make_unique<TagCompound>();
				tag->read(input);
				add(std::move(tag));
			}
		}

		void writePayload(EndianOStream& output) override {
			int16_t tagsSizeBuffer = (int16_t)tags.size();
			output.write<int16_t>(&tagsSizeBuffer);
			
			for (auto& tag : tags)
				tag->write(output);
		}
	};
}