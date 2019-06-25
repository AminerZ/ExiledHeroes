#include "TestState.h"

#include "Core/Util/ResourceManager.h"

using namespace ExiledHeroes;

TestState::TestState(StateHandler* stateHandler)
	: State(stateHandler) {}

TestState::~TestState() {}

void TestState::onSelect(State* from) {
	tileMap.loadFromFile("./res/level.xbt");
}

void TestState::onChange(State* to) {}

void TestState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(tileMap, states);
}

#include <iostream>
void TestState::update(float delta) { std::cout << "Test"; }