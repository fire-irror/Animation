#include <SFML/Graphics.hpp>

    int main(void) {

        RenderWindow window(VideoMode(1200, 800), "AfterSchool2");// 화면 크기, 제목
        window.setFramerateLimit(60);// 60초마다 한 번씩 돌아간다

        // f : 소수
        // Vector2i : 정수

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
                }
            }
        }

        return 0;
    }
}