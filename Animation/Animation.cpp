#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

struct Player {
	RectangleShape sprite;
	int fps;    //frames per sec
	int idx;    //animation index
	int frames; //animation frame num
	long ani_time;  //animation change time
	long ani_delay;	//animation delay
	int speed;
	int is_jumping;	//during jumping
	int jumping_time;	//start jumping time
	int jump_speed;
};


int main(void)
{
	RenderWindow window(VideoMode(1200, 800), "Animation");
	window.setFramerateLimit(60);

	long start_time;
	long spent_time;
	const int GRAVITY = 5;
	const int PLATFORM_Y = 400;	//땅바닥의 y좌표

	Texture run[10];
	run[0].loadFromFile("./animation/Run__000.png");
	run[1].loadFromFile("./animation/Run__001.png");
	run[2].loadFromFile("./animation/Run__002.png");
	run[3].loadFromFile("./animation/Run__003.png");
	run[4].loadFromFile("./animation/Run__004.png");
	run[5].loadFromFile("./animation/Run__005.png");
	run[6].loadFromFile("./animation/Run__006.png");
	run[7].loadFromFile("./animation/Run__007.png");
	run[8].loadFromFile("./animation/Run__008.png");
	run[9].loadFromFile("./animation/Run__009.png");

	struct Player player;
	player.frames = 10;
	player.idx = 0;
	player.sprite.setTexture(&run[0]);
	player.sprite.setSize(Vector2f(90, 120));
	player.sprite.setPosition(200, 200);
	player.ani_delay = 1000 / player.frames / 2;		// 0.5초바다 걸음
	player.speed = 5;
	player.jump_speed = GRAVITY * 2;

	start_time = clock();
	player.ani_time = start_time;
	player.jumping_time = start_time;
	player.is_jumping = 0;

	while (window.isOpen())
	{
		spent_time = clock() - start_time;
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Space) {
					//점프
					if (player.is_jumping == 0) {
						player.jumping_time = spent_time;
					}
					player.is_jumping = 1;
				}
			default:
				break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.sprite.setScale(1, 1);
			player.sprite.move(player.speed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.sprite.setScale(-1, 1);
			player.sprite.move(-player.speed, 0);
		}

		// 0.1초마다 애니메이션 그림이 바뀜
		while (spent_time - player.ani_time > player.ani_delay)
		{
			player.ani_time = spent_time;
			player.sprite.setTexture(&run[player.idx % player.frames]);
			player.idx++;
		}

		//필요하다면 1000을 나중에 변수 처리할것
		if (spent_time - player.jumping_time > 1000)
		{
			player.is_jumping = 0;
		}
		player.sprite.move(0,GRAVITY);

		if (player.is_jumping == 1) {
			player.sprite.move(0, -player.jump_speed);
		} 

		// 플레이어가 땅바닥에 착지하면
		if (player.sprite.getPosition().y + player.sprite.getSize().y > PLATFORM_Y) {
			// 더 이상 내려갈 수 없게 한다.
			player.sprite.setPosition(player.sprite.getPosition().x, PLATFORM_Y - player.sprite.getSize().y);
		}


		window.clear(Color::Magenta);

		window.draw(player.sprite);

		window.display();
	}

	return 0;
}