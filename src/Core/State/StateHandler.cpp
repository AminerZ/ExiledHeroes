#include "StateHandler.h"

using namespace ExiledHeroes;

StateHandler::StateHandler()
	: currentState(nullptr) {

	add<State>(0);
	setState(0);
}

StateHandler::StateHandler(int id, StatePtr& state)
	: currentState(nullptr) {

	add(0, std::make_unique<State>());
	add(id, state);
	setState(id);
}

StateHandler::~StateHandler() {}

void StateHandler::setState(int id) {
	try
	{
		StatePtr& newState = states.at(id);
		
		if (currentState) // If currentState pointing to a State
			currentState->onChange(newState.get());
		newState->onSelect(currentState);
		
		currentState = newState.get();
	}
	catch (...) {
		StatePtr& newState = states.at(0);
		currentState->onChange(newState.get());
		currentState = newState.get();
	}
}

void StateHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*currentState, states);
}

void StateHandler::update(float delta) {
	currentState->update(delta);
}

void StateHandler::remove(int id) {
	states.erase(id);
}