

#include <iostream>
#include <SFML/Graphics.hpp>

//definitions
#define MODE_WIDTH 1100
#define MODE_HEIGHT 800

using namespace std;
using namespace sf;

int main()
{
    
    RenderWindow window(VideoMode(MODE_WIDTH, MODE_HEIGHT), "Chess Game");

    while (window.isOpen()) {
        Event evnt;
        while (window.pollEvent(evnt)) {
            

        }
    }
}
