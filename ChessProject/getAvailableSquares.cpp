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
	if (piece.type == "Bishop") answer = getBishopSquares();
	if (piece.type == "Knight") answer = getKnightSquares();
	if (piece.type == "King") answer = getKingSquares();
	if (piece.type == "Queen") answer = getQueenSquares();
	if (piece.type == "Pawn") answer = getPawnSquares();
	if (piece.type == "Rook") answer = getRookSquares();
	return answer;
}

getAvailableSquares::getAvailableSquares(chessPiece piece, Board board1)
{
	this->piece = piece;
	this->board1 = board1;
}

bool getAvailableSquares::isValid(ll x, ll y) {

	return x >= 1 && x <= 8 && y >= 1 && y <= 8 && (board1.board[x][y].type.size() == 0 || board1.board[x][y].team != piece.team);
}

bool getAvailableSquares::isValidPawnSideWays(ll x, ll y) {

	return  (board1.board[x][y].team != piece.team && board1.board[x][y].team.size() != 0);
}

bool getAvailableSquares::isValidPawn(ll x, ll y) {
	return  (x >= 1 && x <= 8 && y >= 1 && y <= 8) && (board1.board[x][y].type.size() == 0);
}

//for following functions, u must check if coordinates are valid
//if path is blocked by a team member, u must stop before it
//if path is blocked by an opposite team member, u must count is as possible and then stop
//array to loop on is called board 

vector<pair<ll, ll>> getAvailableSquares::getBishopSquares() {
	//return a vector of all valid squares for the bishop
	//can move only diagonally
	vector<pair<ll, ll>> answer;

	int axis[] = { 1,-1 };

	for (int i = 0; i < 2; i++) {

		int xpos = piece.getPos().first + axis[i];

		for (int j = 0; j < 2; j++) {

			xpos = piece.getPos().first + axis[i];

			int ypos = piece.getPos().second + axis[j];

			while (isValid(xpos, ypos)) {

				answer.push_back({ xpos , ypos });

				if (board1.board[xpos][ypos].team != piece.team && board1.board[xpos][ypos].team.size() != 0)

					break;

				xpos += axis[i];

				ypos += axis[j];

			}

		}

	}
		return answer;

	
}

vector<pair<ll, ll>> getAvailableSquares::getKnightSquares() {
	//return a vector of all valid squares for the bishop
	//moves in an L shape, 2 steps, then 1 step perpindicular to the first step
	//can move in any direction
	vector<pair<ll, ll>> answer;

	if (isValid(piece.getPos().first - 1, piece.getPos().second - 2)) {

		answer.push_back({ piece.getPos().first - 1, piece.getPos().second - 2 });
	}
	if (isValid(piece.getPos().first + 1, piece.getPos().second - 2)) {

		answer.push_back({ piece.getPos().first + 1, piece.getPos().second - 2 });
	}
	if (isValid(piece.getPos().first + 1, piece.getPos().second + 2)) {

		answer.push_back({ piece.getPos().first + 1, piece.getPos().second + 2 });
	}
	if (isValid(piece.getPos().first - 1, piece.getPos().second + 2)) {

		answer.push_back({ piece.getPos().first - 1, piece.getPos().second + 2 });
	}
	if (isValid(piece.getPos().first + 2, piece.getPos().second - 1)) {

		answer.push_back({ piece.getPos().first + 2, piece.getPos().second - 1 });
	}
	if (isValid(piece.getPos().first - 2, piece.getPos().second + 1)) {

		answer.push_back({ piece.getPos().first - 2, piece.getPos().second + 1 });
	}
	if (isValid(piece.getPos().first - 2, piece.getPos().second - 1)) {

		answer.push_back({ piece.getPos().first - 2, piece.getPos().second - 1 });
	}
	if (isValid(piece.getPos().first + 2, piece.getPos().second + 1)) {

		answer.push_back({ piece.getPos().first + 2, piece.getPos().second + 1 });
	}

	return answer;
}

vector<pair<ll, ll>> getAvailableSquares::getQueenSquares() {
	//return a vector of all valid squares for the bishop
	//can move horizontally, vertically, and diagonaly
	vector<pair<ll, ll>> answer;

	int axis[] = { 1,-1 };


	for (int i = 0; i < 2; i++) {

		int xpos = piece.getPos().first + axis[i];

		while (isValid(xpos, piece.getPos().second)) {

			answer.push_back({ xpos , piece.getPos().second });

			if (board1.board[xpos][piece.getPos().second].team != piece.team && board1.board[xpos][piece.getPos().second].team.size() != 0)

				break;

			xpos += axis[i];

		}

		

		for (int j = 0; j < 2; j++) {

			xpos = piece.getPos().first + axis[i];

			int ypos = piece.getPos().second + axis[j];

			while (isValid(xpos, ypos)) {

				answer.push_back({ xpos , ypos });

				if (board1.board[xpos][ypos].team != piece.team && board1.board[xpos][ypos].team.size() != 0)

					break;

				xpos += axis[i];

				ypos += axis[j];

			}

		}

		  

		int ypos = piece.getPos().second + axis[i];

		while (isValid(piece.getPos().first, ypos)) {

			answer.push_back({ piece.getPos().first, ypos });

			if (board1.board[piece.getPos().first][ypos].team != piece.team && board1.board[piece.getPos().first][ypos].team.size() != 0)

				break;

			ypos += axis[i];
		}


	}

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
	ll yPos = piece.getPos().second, xPos = piece.getPos().first;
	if (piece.team == "White") {
		//cout << "WHITE ";
		if (piece.getPos().first == 7) {
			//cout << "IN FIRST IF ";
			while (true) {
				if (isValidPawnSideWays(xPos - 1, yPos - 1)) answer.push_back({ xPos - 1, yPos - 1 }); 
				if (isValidPawnSideWays(xPos - 1, yPos + 1)) answer.push_back({ xPos - 1, yPos + 1 }); 
				if (isValidPawn(xPos - 1, yPos)) answer.push_back({ xPos - 1, yPos }); else break;
				if (isValidPawn(xPos - 2, yPos)) answer.push_back({ xPos - 2, yPos }); else break;
				
				break;
			}
		}
		else {
			//cout << "IN SECOND ELSE";
			while (true) {
				if (isValidPawnSideWays(xPos - 1, yPos - 1)) answer.push_back({ xPos - 1, yPos - 1 }); 
				if (isValidPawnSideWays(xPos - 1, yPos + 1)) answer.push_back({ xPos - 1, yPos + 1 }); 
				if (isValidPawn(xPos - 1, yPos)) answer.push_back({ xPos - 1, yPos }); else break;
				
				break;
			}
		}
	}
	if (piece.team == "Black") {
		//cout << "BLACK ";
		if (piece.getPos().first == 2) {
			//cout << "IN THIRD IF ";
			while (true) {
				if (isValidPawnSideWays(xPos + 1, yPos + 1)) answer.push_back({ xPos + 1, yPos + 1 }); 
				if (isValidPawnSideWays(xPos + 1, yPos - 1)) answer.push_back({ xPos + 1, yPos - 1 });
				if (isValidPawn(xPos + 1, yPos)) answer.push_back({ xPos + 1, yPos }); else break;
				if (isValidPawn(xPos + 2, yPos)) answer.push_back({ xPos + 2, yPos }); else break;
				
				break;
			}
		}
		else {
			//cout << "IN FOURTH ELSE";
			while (true) {
				if (isValidPawnSideWays(xPos + 1, yPos - 1)) answer.push_back({ xPos + 1, yPos - 1 }); 
				if (isValidPawnSideWays(xPos + 1, yPos + 1)) answer.push_back({ xPos + 1, yPos + 1 });
				if (isValidPawn(xPos + 1, yPos)) answer.push_back({ xPos + 1, yPos }); else break;
				
				break;
			}
		}
	}

	return answer;
}

vector<pair<ll, ll>> getAvailableSquares::getRookSquares() {
	//return a vector of all valid squares for the bishop
	//can move vertically or horizontally
	vector<pair<ll, ll>> answer;

	int Xrook1 = piece.getPos().first + 1;
	int Xrook2 = piece.getPos().first - 1;
	int Yrook1 = piece.getPos().second + 1;
	int Yrook2 = piece.getPos().second - 1;
	while (isValid(Xrook1, piece.getPos().second)) {

		answer.push_back({ Xrook1 , piece.getPos().second });
		if (board1.board[Xrook1][piece.getPos().second].team != piece.team && board1.board[Xrook1][piece.getPos().second].team.size() != 0)
			break;
		Xrook1++;
	}
	while (isValid(Xrook2, piece.getPos().second)) {
		answer.push_back({ Xrook2 , piece.getPos().second });
		if (board1.board[Xrook2][piece.getPos().second].team != piece.team && board1.board[Xrook2][piece.getPos().second].team.size() != 0)
			break;

		Xrook2--;
	}
	while (isValid(piece.getPos().first, Yrook1)) {

		answer.push_back({ piece.getPos().first,Yrook1 });
		if (board1.board[piece.getPos().first][Yrook1].team != piece.team && board1.board[piece.getPos().first][Yrook1].team.size() != 0)
			break;
		Yrook1++;
	}
	while (isValid(piece.getPos().first, Yrook2)) {

		answer.push_back({ piece.getPos().first, Yrook2 });
		if (board1.board[piece.getPos().first][Yrook2].team != piece.team && board1.board[piece.getPos().first][Yrook2].team.size() != 0)
			break;
		Yrook2--;
	}

	return answer;
}

vector<pair<ll, ll>> getAvailableSquares::getKingSquares()
{
	//return a vector of all valid squares for the bishop
	//can move one square only anywhere
	vector<pair<ll, ll>> answer;
	vector<pair<ll, ll>> finalAnswer;
	int xaxis[] = { 1,1,1,-1,-1,-1,0,0 };
	int yaxis[] = { 1,0,-1,-1,1,0,1,-1 };
	for (int i = 0; i < 8; i++)
	{
		if (isValid(piece.getPos().first + xaxis[i], piece.getPos().second + yaxis[i]))
		{
			answer.push_back({ piece.getPos().first + xaxis[i],piece.getPos().second + yaxis[i] });
		}
	}
	
	/*vector<pair<ll, ll>> allAttackedSquares = kingCheckAllSquaresAttacked();
	for (auto elem1 : answer) {
		bool attacked = false;
		for (auto elem2 : allAttackedSquares) {
			if (elem2 == elem1) {
				cout << "oops: attacked " << elem1.first << " " << elem1.second << endl;
				attacked = true;
				break;
			}
		}
		if (!attacked) finalAnswer.push_back(elem1);
	}
	
	return finalAnswer;*/
	return answer;

}

//
//vector<pair<ll, ll>> getAvailableSquares::kingCheckAllSquaresAttacked() {
//	vector<pair<ll, ll>> answers;
//
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			//check if peice is a different team and make sure it isnt empty
//			if (board1.board[i][j].team != piece.team && board1.board[i][j].team.size() != 0 && board1.board[i][j].type != "King") {
//				getAvailableSquares getAvailable(board1.board[i][j], board1);
//				vector<pair<ll, ll>> sol = getAvailable.getSquares();
//				for (auto elem : sol) answers.push_back(elem);
//			}
//		}
//	}
//
//	return answers;
//}