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
private:
    /* Here will be the instance stored. */
    

    /* Private constructor to prevent instancing. */
   Board();

public:
    /* Static access method. */
    static Board &Instance();
    chessPiece board[9][9];
};
