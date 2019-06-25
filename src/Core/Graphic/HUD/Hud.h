#pragma once
#include <memory>
#include <map>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/View.hpp>

#include "Core/Component/Updatable.h"

namespace ExiledHeroes {
	class Hud;
	class IHudLayer : public sf::Drawable, public Updatable {
	public:
		~IHudLayer() {};

	protected:
		friend class Hud;

	protected:
		virtual void update(float delta) = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
		virtual sf::View getView() = 0;
	};
	
	class Hud : public sf::Drawable, public Updatable {
	private:
		std::map<int8_t, std::unique_ptr<IHudLayer>> layers;
	public:
		Hud();

		void add(int8_t depth, std::unique_ptr<IHudLayer>& layer);
		void remove(int8_t depth);

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(float delta) override;
	};
};