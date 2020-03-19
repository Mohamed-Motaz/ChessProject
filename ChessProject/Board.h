#pragma once
#include "chessPiece.h"
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>

#define ll long long

using namespace std;
using namespace sf;

class Board
{
public:
	chessPiece board[9][9];
	Board();
};