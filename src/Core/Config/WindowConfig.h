#pragma once
#include <string>

namespace ExiledHeroes {
	struct  WindowConfig
	{
		unsigned int width = 1280, height = 720;
		std::string title = "Exiled Heroes";
		
		int8_t antiAliasingLevel = 4;
		int8_t windowMode = 0;
	};
}