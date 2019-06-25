#include "Window.h"

using namespace ExiledHeroes;

Window::Window(WindowConfig config)
	: window(std::make_unique<sf::RenderWindow>())
{
	configure(config);
	window->setVerticalSyncEnabled(true);
}

void Window::clear(sf::Color color)
{
	window->clear(color);
}

void Window::display()
{
	window->display();
}

bool Window::isOpen() const {
	return window->isOpen();
}

void Window::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{
	window->draw(drawable, states);
}

void Window::configure(WindowConfig config) {
	width = config.width;
	height = config.height;
	title = config.title;
	antiAliasingLevel = (AntiAliasing)config.antiAliasingLevel;
	windowMode = (WindowMode)config.windowMode;
	createWindow();
}

void Window::pollEvents() {
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			close();
	}
}

void Window::setTitle(std::string name) {
	title = name;
}

void Window::close()
{
	window->close();
}

void Window::createWindow() {
	sf::VideoMode vidMode;
	windowMode == WindowMode::Fullscreen ?
		vidMode = sf::VideoMode::getDesktopMode() : 
		vidMode = sf::VideoMode(width, height);

	sf::Uint32 style;
	windowMode == WindowMode::Fullscreen ?
		style = sf::Style::Fullscreen :
		style = sf::Style::Titlebar | sf::Style::Close;

	sf::ContextSettings settings = sf::ContextSettings();
	settings.antialiasingLevel = antiAliasingLevel;

	window->create(vidMode, "Exiled Heroes", style, settings);
}

void Window::setWindowMode(WindowMode mode) {
	windowMode = mode;
	createWindow();
}