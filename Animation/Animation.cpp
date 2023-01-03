#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

int main(void)
{
    RenderWindow window(VideoMode(1200, 800), "Animation");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
    }

    return 0;
}