#pragma once
#include "chessPiece.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>

#define ll long long

using namespace std;
using namespace sf;

class getAvailableSquares
{

public:
	getAvailableSquares();
	chessPiece piece;
	Board board1;
	getAvailableSquares(chessPiece piece, Board board1);
	bool isValid(ll x, ll y);
	vector<pair<ll, ll>> getSquares();
	vector<pair<ll, ll>> getBishopSquares();
	vector<pair<ll, ll>> getKnightSquares();
	vector<pair<ll, ll>> getQueenSquares();
	vector<pair<ll, ll>> getPawnSquares();
	vector<pair<ll, ll>> getRookSquares();
	vector<pair<ll, ll>> getKingSquares();

};
