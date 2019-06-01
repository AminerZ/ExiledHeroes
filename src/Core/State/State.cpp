#include "State.h"

using namespace ExiledHeroes;

State::State() {}
State::~State() {}

void ExiledHeroes::State::onSelect(StatePtr& from) {}

void ExiledHeroes::State::onChange(StatePtr& to) {}

void State::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

void State::update(float delta) {}