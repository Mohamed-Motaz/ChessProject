#include "Board.h"
#include "chessPiece.h"
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>

#define ll long long

using namespace std;
using namespace sf;

static Board* singleBoard;

Board::Board() {
	
}

Board &Board::Instance()
{
	if (!singleBoard) {
		singleBoard = new Board();
	}
	return *singleBoard;
}

