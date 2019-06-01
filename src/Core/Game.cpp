#include "Game.h"

using namespace ExiledHeroes;

Game::Game()
	: Game(0,nullptr) {}

Game::Game(int argc, char* argv[])
	: window(std::make_unique<Window>()){
}

Game::~Game() {}

void Game::run() {
	while (window->isOpen()) {
		window->pollEvents();
		update(clock.restart().asSeconds());

		window->clear();
		window->draw(*this);
		window->display();
	}

	window->close();
}

Handlers& Game::getHandlers() {
	return handlers;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	window->draw(handlers, states);
}

void Game::update(float delta)
{
	handlers.update(delta);
}