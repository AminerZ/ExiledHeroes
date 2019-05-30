#include "TagUtil.h"
#include "Tags.h"

#include <fstream>

using namespace ExiledHeroes;

// Factory
std::unique_ptr<Tag> TagUtil::makeTag(TagType type, std::string name) {
	switch (type)
	{
	case TagType::End:
		throw "End does not have a Tag class";
		return nullptr;
	case TagType::Byte:		return std::make_unique<TagByte>(name);
	case TagType::Short:	return std::make_unique<TagShort>(name);
	case TagType::Int:		return std::make_unique<TagInt>(name);
	case TagType::Long:		return std::make_unique<TagLong>(name);
	case TagType::Float:	return std::make_unique<TagFloat>(name);
	case TagType::Double:	return std::make_unique<TagDouble>(name);
	case TagType::String:	return std::make_unique<TagString>(name);
	//case TagType::List:		return std::make_unique<TagCompound>(name);
	case TagType::Compound:	return std::make_unique<TagCompound>(name);
	default:
		throw "No type matching TagType found";
		return nullptr;
	}
}

std::unique_ptr<TagCompound> TagUtil::fromFile(std::string path) {
	auto rootTag = makeTag<TagCompound>();

	std::ifstream file(path, std::ios::binary);
	rootTag->read(file);
	file.close();

	return rootTag;
}