#pragma once
#include <memory>

#include <SFML/Graphics.hpp>

#include "Core/Component/Updatable.h"

namespace ExiledHeroes {
	class State : public sf::Drawable, public Updatable
	{
	protected:
		typedef std::shared_ptr<State> StatePtr;
	public:
		State();
		virtual ~State();

		virtual void onSelect(StatePtr& from);
		virtual void onChange(StatePtr& to);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void update(float delta);
	};
}
