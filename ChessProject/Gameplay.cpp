#include "Gameplay.h"
#include "getAvailableSquares.h"
#include "chessPiece.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>>

Gameplay::Gameplay() {

}

bool Gameplay::IsValidPositionChange(pair<ll, ll> startingPosition, pair<ll, ll> targetPosition, Board board1)
{
	if (board1.board[targetPosition.first][targetPosition.second].type.size() == 0) cout << "EMPTY SPACE" << endl;
	getAvailableSquares  getAvailable = getAvailableSquares(board1.board[startingPosition.first][startingPosition.second], board1);

	vector<pair<ll, ll>>  ans = getAvailable.getSquares();

	for (auto elem : ans) {
		cout << elem.first << " " << elem.second << endl;
		if (elem.first == targetPosition.first && elem.second == targetPosition.second) {

			return true;
		}
	}
	return false;
}

pair<pair<ll, ll>, pair<ll, ll>> Gameplay::InputStartingPositionAndTargetPosition()
{
	pair<ll, ll> StartingPosition, TargetPosition;

	cout << "Please enter the position of the piece you want to move" << endl;

	cin >> StartingPosition.first >> StartingPosition.second;

	cout << "Please enter the position you want the piece to move to" << endl;

	cin >> TargetPosition.first >> TargetPosition.second;

	return { StartingPosition, TargetPosition };
}

Board Gameplay::MovePiece(pair<ll, ll> startingPosition, pair<ll, ll> targetPosition, Board board1)
{
	chessPiece currentPiece = board1.board[startingPosition.first][startingPosition.second];

	//Case 2 of checkmate: Move to attacked position
	if (currentPiece.type == "King") {
		string kingTeam = currentPiece.team;
		
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				chessPiece tmp = board1.board[i][j];
				if (tmp.type.size() != 0 && tmp.team != kingTeam) {
					getAvailableSquares getAvailable(tmp, board1);
					vector<pair<ll, ll>> positions = getAvailable.getSquares();
					for (auto elem : positions) {

						if (elem.first == targetPosition.first && elem.second == targetPosition.second) {
							
							//checkmate
							board1.board[startingPosition.first][startingPosition.second].isAlive = false;
							return board1;
							//###############################################################################################################################################################################
							//##################################################################################MUST CHECK IF KING IS DEAD###################################################################
							//###############################################################################################################################################################################
						}
					}
				}
			}
		}
	}
	board1.board[startingPosition.first][startingPosition.second] = chessPiece();
	board1.board[targetPosition.first][targetPosition.second] = currentPiece;
	currentPiece.position = { targetPosition.first, targetPosition.second };

	return board1;
}

bool Gameplay::isKingCheckmated(pair<ll, ll> currentPosition, Board board1)
{
	string kingTeam = board1.board[currentPosition.first][currentPosition.second].team;
	//Case 1: King is attacked
	//		  No available squares
	//		  No piece can block the attack
	
	//Case 2: King moves to attacked position
	//implemented in MovePiece method

	//Case 3: Only king can attack piece BUT piece is defended
	//already taken care of
	return false;
}

