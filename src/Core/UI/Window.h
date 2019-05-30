#pragma once
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "Core/Config/WindowConfig.h"

namespace ExiledHeroes {

	class Window {
	public:
		enum AntiAliasing : int8_t {
			OFF = 0,
			MSAAx1 = 1,
			MSAAx2 = 2,
			MSAAx4 = 4,
			MSAAx8 = 8
		};

		enum WindowMode : int8_t{
			Windowed,
			Fullscreen
		};
	private:
		unsigned int width, height;
		std::string title;
		AntiAliasing antiAliasingLevel;
		WindowMode windowMode;

		sf::Event event;
		std::unique_ptr<sf::RenderWindow> window;

	public:
		Window(WindowConfig conf = WindowConfig());

		void clear(sf::Color color = sf::Color(0, 0, 0, 255));
		void display();

		bool isOpen() const;

		void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

		void configure(WindowConfig config);

		void poolEvents();
		void setTitle(std::string name);
		void close();
	private:
		void createWindow();
		void Window::setWindowMode(WindowMode mode);
	};

}