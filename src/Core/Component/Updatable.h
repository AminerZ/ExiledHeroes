#pragma once
namespace ExiledHeroes {
	class Updatable {
	protected:
		virtual void update(float delta) = 0;
	};
}