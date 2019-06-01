#include "State.h"

using namespace ExiledHeroes;

State::State() {}
State::~State() {}

void ExiledHeroes::State::onSelect(State* from) {}

void ExiledHeroes::State::onChange(State* to) {}

void State::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

void State::update(float delta) {}