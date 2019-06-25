#include <memory>

#include "Core/Game.h"
#include "Game/State/States.h"

using namespace ExiledHeroes;

void initializeStates(std::unique_ptr<StateHandler>&& stateHandler);

/* Main Entry Point of the Game */
int main(int argc, char* argv[]) {

	std::unique_ptr<Game> game = std::make_unique<Game>(argc, argv);

	initializeStates(game->getStateHandler());

	game->run();
	return 0;
}

void initializeStates(std::unique_ptr<StateHandler>&& stateHandler) {
	stateHandler->add<LoadState>(States::Load);
	stateHandler->add<TestState>(States::Test);
	// TODO: add more States Here
	
	LoadState::LoadStat loadStat(States::Test);
	loadStat.textures = { {"TestAtlas", "./res/TestAtlasTile.png"} };
	stateHandler->get<LoadState>(States::Load)
		->setStat(loadStat);
	
	stateHandler->setState(States::Load);
}