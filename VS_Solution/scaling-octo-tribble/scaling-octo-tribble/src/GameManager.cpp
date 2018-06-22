#include "GameManager.h"
#include "TextureManager.h"
#include<chrono>


GameManager::GameManager(int width, int height)
	: window(sf::VideoMode(width, height), "Tribbles!")
{
	auto& textures = TextureManager::getSingleton();

	testSprite.setTexture(textures.getTexture(TextureID::TRIBBLE));
	testSprite.setPosition(50, 50);
}

void GameManager::gameLoop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		tick();

		window.clear();

		window.draw(testSprite);

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
	nanoseconds delta_ns = now - last_frame;
	milliseconds delta_milis = duration_cast<milliseconds>(delta_ns);
	float delta_ms = static_cast<float>(delta_milis.count());

	//Let's set up delta_time to be a fraction of a second. This may not be standard practice (it might be), but it allows us to
	//use speeds variables like "move 1200 pixels a second" which kind of gives us a mental idea of what the values we're using
	//So, if a delta_time has a value of 0.5 means half of a second occured since the last frame occured; (0.5 * 1second).
	//Now, we can base all our speeds on pixels per second! 
	float delta_time = delta_ms / 1000.f;

	//io before actor logical/ai ticks
	io(delta_time);
	
	//process all ticks

	//update last frame after processing of tick.
	last_frame = now;
}

void GameManager::io(float delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		static float debug_move_speed = 1200.f; //device units(pixels) per second; should clear screen in 1 second regardless of framerate
		auto pos = testSprite.getPosition();
		testSprite.setPosition(pos.x + debug_move_speed * delta_time, pos.y);
	}
}
