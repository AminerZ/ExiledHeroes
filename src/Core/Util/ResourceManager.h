#pragma once
#include <unordered_map>
#include <memory>
#include <mutex>
#include <string>

#include <SFML/Graphics/Texture.hpp>

namespace ExiledHeroes {
	template<class T>
	class Manager {
	private:
		std::mutex mutex;

		std::unordered_map<std::string, std::shared_ptr<T>> resources;
	public:
		void add(std::string id, std::shared_ptr<T> res) {
			std::lock_guard<std::mutex> guard(mutex);
			resources.insert({ id,res });
		}

		void remove(std::string id) {
			std::lock_guard<std::mutex> guard(mutex);
			auto iterator = resources.find(id);
			if(iterator != resources.end())
				resources.erase(iterator);
		}

		std::shared_ptr<T> get(std::string id) {
			return resources.at(id);
		}
	};

	struct ResourceManager {
		static Manager<sf::Texture> textureManager;
	};
}