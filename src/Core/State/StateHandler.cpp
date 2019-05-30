#include "StateHandler.h"

using namespace ExiledHeroes;

StateHandler::StateHandler()
{
	add(0, std::make_shared<State>());
	setState(0);
}

StateHandler::StateHandler(int id, StatePtr state)
{
	add(0, std::make_shared<State>());
	add(id, state);
	setState(id);
}

StateHandler::~StateHandler() {}

void StateHandler::setState(int id)
{
	try 
	{
		StatePtr& newState = states.at(id);
		
		if (currentState != nullptr)
			currentState->onChange(newState);
		newState->onSelect(currentState);
		
		currentState = newState;
	}
	catch (...) { currentState = states.at(0);}
}

void StateHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*currentState, states);
}

void StateHandler::update(float delta)
{
	currentState->update(delta);
}

void StateHandler::add(int id, StatePtr statePtr)
{
	states.insert({ id, statePtr });
}

void StateHandler::remove(int id)
{
	states.erase(id);
}