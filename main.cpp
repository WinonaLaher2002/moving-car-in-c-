#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Rain drop structure
struct RainDrop {
    float x, y;
    float speed;
};

// Initialize rain drops
std::vector<RainDrop> initRain(int count) {
    std::vector<RainDrop> rain;
    for (int i = 0; i < count; i++) {
        RainDrop drop;
        drop.x = static_cast<float>(rand() % WIDTH);
        drop.y = static_cast<float>(rand() % (HEIGHT - 60));
        drop.speed = static_cast<float>((rand() % 5) + 3);
        rain.push_back(drop);
    }
    return rain;
}

// Random color (avoiding black)
sf::Color randomColor() {
    sf::Color colors[] = {
        sf::Color::Red, sf::Color::Green, sf::Color::Blue,
        sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta,
        sf::Color::White, sf::Color(255, 165, 0),   // Orange
        sf::Color(128, 0, 128),                       // Purple
        sf::Color(0, 255, 127),                       // Spring Green
        sf::Color(255, 20, 147),                      // Deep Pink
        sf::Color(0, 191, 255),                       // Deep Sky Blue
        sf::Color(255, 215, 0),                       // Gold
        sf::Color(50, 205, 50)                        // Lime Green
    };
    return colors[rand() % 14];
}

// Draw car at position (cx, cy) with given color
void drawCar(sf::RenderWindow& window, float cx, float cy, sf::Color carColor) {
    // Car body (ellipse approximated with a scaled circle)
    sf::CircleShape body(30.f);
    body.setScale(1.f, 0.4f);
    body.setFillColor(carColor);
    body.setOrigin(30.f, 30.f);
    body.setPosition(cx, cy);
    window.draw(body);

    // Car top (trapezoid using convex shape)
    sf::ConvexShape top;
    top.setPointCount(4);
    top.setPoint(0, sf::Vector2f(cx - 20, cy));
    top.setPoint(1, sf::Vector2f(cx - 10, cy - 15));
    top.setPoint(2, sf::Vector2f(cx + 10, cy - 15));
    top.setPoint(3, sf::Vector2f(cx + 20, cy));
    top.setFillColor(carColor);
    window.draw(top);

    // Left wheel
    sf::CircleShape leftWheel(8.f);
    leftWheel.setFillColor(sf::Color::Black);
    leftWheel.setOrigin(8.f, 8.f);
    leftWheel.setPosition(cx - 20, cy + 10);
    window.draw(leftWheel);

    // Right wheel
    sf::CircleShape rightWheel(8.f);
    rightWheel.setFillColor(sf::Color::Black);
    rightWheel.setOrigin(8.f, 8.f);
    rightWheel.setPosition(cx + 20, cy + 10);
    window.draw(rightWheel);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Moving Car with Rain");
    window.setFramerateLimit(10); // ~100ms delay like original

    std::vector<RainDrop> rain = initRain(100);

    float carX = static_cast<float>(WIDTH / 2);
    float carY = static_cast<float>(HEIGHT - 40);
    sf::Color carColor = randomColor();
    int colorTimer = 0;

    // Road
    sf::RectangleShape road(sf::Vector2f(static_cast<float>(WIDTH), 60.f));
    road.setFillColor(sf::Color(64, 64, 64)); // Dark gray
    road.setPosition(0, static_cast<float>(HEIGHT - 60));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                window.close(); // Any key closes like kbhit()
        }

        // Change car color every frame (like original random color)
        carColor = randomColor();

        // Update rain
        for (auto& drop : rain) {
            drop.y += drop.speed;
            if (drop.y > HEIGHT - 60) {
                drop.y = 0;
                drop.x = static_cast<float>(rand() % WIDTH);
            }
        }

        // Draw everything
        window.clear(sf::Color(20, 20, 40)); // Dark background

        // Draw rain
        for (const auto& drop : rain) {
            sf::Vertex rainLine[] = {
                sf::Vertex(sf::Vector2f(drop.x, drop.y), sf::Color(173, 216, 230)),       // Light blue
                sf::Vertex(sf::Vector2f(drop.x, drop.y + 5), sf::Color(173, 216, 230))
            };
            window.draw(rainLine, 2, sf::Lines);
        }

        // Draw road
        window.draw(road);

        // Draw car
        drawCar(window, carX, carY, carColor);

        window.display();
    }

    return 0;
}
