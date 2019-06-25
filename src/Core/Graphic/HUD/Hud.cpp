#include "Hud.h"

using namespace ExiledHeroes;

Hud::Hud(){}

void Hud::add(int8_t depth, std::unique_ptr<IHudLayer>& layer) {
	layers.insert({ depth, std::move(layer) });
}

void Hud::remove(int8_t depth) {
	layers.erase(depth);
}

void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& layer : layers) {
		target.setView(layer.second->getView());
		target.draw(*layer.second, states);
	}
}

void Hud::update(float delta) {
	for (auto& layer : layers) {
		layer.second->update(delta); // TODO: Maybe it has bug
	}
}