#pragma once
#include "Core/State/State.h"

#include <map>

namespace ExiledHeroes {

	class LoadState : public State {
	public:
		struct LoadStat {
			LoadStat(int to) : to(to) {}

			int to;
			std::map<std::string, std::string> textures;
		};
	private:
		LoadStat loadStat;
	public:
		LoadState(StateHandler* stateHandler);

		void setStat(LoadStat load);
	private:
		void onSelect(State* from);
		//void onChange(State* to);

		//void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void update(float delta);
	};
}