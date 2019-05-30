#pragma once
#include <memory>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Core/Component/Updatable.h"
#include "State.h"

namespace ExiledHeroes {

	class StateHandler : public sf::Drawable, Updatable{
	public:
		typedef std::shared_ptr<State> StatePtr;
	private:
		std::map<short, StatePtr> states;
		StatePtr currentState;
	public:
		StateHandler();
		StateHandler(int id, StatePtr state);
		~StateHandler();

		void setState(int id);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(float delta);

		void add(int id, StatePtr statePtr);
		void remove(int id);
	};
}