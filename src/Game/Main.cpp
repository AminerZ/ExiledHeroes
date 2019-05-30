#include <memory>

#include "Core/Game.h"
#include "Game/States/States.h"

using namespace ExiledHeroes;

/* Main Entry Point of the Game */
int main(int argc, char* argv[]) {
	std::unique_ptr<ExiledHeroes::Game> game = 
		std::make_unique<ExiledHeroes::Game>(argc, argv);
	
	auto& stateHandler = game->getHandlers().stateHandler;
	
	game->run();
	return 0;
}