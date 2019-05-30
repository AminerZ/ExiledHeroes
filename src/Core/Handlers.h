#pragma once
#include <memory>

#include <SFML/Graphics/Drawable.hpp>

#include "Core/Component/Updatable.h"
#include "Core/State/StateHandler.h"

namespace ExiledHeroes {
	struct Handlers: public sf::Drawable, public Updatable {
		std::unique_ptr<StateHandler> stateHandler = std::make_unique<StateHandler>();
		// TODO: ADD more handler here

		void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			target.draw(*stateHandler, states);
		}

		void update(float delta) {
			stateHandler->update(delta);
		}
	};
}