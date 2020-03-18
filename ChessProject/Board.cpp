#include "Board.h"
#include "chessPiece.h"
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>

#define ll long long

using namespace std;
using namespace sf;

Board::Board()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = chessPiece();
		}
	}
}
