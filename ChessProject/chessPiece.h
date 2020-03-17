#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>

#define ll long long

using namespace std;
using namespace sf;
class chessPiece
{
	string team;
	string type;
	pair<ll, ll> position;
	bool isAlive;

	pair<ll, ll> getPos();

	vector<pair<ll, ll>> getAvailableSquares();
	vector<pair<ll, ll>> getBishopSquares();
	vector<pair<ll, ll>> getKnightSquares();
	vector<pair<ll, ll>> getQueenSquares();
	vector<pair<ll, ll>> getPawnSquares();
	vector<pair<ll, ll>> getRookSquares();
	vector<pair<ll, ll>> getKingSquares();

};

