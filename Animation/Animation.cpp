#include <SFML/Graphics.hpp>

    int main(void) {

        RenderWindow window(VideoMode(1200, 800), "AfterSchool2");// ȭ�� ũ��, ����
        window.setFramerateLimit(60);// 60�ʸ��� �� ���� ���ư���

        // f : �Ҽ�
        // Vector2i : ����

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