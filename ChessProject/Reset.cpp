#include "Reset.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "chessPiece.h"
#include "getAvailableSquares.h"
#include "Gameplay.h"
//definitions
#define MODE_WIDTH 780
#define MODE_HEIGHT 600

using namespace std;
using namespace sf;
Reset rees;
bool Reset::restart(bool isSoundOn_restart, bool isSoundOff_restart)
{
	vector<pair<double, double>>Clik;
	pair<double, double>XY_clickpos;
	pair<double, double>valid_clickpos;
	RenderWindow window(VideoMode(MODE_WIDTH, MODE_HEIGHT), "Chess Game");
	Board board1 = Board();
	Texture BackGround; BackGround.loadFromFile("textures/Chess Board.png");
	Sprite back; back.setTexture(BackGround);
	Texture Pieces; Pieces.loadFromFile("textures/Pieces.png");
	Sprite piece; piece.setTexture(Pieces); piece.setTextureRect(IntRect(60, 60, 60, 60)); piece.setPosition(60, 60);
	CircleShape validmove(6); validmove.setFillColor(Color::Blue); validmove.setPosition(1000, 1000);
	Texture menu;	menu.loadFromFile("textures/Menu.png");
	Sprite menuu;	menuu.setTexture(menu);
	Texture soundon;	soundon.loadFromFile("textures/soundButton.png");
	Sprite SoundOn;	SoundOn.setTexture(soundon); SoundOn.setPosition(1000, 1000);
	Texture soundoff;	soundoff.loadFromFile("textures/soundOff.png");
	Sprite SoundOff;	SoundOff.setTexture(soundoff); SoundOff.setPosition(1000, 1000);
	bool icon = true, valid_disappear = false, issound_tab = false, ismenusetting = false, isSoundOff = isSoundOff_restart, isSoundOn = isSoundOn_restart;
	int counter = 0;
	//White Pawns
	chessPiece Pawn1W = chessPiece("White", "Pawn", { 7, 1 }, true); board1.board[Pawn1W.getPos().first][Pawn1W.getPos().second] = Pawn1W;
	chessPiece Pawn2W = chessPiece("White", "Pawn", { 7, 2 }, true); board1.board[Pawn2W.getPos().first][Pawn2W.getPos().second] = Pawn2W;
	chessPiece Pawn3W = chessPiece("White", "Pawn", { 7, 3 }, true); board1.board[Pawn3W.getPos().first][Pawn3W.getPos().second] = Pawn3W;
	chessPiece Pawn4W = chessPiece("White", "Pawn", { 7, 4 }, true); board1.board[Pawn4W.getPos().first][Pawn4W.getPos().second] = Pawn4W;
	chessPiece Pawn5W = chessPiece("White", "Pawn", { 7, 5 }, true); board1.board[Pawn5W.getPos().first][Pawn5W.getPos().second] = Pawn5W;
	chessPiece Pawn6W = chessPiece("White", "Pawn", { 7, 6 }, true); board1.board[Pawn6W.getPos().first][Pawn6W.getPos().second] = Pawn6W;
	chessPiece Pawn7W = chessPiece("White", "Pawn", { 7, 7 }, true); board1.board[Pawn7W.getPos().first][Pawn7W.getPos().second] = Pawn7W;
	chessPiece Pawn8W = chessPiece("White", "Pawn", { 7, 8 }, true); board1.board[Pawn8W.getPos().first][Pawn8W.getPos().second] = Pawn8W;

	//Black Pawns
	chessPiece Pawn1B = chessPiece("Black", "Pawn", { 2, 1 }, true); board1.board[Pawn1B.getPos().first][Pawn1B.getPos().second] = Pawn1B;
	chessPiece Pawn2B = chessPiece("Black", "Pawn", { 2, 2 }, true); board1.board[Pawn2B.getPos().first][Pawn2B.getPos().second] = Pawn2B;
	chessPiece Pawn3B = chessPiece("Black", "Pawn", { 2, 3 }, true); board1.board[Pawn3B.getPos().first][Pawn3B.getPos().second] = Pawn3B;
	chessPiece Pawn4B = chessPiece("Black", "Pawn", { 2, 4 }, true); board1.board[Pawn4B.getPos().first][Pawn4B.getPos().second] = Pawn4B;
	chessPiece Pawn5B = chessPiece("Black", "Pawn", { 2, 5 }, true); board1.board[Pawn5B.getPos().first][Pawn5B.getPos().second] = Pawn5B;
	chessPiece Pawn6B = chessPiece("Black", "Pawn", { 2, 6 }, true); board1.board[Pawn6B.getPos().first][Pawn6B.getPos().second] = Pawn6B;
	chessPiece Pawn7B = chessPiece("Black", "Pawn", { 2, 7 }, true); board1.board[Pawn7B.getPos().first][Pawn7B.getPos().second] = Pawn7B;
	chessPiece Pawn8B = chessPiece("Black", "Pawn", { 2, 8 }, true); board1.board[Pawn8B.getPos().first][Pawn8B.getPos().second] = Pawn8B;

	//White Rooks
	chessPiece Rook1W = chessPiece("White", "Rook", { 8, 1 }, true); board1.board[Rook1W.getPos().first][Rook1W.getPos().second] = Rook1W;
	chessPiece Rook2W = chessPiece("White", "Rook", { 8, 8 }, true); board1.board[Rook2W.getPos().first][Rook2W.getPos().second] = Rook2W;

	//Black Rooks
	chessPiece Rook1B = chessPiece("Black", "Rook", { 1, 1 }, true); board1.board[Rook1B.getPos().first][Rook1B.getPos().second] = Rook1B;
	chessPiece Rook2B = chessPiece("Black", "Rook", { 1, 8 }, true); board1.board[Rook2B.getPos().first][Rook2B.getPos().second] = Rook2B;

	//White Bishops
	chessPiece Bishop1W = chessPiece("White", "Bishop", { 8, 3 }, true); board1.board[Bishop1W.getPos().first][Bishop1W.getPos().second] = Bishop1W;
	chessPiece Bishop2W = chessPiece("White", "Bishop", { 8, 6 }, true); board1.board[Bishop2W.getPos().first][Bishop2W.getPos().second] = Bishop2W;

	//Black Bishops
	chessPiece Bishop1B = chessPiece("Black", "Bishop", { 1, 3 }, true); board1.board[Bishop1B.getPos().first][Bishop1B.getPos().second] = Bishop1B;
	chessPiece Bishop2B = chessPiece("Black", "Bishop", { 1, 6 }, true); board1.board[Bishop2B.getPos().first][Bishop2B.getPos().second] = Bishop2B;

	//White Knights
	chessPiece Knight1W = chessPiece("White", "Knight", { 8, 2 }, true); board1.board[Knight1W.getPos().first][Knight1W.getPos().second] = Knight1W;
	chessPiece Knight2W = chessPiece("White", "Knight", { 8, 7 }, true); board1.board[Knight2W.getPos().first][Knight2W.getPos().second] = Knight2W;

	//Black Knights
	chessPiece Knight1B = chessPiece("Black", "Knight", { 1, 2 }, true); board1.board[Knight1B.getPos().first][Knight1B.getPos().second] = Knight1B;
	chessPiece Knight2B = chessPiece("Black", "Knight", { 1, 7 }, true); board1.board[Knight2B.getPos().first][Knight2B.getPos().second] = Knight2B;

	//White Queen
	chessPiece Queen1W = chessPiece("White", "Queen", { 8, 4 }, true); board1.board[Queen1W.getPos().first][Queen1W.getPos().second] = Queen1W;

	//Black Queen
	chessPiece Queen1B = chessPiece("Black", "Queen", { 1, 4 }, true); board1.board[Queen1B.getPos().first][Queen1B.getPos().second] = Queen1B;

	//White King
	chessPiece King1W = chessPiece("White", "King", { 8, 5 }, true); board1.board[King1W.getPos().first][King1W.getPos().second] = King1W;

	//Black King
	chessPiece King1B = chessPiece("Black", "King", { 1, 5 }, true); board1.board[King1B.getPos().first][King1B.getPos().second] = King1B;
	while (true) {//While loop 3ashn lama ye3mel window.close() ye5sh tany fi loop el game
		while (window.isOpen()) {

			Event evnt;
			while (window.pollEvent(evnt)) {
				if (evnt.type == Event::Closed) {
					window.close();
				}

			}

			window.clear();
			//Kareem : I've commented that to work on the sfml
			/*
			for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
			if (board1.board[i][j].type.size() == 0) cout << "YAY";
			cout << board1.board[i][j].type << " ";
			}cout << endl;
			}
			for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
			getAvailableSquares getAvailable = getAvailableSquares(board1.board[i][j], board1);
			vector<pair<ll, ll>>  ans = getAvailable.getSquares();
			if (board1.board[i][j].type.size() == 0) continue;
			cout << board1.board[i][j].type << endl;
			cout << "Initial Position is: " << board1.board[i][j].getPos().first << " " << board1.board[i][j].getPos().second << endl;
			for (auto elem : ans) {
			cout << elem.first << " " << elem.second << endl;
			}
			}
			}*/
			/*pair<pair<ll, ll>, pair<ll, ll>> positons;
			positons = Gameplay::InputStartingPositionAndTargetPosition();
			pair<ll, ll> startingPosition = positons.first, targetPosition = positons.second;
			if (Gameplay::IsValidPositionChange(startingPosition, targetPosition, board1)) {
			board1 = Gameplay::MovePiece(startingPosition, targetPosition, board1);
			}
			else {
			cout << "INVALID MOVE" << endl;
			}*/
			//Kareem : window clicks
			Vector2i mousepos = Mouse::getPosition(window);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (mousepos.x > 698.514 && mousepos.x < 698.514 + 70 && mousepos.y>514 && mousepos.y < 514 + 70 && icon == true) {
					window.close(); rees.restart(isSoundOn, isSoundOff);
				}
				if (mousepos.x > 693.19 && mousepos.x < 693.19 + 75 && mousepos.y>19 && mousepos.y < 19 + 72 && icon == true) {
					icon = false;
				}
			}
			window.draw(menuu);
			if (Mouse::isButtonPressed(Mouse::Left) && icon == false && mousepos.x >= 290 && mousepos.x <= 460 && mousepos.y >= 330 && mousepos.y <= 390)
			{
				window.close();
			}

			if (Mouse::isButtonPressed(Mouse::Left) && icon == false && mousepos.x >= 290 && mousepos.x <= 460 && mousepos.y >= 215 && mousepos.y <= 274)
			{
				window.close(); rees.restart(isSoundOn, isSoundOff); icon = true;
			}

			// Sound Tabs
			if (Mouse::isButtonPressed(Mouse::Left) && isSoundOn == 1 && isSoundOff == 0 && icon == false && mousepos.x >= 677 && mousepos.x <= 745 && mousepos.y >= 109 && mousepos.y <= 177)
			{
				isSoundOn = 0;	isSoundOff = 1;
			}
			else if (Mouse::isButtonPressed(Mouse::Right) && isSoundOn == 0 && isSoundOff == 1 && icon == false && mousepos.x >= 677 && mousepos.x <= 745 && mousepos.y >= 109 && mousepos.y <= 177)
			{
				isSoundOn = 1;	isSoundOff = 0;
			}

			if (isSoundOff == 0 && isSoundOn == 1 && icon == false)
			{
				SoundOn.setPosition(677, 109);	window.draw(SoundOn);
			}
			else if (isSoundOn == 0 && isSoundOff == 1 && icon == false)
			{
				SoundOff.setPosition(677, 109); window.draw(SoundOff);
			}

			if (icon)
			{
				window.clear();
				window.draw(back);
				for (int i = 1; i < 9; i++) {
					for (int j = 1; j < 9; j++) {
						if (board1.board[i][j].type.size() == 0) continue;
						if (board1.board[i][j].type == "Pawn" && board1.board[i][j].team == "White")
						{
							piece.setTextureRect(IntRect(120, 60, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Pawn" && board1.board[i][j].team == "Black")
						{
							piece.setTextureRect(IntRect(0, 120, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Queen" && board1.board[i][j].team == "White")
						{
							piece.setTextureRect(IntRect(180, 0, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);

						}
						if (board1.board[i][j].type == "Queen" && board1.board[i][j].team == "Black")
						{
							piece.setTextureRect(IntRect(180, 180, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "King" && board1.board[i][j].team == "White")
						{
							piece.setTextureRect(IntRect(240, 0, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "King" && board1.board[i][j].team == "Black")
						{
							piece.setTextureRect(IntRect(240, 180, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Knight" && board1.board[i][j].team == "White")
						{
							piece.setTextureRect(IntRect(60, 0, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Knight" && board1.board[i][j].team == "Black")
						{
							piece.setTextureRect(IntRect(60, 180, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Bishop" && board1.board[i][j].team == "White")
						{
							piece.setTextureRect(IntRect(120, 0, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Bishop" && board1.board[i][j].team == "Black")
						{
							piece.setTextureRect(IntRect(120, 180, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Rook" && board1.board[i][j].team == "White")
						{
							piece.setTextureRect(IntRect(0, 0, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}
						if (board1.board[i][j].type == "Rook" && board1.board[i][j].team == "Black")
						{
							piece.setTextureRect(IntRect(0, 180, 60, 60));
							piece.setPosition(60 * board1.board[i][j].getPos().second, 60 * board1.board[i][j].getPos().first);
							window.draw(piece);
						}


					}

				}

				// Kareem : drawing the pieces according their board positions


				if (Mouse::isButtonPressed(Mouse::Right)) {
					valid_disappear = false;
					Clik.clear();
					for (int i = 1; i < 9; i++) {
						for (int j = 1; j < 9; j++) {
							if (mousepos.x > 60 * board1.board[i][j].getPos().second && mousepos.x < 60 * board1.board[i][j].getPos().second + 60 &&
								mousepos.y > 60 * board1.board[i][j].getPos().first && mousepos.y < 60 * board1.board[i][j].getPos().first + 60)
							{
								XY_clickpos.first = i; XY_clickpos.second = j;
								getAvailableSquares getAvailable = getAvailableSquares(board1.board[i][j], board1);
								vector<pair<ll, ll>>  ans = getAvailable.getSquares();
								chessPiece currentPiece = board1.board[(int)XY_clickpos.first][(int)XY_clickpos.second];
								if (counter % 2 == 0 && currentPiece.team != "White") break;
								if (counter % 2 != 0 && currentPiece.team != "Black") break;
								for (auto elem : ans)
								{
									Clik.push_back({ 60 * elem.second + 25, 60 * elem.first + 25 });
									validmove.setPosition(60 * elem.second + 25, 60 * elem.first + 25);
									window.draw(validmove);
								}
							}
						}
					}

				}

				if (!Mouse::isButtonPressed(Mouse::Right) && valid_disappear == false) {
					for (int i = 0; i < Clik.size(); i++) {
						validmove.setPosition(Clik[i].first, Clik[i].second);
						window.draw(validmove);
					}
				}

				if (Mouse::isButtonPressed(Mouse::Left))
				{
					valid_disappear = true;
					cout << "yayayaya" << endl;
					getAvailableSquares getAvailable = getAvailableSquares(board1.board[(int)XY_clickpos.first][(int)XY_clickpos.second], board1);
					vector<pair<ll, ll>>  ans = getAvailable.getSquares();
					cout << ans.size() << endl;
					for (auto elem : ans)
					{
						if (mousepos.x > 60 * elem.second && mousepos.x < 60 * elem.second + 60 && mousepos.y > 60 * elem.first && mousepos.y < 60 * elem.first + 60)
						{
							chessPiece currentPiece = board1.board[(int)XY_clickpos.first][(int)XY_clickpos.second];
							if (counter % 2 == 0 && currentPiece.team != "White") break;
							if (counter % 2 != 0 && currentPiece.team != "Black") break;
							valid_clickpos.first = elem.first; valid_clickpos.second = elem.second;
							board1 = Gameplay::MovePiece({ XY_clickpos.first, XY_clickpos.second }, { valid_clickpos.first, valid_clickpos.second }, board1);
							cout << valid_clickpos.first << "  " << valid_clickpos.second << endl;
							for (int x = 1; x <= 8; x++) {
								for (int z = 1; z <= 8; z++) {
									/*if (board1.board[x][z].team.size() == 0) {
									cout << "yay "; continue;
									}*/
									cout << board1.board[x][z].position.first << board1.board[x][z].position.second << ' ';
								}cout << endl;

							}
							counter++;
						}
					}
				}
				//if (Mouse::isButtonPressed(Mouse::Left)) { XY_clickpos.first = 0; XY_clickpos.second = 0; }

				window.draw(piece);
			}
			window.display();

		}
	}
}

//modification for each paste "bool icon = true" , "res---> rees"x2
