#include "chessPiece.h"
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
	

	chessPiece(string team, string type,pair<ll, ll> position, bool isAlive)
	{
		this->team = team;
		this->type = type;
		this->position = position;
		this->isAlive = isAlive;
	}
	public:
		pair<ll, ll> getPos() {
			return position;
		}
		vector<pair<ll, ll>> getAvailableSquares() {

			if (type == "bishop") getBishopSquares();
			
			if (type == "knight") getKnightSquares();
			
			if (type == "king") getQueenSquares();
			
			if (type == "queen") getPawnSquares();
			
			if (type == "pawn") getRookSquares();
			
			if (type == "rook") getKingSquares();
			
		}
	private:
		bool isValid(ll x, ll y) {
			return x >= 1 && x <= 8 && y >= 1 && y <= 8;
		}

		//for following functions, u must check if coordinates are valid
		//if path is blocked by a team member, u must stop before it
		//if path is blocked by an opposite team member, u must count is as possible and then stop

		vector<pair<ll, ll>> getBishopSquares() {
			//return a vector of all valid squares for the bishop
			//can move only diagonally

		}
		vector<pair<ll, ll>> getKnightSquares() {
			//return a vector of all valid squares for the bishop
			//moves in an L shape, 2 steps, then 1 step perpindicular to the first step
			//can move in any direction
		}
		vector<pair<ll, ll>> getQueenSquares() {
			//return a vector of all valid squares for the bishop
			//can move horizontally, vertically, and diagonaly
		}
		vector<pair<ll, ll>> getPawnSquares() {
			//return a vector of all valid squares for the bishop
			
			//if first move for pawn, pawn can move two squares to the front
			//decide if first move based on position on board. 
			//if team black then position must b 7
			//if team white then position must b 2
			//can move only forward
		}
		vector<pair<ll, ll>> getRookSquares() {
			//return a vector of all valid squares for the bishop
			//can move vertically or horizontally
		}
		vector<pair<ll, ll>> getKingSquares() {
			//return a vector of all valid squares for the bishop
			//can move one square only anywhere
		}
};
