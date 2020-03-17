#include "chessPiece.h"
#include "Board.h"
#include "getAvailableSquares.h"
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>

#define ll long long

using namespace std;
using namespace sf;


chessPiece::chessPiece(string team, string type,pair<ll, ll> position, bool isAlive)
{
	this->team = team;
	this->type = type;
	this->position = position;
	this->isAlive = isAlive;
}

chessPiece::chessPiece()
{
}
	
pair<ll, ll> chessPiece::getPos()
{
	return pair<ll, ll>();
}


	

