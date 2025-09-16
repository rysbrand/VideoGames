#include "../Header/stdafx.h"
#include "../Header/Game.h"

using namespace std;

int main()
{

	//set up window dimensions
	const int windowWidth = 1000;
	const int windowHeight = 700;


	//create and title the window
	sf::RenderWindow window(sf::VideoMode({ windowWidth, windowHeight }), "My window");
	window.setFramerateLimit(60);

	//load the background texture
	sf::Texture btexture("C:\\Users\\becca.ysbrand\\OneDrive - Southeast Technical College\\Desktop\\VideoGames\\VideoGames\\Platformerpack\\PNG\\Backgrounds\\blue_desert.png");

	//create the background sprite
	sf::Sprite background(btexture);
	//set the texture to be repeated to cover the entire window
	sf::IntRect textureRect({ 0, 0 }, { windowWidth * 8, windowHeight * 2 });
	background.setTextureRect(textureRect);
	btexture.setRepeated(true);

	//create a view
	sf::View view(window.getDefaultView());

	//load the player texture
	sf::Texture texture("C:\\Users\\becca.ysbrand\\OneDrive - Southeast Technical College\\Desktop\\VideoGames\\VideoGames\\cute_pixelperson.png");
	if (!texture.loadFromFile("C:\\Users\\becca.ysbrand\\OneDrive - Southeast Technical College\\Desktop\\VideoGames\\VideoGames\\cute_pixelperson.png")) {
		std::cerr << "Failed to load texture\n";
		return 1;
	}
	//create the player sprite
	sf::Sprite player(texture);

	//set the origin to the center of the sprite for rotation and scaling
	player.setOrigin(sf::Vector2f(0, 0));

	//set initial position of the player
	sf::Vector2f pos{ 10.f, 50.f };
	sf::Vector2f vel{ 0.f, 0.f };
	const float moveSpeed = 220.f;     // px/s
	const float jumpVel = -420.f;    // px/s (negative = up)
	const float gravity = 1200.f;    // px/s^2
	bool onGround = false;
	float spritespeed = 5.0f;
	
	auto bounds = player.getGlobalBounds();
	float groundY = windowHeight - bounds.size.y - 10.f;

	pos.y = groundY;

	sf::Clock clock;
	sf::Time t1 = sf::microseconds(10000);
	sf::Time t2 = sf::milliseconds(10);
	sf::Time t3 = sf::seconds(0.0f);

	pos = player.getPosition();

	while(window.isOpen())

	{
		while (const std::optional<sf::Event> event = window.pollEvent())
		{
			bool jumpPressed = false;
			if (event->is<sf::Event::Closed>())
				window.close();

			if (event->is<sf::Event::KeyReleased>()) {
				//handle key release. here for debugging purposes.
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))  jumpPressed = true;

			if (jumpPressed && onGround) {
				vel.y = jumpVel;
				onGround = false;
			}

		}
		float deltaTime = clock.restart().asSeconds();
		// Keyboard input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			std::cout << "Right key pressed" << std::endl;
			pos.x += spritespeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			std::cout << "Left key pressed" << std::endl;
			pos.x -= spritespeed;
		}

		vel.y += gravity * deltaTime;
		pos += vel * deltaTime;

		if (pos.y >= groundY) {
			pos.y = groundY;
			vel.y = 0.f;
			onGround = true;
		}

		view.setCenter(player.getPosition());
		window.setView(view);

		player.setPosition(pos);
		window.clear(sf::Color(30, 30, 45));
		window.draw(background);
		window.draw(player);
		window.display();
	}
	return 0;
}