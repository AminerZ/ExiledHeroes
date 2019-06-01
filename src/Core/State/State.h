#pragma once
#include <memory>

#include <SFML/Graphics.hpp>

#include "Core/Component/Updatable.h"

namespace ExiledHeroes {
	class State : public sf::Drawable, public Updatable
	{
	public:
		State();
		virtual ~State();

		virtual void onSelect(State* from);
		virtual void onChange(State* to);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void update(float delta);
	};
}
