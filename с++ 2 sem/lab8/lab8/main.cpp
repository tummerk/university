#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML Rotation & Movement");


    RectangleShape rect(Vector2f(100, 50));
    CircleShape shape(100, 5);

    rect.setFillColor(Color::Green);
    rect.setOrigin(50, 25); 
    rect.setPosition(200, 150); 

    shape.setOutlineColor(Color::Red);
    shape.setPosition(300,300);

    float rotationSpeed = 90.0f; 
    float movementSpeed = 0.0f; 
    Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        rect.rotate(rotationSpeed * deltaTime);

        float angle = rect.getRotation(); 
        float radians = angle * 3.14159f / 180.0f;
        Vector2f direction(std::cos(radians), std::sin(radians));
        rect.move(direction * movementSpeed * deltaTime);

        window.clear();
        window.draw(rect);
        window.draw(shape);
        window.display();
    }

    return 0;
}