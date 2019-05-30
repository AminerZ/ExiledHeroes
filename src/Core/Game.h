#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "Handlers.h"
#include "UI/Window.h"
#include "Core/Component/Updatable.h"

namespace ExiledHeroes {
	class Game : public sf::Drawable, public Updatable{
	private:
		Handlers handlers;
		std::unique_ptr<Window> window;
		sf::Clock clock;
	public:
		Game();
		Game(int argc, char* argv[]);
		~Game();
		
		void run();

		Handlers& getHandlers();
		
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(float delta) override;
	};
}