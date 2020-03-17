#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "chessPiece.h"
#include "getAvailableSquares.h"

//definitions
#define MODE_WIDTH 1200
#define MODE_HEIGHT 900

using namespace std;
using namespace sf;

int main()
{
    
    RenderWindow window(VideoMode(MODE_WIDTH, MODE_HEIGHT), "Chess Game");
    Board board = Board();

    while (window.isOpen()) {
        Event evnt;
        while (window.pollEvent(evnt)) {
            

        }
    }
}
