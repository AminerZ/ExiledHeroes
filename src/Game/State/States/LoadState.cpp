#include "LoadState.h"

#include "Core/Util/ResourceManager.h"

#include "Core/State/StateHandler.h"

using namespace ExiledHeroes;

LoadState::LoadState(StateHandler* stateHandler) 
	: State(stateHandler), loadStat(0){}

void LoadState::setStat(LoadStat stat) {
	loadStat = stat;
}

void LoadState::onSelect(State* from) {}

/// Load all in one update
void LoadState::update(float delta) {
	if (loadStat.to == 0) // load payload is going to load EmptyState
		return;

	for (auto& textureData : loadStat.textures) {
		auto texture = std::make_shared<sf::Texture>();
		texture->loadFromFile(textureData.second);
		ResourceManager::textureManager.add(textureData.first, texture);
	}

	stateHandler->setState(loadStat.to);
}