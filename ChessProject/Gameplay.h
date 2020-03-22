#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>
#include "getAvailableSquares.h"
#include "chessPiece.h"
#include "Board.h"

#define ll long long

using namespace std;
using namespace sf;

class Gameplay
{
private:
	Gameplay();
public:
	
	static bool IsValidPositionChange(pair<ll, ll> startingPosition, pair<ll, ll> targetPosition, Board board);

	static pair<pair<ll, ll>, pair<ll, ll>> InputStartingPositionAndTargetPosition();
	
	static Board MovePiece(pair<ll, ll> startingPosition, pair<ll, ll> targetPosition, Board board1);
};
