#include "Gameplay.h"
#include "getAvailableSquares.h"
#include "chessPiece.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>>
#include "Reset.h"

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

Board Gameplay::MovePiece(pair<ll, ll> startingPosition, pair<ll, ll> targetPosition, Board board1, ll counter)
{
	chessPiece currentPiece = board1.board[startingPosition.first][startingPosition.second];

	////CheckMate
	if (currentPiece.type == "King") {
		//Case 2 of checkmate: Move to attacked position
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
							cout << "CHECKMATYEEEEEEEEEEEEEEEEEEEEEE" << endl;
							board1.board[startingPosition.first][startingPosition.second].isAlive = false;
							//Kareem : the checkmate window law 3ayz el 2byd 5aly el sora "whiteWin"
							Reset checkres;
							RenderWindow CheckMate(VideoMode(650, 459), "CHESS-THE GAME OF KINGS");
							Texture Checkmate;	
							if (counter % 2 == 0)
								Checkmate.loadFromFile("textures/blackWin.png");
							else
								Checkmate.loadFromFile("textures/whiteWin.png");
							Sprite checkmate;	checkmate.setTexture(Checkmate);
							while (CheckMate.isOpen()) {
								CheckMate.clear(); CheckMate.draw(checkmate); CheckMate.display();
								Vector2i mousepos = Mouse::getPosition(CheckMate);
								if (Mouse::isButtonPressed(Mouse::Left) && mousepos.x > 119 && mousepos.x < 297 && mousepos.y>339 && mousepos.y < 398)
								{
									CheckMate.close();  checkres.restart(1, 0);
								}
								if (Mouse::isButtonPressed(Mouse::Left) && mousepos.x > 337 && mousepos.x < 519 && mousepos.y>338 && mousepos.y < 397)
								{
									CheckMate.close();
								}
							}
							//return board1;
							//###############################################################################################################################################################################
							//##################################################################################MUST CHECK IF KING IS DEAD###################################################################
							//###############################################################################################################################################################################
						}
					}
				}
			}
		}

		
	}
	//Case 1 of checkmate!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	chessPiece king;
	cout << "currentpeice team: " << currentPiece.type << " : " << currentPiece.team << endl;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (board1.board[i][j].type == "King" && board1.board[i][j].team != currentPiece.team) {
				king = board1.board[i][j];
				break;
			}
		}
	}
	cout << "KINGSSSS    " << king.type << " " << king.team << endl;

	bool attacked = false;
	int attackers = 0;
	//king is attacked
	vector<pair<ll, ll>> ans1;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			//chessPiece currentPiece = board1.board[i][j];
			if (board1.board[i][j].team != king.team && board1.board[i][j].type.size() != 0) {
				getAvailableSquares getAvailable(board1.board[i][j], board1);
				ans1.clear();
				ans1 = getAvailable.getSquares();
				cout << ans1.size() << endl;
				for (auto elem : ans1) {
					if (elem.first == king.position.first && elem.second == king.position.second) {
						attacked = true;
						attackers++;
						break;
					}
				}
			}
		}
	}
	
	if (!attacked) {
		//return board1; //false no checkmate
	}
	//get available squares fir king
	getAvailableSquares getAvailable(king, board1);
	vector<pair<ll, ll>> ans = getAvailable.getSquares();
	int numberofUnavaliable = 0;
	for (auto elem : ans) {
		bool notAvaliable = false;
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				chessPiece currentPiece = board1.board[i][j];
				if (currentPiece.team != king.team && currentPiece.team.size() != 0) {
					cout << "PIECEEEEEEEEEEEEEEEE: " << currentPiece.team << ": " << currentPiece.type << endl;
					getAvailableSquares getAvailable(currentPiece, board1);
					vector<pair<ll, ll>> answer = getAvailable.getSquares();
					cout << "ans size: " << ans.size() << endl;
					cout << ans[0].first << " "<< ans[0].second << endl;
					
					for (auto elemen : answer) {
						if (elemen.first == elem.first && elemen.second == elem.second) {
							cout << "innnnnnnnnnnnnnnnnnnnnnnnnnn" << endl;
							notAvaliable = true;
							numberofUnavaliable++;
							break;
						}
					}
				}
			}
		}
		if (notAvaliable)
			numberofUnavaliable++;
	}
	cout << "NUMBER UNAVILABLE = " << numberofUnavaliable << "    ans.size " << ans.size() << "   attackers : "<< attackers << endl;
	if (numberofUnavaliable == ans.size() && attackers > 1) {
		cout << "CHECKMATYEEEEEEEEEEEEEEEEEEEEEE" << endl;
		//return board1; //true, checkmate occured
		//Kareem : the checkmate window law 3ayz el 2byd 5aly el sora "whiteWin"
		Reset checkres;
		RenderWindow CheckMate(VideoMode(650, 459), "CHESS-THE GAME OF KINGS");
		Texture Checkmate;	Checkmate.loadFromFile("textures/blackWin.png");
		Sprite checkmate;	checkmate.setTexture(Checkmate);
		while (CheckMate.isOpen()) {
			CheckMate.clear(); CheckMate.draw(checkmate); CheckMate.display();
			Vector2i mousepos = Mouse::getPosition(CheckMate);
			if (Mouse::isButtonPressed(Mouse::Left) && mousepos.x > 119 && mousepos.x < 297 && mousepos.y>339 && mousepos.y < 398)
			{
				CheckMate.close();  checkres.restart(1, 0);
			}
			if (Mouse::isButtonPressed(Mouse::Left) && mousepos.x > 337 && mousepos.x < 519 && mousepos.y>338 && mousepos.y < 397)
			{
				CheckMate.close();
			}
		}
		//////
	}
	cout << "starting position for piece " << currentPiece.team << " " << currentPiece.type << " is " << startingPosition.first << " " << startingPosition.second << endl;
	cout << "target position is " << targetPosition.first << " " << targetPosition.second << endl;
	board1.board[startingPosition.first][startingPosition.second] = chessPiece();
	board1.board[targetPosition.first][targetPosition.second].isAlive = currentPiece.isAlive;
	board1.board[targetPosition.first][targetPosition.second].team = currentPiece.team;
	board1.board[targetPosition.first][targetPosition.second].type = currentPiece.type;
	board1.board[targetPosition.first][targetPosition.second].position.first = targetPosition.first;
	board1.board[targetPosition.first][targetPosition.second].position.second = targetPosition.second;
	cout << "PIECE IS NOW MOVED" << endl;
	return board1;
}


bool Gameplay::isKingCheckmated(pair<ll, ll> startingPosition, pair<ll, ll> targetPosition, Board board1)
{
	cout << "YAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAy" << endl;
	//chessPiece currentPiece = board1.board[startingPosition.first][startingPosition.second];
	//Case 1: King is attacked
	//		  No available squares
	//		  No piece can block the attack


	//Case 2: King moves to attacked position
	//implemented in MovePiece method
	//cout << "innnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn" << endl;
	//if (currentPiece.type == "King") {
	//	string kingTeam = currentPiece.team;

	//	for (int i = 1; i <= 8; i++) {
	//		for (int j = 1; j <= 8; j++) {
	//			chessPiece tmp = board1.board[i][j];
	//			if (tmp.type.size() != 0 && tmp.team != kingTeam) {
	//				cout << "in" << endl;
	//				getAvailableSquares getAvailable(tmp, board1);
	//				vector<pair<ll, ll>> positions = getAvailable.getSquares();
	//				for (auto elem : positions) {

	//					if (elem.first == targetPosition.first && elem.second == targetPosition.second) {
	//						cout << "oooooooooooooooooooooooooooooooops";
	//						//checkmate
	//						//board1.board[startingPosition.first][startingPosition.second].isAlive = false;
	//						return true;
	//						//###############################################################################################################################################################################
	//						//##################################################################################MUST CHECK IF KING IS DEAD###################################################################
	//						//###############################################################################################################################################################################
	//					}
	//				}
	//			}
	//		}
	//	}
	//}



	//Case 3: Only king can attack piece BUT piece is defended
	//already taken care of
	return false;
}

