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
public:
	string team;
	string type;
	pair<ll, ll> position;
	bool isAlive;

	pair<ll, ll> getPos();
	chessPiece(string team, string type, pair<ll, ll> position, bool isAlive);
	chessPiece();
};

