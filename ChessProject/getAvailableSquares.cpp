#include "getAvailableSquares.h"
#include "chessPiece.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
#include <sfml/Graphics.hpp>

#define ll long long

using namespace std;
using namespace sf;

getAvailableSquares::getAvailableSquares()
{
}

vector<pair<ll, ll>> getAvailableSquares::getSquares() {
	
	vector<pair<ll, ll>> answer;
	if (piece.type == "bishop") answer = getBishopSquares();
	if (piece.type == "knight") answer = getKnightSquares();
	if (piece.type == "king") answer = getQueenSquares();
	if (piece.type == "queen") answer = getPawnSquares();
	if (piece.type == "pawn") answer = getRookSquares();
	if (piece.type == "rook") answer = getKingSquares();
	return answer;
}
getAvailableSquares::getAvailableSquares(chessPiece piece, Board board)
{
	this->piece = piece;
	this->board = board;
}
bool getAvailableSquares::isValid(ll x, ll y) {
	return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

//for following functions, u must check if coordinates are valid
//if path is blocked by a team member, u must stop before it
//if path is blocked by an opposite team member, u must count is as possible and then stop
//array to loop on is called board 

vector<pair<ll, ll>> getAvailableSquares::getBishopSquares() {
	//return a vector of all valid squares for the bishop
	//can move only diagonally
	vector<pair<ll, ll>> answer;

	return answer;

}
vector<pair<ll, ll>> getAvailableSquares::getKnightSquares() {
	//return a vector of all valid squares for the bishop
	//moves in an L shape, 2 steps, then 1 step perpindicular to the first step
	//can move in any direction
	vector<pair<ll, ll>> answer;

	return answer;
}
vector<pair<ll, ll>> getAvailableSquares::getQueenSquares() {
	//return a vector of all valid squares for the bishop
	//can move horizontally, vertically, and diagonaly
	vector<pair<ll, ll>> answer;

	return answer;
}
vector<pair<ll, ll>> getAvailableSquares::getPawnSquares() {
	//return a vector of all valid squares for the bishop
	//if first move for pawn, pawn can move two squares to the front
	//decide if first move based on position on board. 
	//if team black then position must b 7
	//if team white then position must b 2
	//can move only forward
	vector<pair<ll, ll>> answer;
	if (piece.team == "white") {
		if (piece.getPos().first == 7) {
			answer.push_back({ piece.getPos().first - 1, piece.getPos().second });
			answer.push_back({ piece.getPos().first - 2, piece.getPos().second });
		}
	}
	if (piece.team == "black") {
		if (piece.getPos().first == 2) {
			answer.push_back({ piece.getPos().first + 1, piece.getPos().second });
			answer.push_back({ piece.getPos().first + 2, piece.getPos().second });
		}
	}
	return answer;
}
vector<pair<ll, ll>> getAvailableSquares::getRookSquares() {
	//return a vector of all valid squares for the bishop
	//can move vertically or horizontally
	vector<pair<ll, ll>> answer;

	return answer;
}
vector<pair<ll, ll>> getAvailableSquares::getKingSquares() {
	//return a vector of all valid squares for the bishop
	//can move one square only anywhere
	vector<pair<ll, ll>> answer;

	return answer;
}
