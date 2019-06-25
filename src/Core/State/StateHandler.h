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
		typedef std::unique_ptr<State> StatePtr;
	private:
		std::map<short, StatePtr> states;
		State* currentState;
	public:
		StateHandler();
		~StateHandler();

		void setState(int id);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(float delta);

		template<class T = State>
		void add(int id) {
			states.emplace(id, new T(this));
		}
		void remove(int id);
	};
}