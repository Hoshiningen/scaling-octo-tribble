#include "GameManager.h"
#include "TextureManager.h"
#include "TribbleBuilder.h"

#include <algorithm>
#include <chrono>
#include <memory>

GameManager::GameManager(int width, int height)
    : window(sf::VideoMode(width, height), "Tribbles!"),
      player(std::make_unique<Player>(sf::Vector2f(width / 2.f, height / 2.f)))
{
	//really fast frames will such a small time between two ticks, that the delta time will be zero (after casting).
	//this cause zero multiplication propagations and cause a a jittery movement effect.
	window.setFramerateLimit(60);

	auto& textures = TextureManager::getSingleton();

    player->setTexture(textures.getTexture(TextureID::PLAYER));
    player->setColor(sf::Color::Cyan);

    sf::FloatRect globalBounds = player->getGlobalBounds();  
    player->setOrigin(globalBounds.width / 2.f, globalBounds.height / 2.f);
    player->setPosition(width / 2.f, height * .9f);

    addTribble();
}

void GameManager::gameLoop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || shutdown)
				window.close();			
		}

		tick();
		window.clear();

        std::for_each(std::begin(tribbles), std::end(tribbles),
            [win = &window](auto& triblePair) 
            { 
                win->draw(triblePair.second);
            });

        window.draw(*player);

		//buffer swap
		window.display();
	}
}

void GameManager::tick()
{
	//function encapsulated last frame
	static auto last_frame = std::chrono::steady_clock::now();
	using std::chrono::duration_cast;
	using std::chrono::milliseconds;
	using std::chrono::nanoseconds;	

	//set up delta time
	auto now = std::chrono::steady_clock::now();
	milliseconds delta_milis = duration_cast<milliseconds>(now - last_frame);
	auto delta_ms = static_cast<float>(delta_milis.count());

	//Let's set up delta_time to be a fraction of a second. This may not be standard practice (it might be), but it allows us to
	//use speeds variables like "move 1200 pixels a second" which kind of gives us a mental idea of what the values we're using
	//So, if a delta_time has a value of 0.5 means half of a second occured since the last frame occured; (0.5 * 1second).
	//Now, we can base all our speeds on pixels per second! 
	float delta_time = delta_ms / 1000.f;

	//io before actor logical/ai ticks
	io(delta_time);
	
	//process all ticks
	tickAll(delta_time);

	//update last frame after processing of tick.
	last_frame = now;
}

void GameManager::io(float delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		//static const float debug_move_speed = 1200.f; //device units(pixels) per second; should clear screen in 1 second regardless of framerate
		//auto pos = testSprite.getPosition();
		//testSprite.setPosition(pos.x + debug_move_speed * delta_time, pos.y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		shutdown = true;
	}
}

void GameManager::addTribble()
{
	static const float scaleFactor = 0.66f;

    TribbleBuilder tribbleBuilder;
    auto newSprite = tribbleBuilder.setPosition({ 50, 50 })
        .setScale({ scaleFactor / 2, scaleFactor })
        .setTexture(TextureManager::getSingleton().getTexture(TextureID::TRIBBLE))
        .create();

    tribbles.emplace(std::move(newSprite), *newSprite);
}

void GameManager::addTribble(float x, float y)
{
    static const float scaleFactor = 0.66f;

    TribbleBuilder tribbleBuilder;
    auto newSprite = tribbleBuilder.setPosition({ x, y })
        .setTexture(TextureManager::getSingleton().getTexture(TextureID::TRIBBLE))
        .setScale({ scaleFactor / 2, scaleFactor })
        .setVelocity({25, 100})
        .create();

    tribbles.emplace(std::move(newSprite), *newSprite);
}

void GameManager::tickAll(float deltaTime)
{
    std::for_each(std::begin(tribbles), std::end(tribbles),
        [delta = deltaTime](auto& triblePair)
        { 
            triblePair.second.tick(delta);
        });

    player->tick(deltaTime);
}
