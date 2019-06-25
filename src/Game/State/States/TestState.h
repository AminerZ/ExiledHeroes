#pragma once
#include "Core/State/State.h"

#include "Core/TileMap/TileMap.h"

namespace ExiledHeroes {

	class TestState : public State {
	private:
		TileMap tileMap;
	public:
		TestState(StateHandler* stateHandler);
		~TestState();
	private:
		void onSelect(State* from);
		void onChange(State* to);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void update(float delta);
	};
}