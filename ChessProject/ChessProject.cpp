#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "chessPiece.h"
#include "getAvailableSquares.h"
#include "Gameplay.h"

//definitions
#define MODE_WIDTH 1299
#define MODE_HEIGHT 1000

using namespace std;
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(MODE_WIDTH, MODE_HEIGHT), "Chess Game");
    Board board1 = Board();
    Texture BackGround; BackGround.loadFromFile("textures/4774.png");
    Sprite back; back.setTexture(BackGround);
    Texture Pieces; Pieces.loadFromFile("textures/pieces.png");
    Sprite piece; piece.setTexture(Pieces); piece.setTextureRect(IntRect(100, 100, 100, 100)); piece.setPosition(100, 100);
    CircleShape validmove(12); validmove.setFillColor(Color::Blue);
    //White Pawns
    chessPiece Pawn1W = chessPiece("White", "Pawn", { 7,1 }, true); board1.board[Pawn1W.getPos().first][Pawn1W.getPos().second] = Pawn1W;
    chessPiece Pawn2W = chessPiece("White", "Pawn", { 7,2 }, true); board1.board[Pawn2W.getPos().first][Pawn2W.getPos().second] = Pawn2W;
    chessPiece Pawn3W = chessPiece("White", "Pawn", { 7,3 }, true); board1.board[Pawn3W.getPos().first][Pawn3W.getPos().second] = Pawn3W;
    chessPiece Pawn4W = chessPiece("White", "Pawn", { 7,4 }, true); board1.board[Pawn4W.getPos().first][Pawn4W.getPos().second] = Pawn4W;
    chessPiece Pawn5W = chessPiece("White", "Pawn", { 7,5 }, true); board1.board[Pawn5W.getPos().first][Pawn5W.getPos().second] = Pawn5W;
    chessPiece Pawn6W = chessPiece("White", "Pawn", { 7,6 }, true); board1.board[Pawn6W.getPos().first][Pawn6W.getPos().second] = Pawn6W;
    chessPiece Pawn7W = chessPiece("White", "Pawn", { 7,7 }, true); board1.board[Pawn7W.getPos().first][Pawn7W.getPos().second] = Pawn7W;
    chessPiece Pawn8W = chessPiece("White", "Pawn", { 7,8 }, true); board1.board[Pawn8W.getPos().first][Pawn8W.getPos().second] = Pawn8W;

    //Black Pawns
    chessPiece Pawn1B = chessPiece("Black", "Pawn", { 2,1 }, true); board1.board[Pawn1B.getPos().first][Pawn1B.getPos().second] = Pawn1B;
    chessPiece Pawn2B = chessPiece("Black", "Pawn", { 2,2 }, true); board1.board[Pawn2B.getPos().first][Pawn2B.getPos().second] = Pawn2B;
    chessPiece Pawn3B = chessPiece("Black", "Pawn", { 2,3 }, true); board1.board[Pawn3B.getPos().first][Pawn3B.getPos().second] = Pawn3B;
    chessPiece Pawn4B = chessPiece("Black", "Pawn", { 2,4 }, true); board1.board[Pawn4B.getPos().first][Pawn4B.getPos().second] = Pawn4B;
    chessPiece Pawn5B = chessPiece("Black", "Pawn", { 2,5 }, true); board1.board[Pawn5B.getPos().first][Pawn5B.getPos().second] = Pawn5B;
    chessPiece Pawn6B = chessPiece("Black", "Pawn", { 2,6 }, true); board1.board[Pawn6B.getPos().first][Pawn6B.getPos().second] = Pawn6B;
    chessPiece Pawn7B = chessPiece("Black", "Pawn", { 2,7 }, true); board1.board[Pawn7B.getPos().first][Pawn7B.getPos().second] = Pawn7B;
    chessPiece Pawn8B = chessPiece("Black", "Pawn", { 2,8 }, true); board1.board[Pawn8B.getPos().first][Pawn8B.getPos().second] = Pawn8B;

    //White Rooks
    chessPiece Rook1W = chessPiece("White", "Rook", { 8,1 }, true); board1.board[Rook1W.getPos().first][Rook1W.getPos().second] = Rook1W;
    chessPiece Rook2W = chessPiece("White", "Rook", { 8,8 }, true); board1.board[Rook2W.getPos().first][Rook2W.getPos().second] = Rook2W;

    //Black Rooks
    chessPiece Rook1B = chessPiece("Black", "Rook", { 1,1 }, true); board1.board[Rook1B.getPos().first][Rook1B.getPos().second] = Rook1B;
    chessPiece Rook2B = chessPiece("Black", "Rook", { 1,8 }, true); board1.board[Rook2B.getPos().first][Rook2B.getPos().second] = Rook2B;

    //White Bishops
    chessPiece Bishop1W = chessPiece("White", "Bishop", { 8,3 }, true); board1.board[Bishop1W.getPos().first][Bishop1W.getPos().second] = Bishop1W;
    chessPiece Bishop2W = chessPiece("White", "Bishop", { 8,6 }, true); board1.board[Bishop2W.getPos().first][Bishop2W.getPos().second] = Bishop2W;

    //Black Bishops
    chessPiece Bishop1B = chessPiece("Black", "Bishop", { 1,3 }, true); board1.board[Bishop1B.getPos().first][Bishop1B.getPos().second] = Bishop1B;
    chessPiece Bishop2B = chessPiece("Black", "Bishop", { 1,6 }, true); board1.board[Bishop2B.getPos().first][Bishop2B.getPos().second] = Bishop2B;

    //White Knights
    chessPiece Knight1W = chessPiece("White", "Knight", { 8,2 }, true); board1.board[Knight1W.getPos().first][Knight1W.getPos().second] = Knight1W;
    chessPiece Knight2W = chessPiece("White", "Knight", { 8,7 }, true); board1.board[Knight2W.getPos().first][Knight2W.getPos().second] = Knight2W;

    //Black Knights
    chessPiece Knight1B = chessPiece("Black", "Knight", { 1,2 }, true); board1.board[Knight1B.getPos().first][Knight1B.getPos().second] = Knight1B;
    chessPiece Knight2B = chessPiece("Black", "Knight", { 1,7 }, true); board1.board[Knight2B.getPos().first][Knight2B.getPos().second] = Knight2B;

    //White Queen
    chessPiece Queen1W = chessPiece("White", "Queen", { 8,4 }, true); board1.board[Queen1W.getPos().first][Queen1W.getPos().second] = Queen1W;

    //Black Queen
    chessPiece Queen1B = chessPiece("Black", "Queen", { 1,4 }, true); board1.board[Queen1B.getPos().first][Queen1B.getPos().second] = Queen1B;

    //White King
    chessPiece King1W = chessPiece("White", "King", { 8,5 }, true); board1.board[King1W.getPos().first][King1W.getPos().second] = King1W;

    //Black King
    chessPiece King1B = chessPiece("Black", "King", { 1,5 }, true); board1.board[King1B.getPos().first][King1B.getPos().second] = King1B;

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
        }
        */

        
        pair<pair<ll, ll>, pair<ll,ll>> positons;
        positons = Gameplay::InputStartingPositionAndTargetPosition();
        pair<ll, ll> startingPosition = positons.first, targetPosition = positons.second;
        if (Gameplay::IsValidPositionChange(startingPosition, targetPosition, board1)) {
            Gameplay::MovePiece(startingPosition, targetPosition, board1);
        }
        else {
            cout << "INVALID MOVE";
        }
        window.draw(back);
        // Kareem : drawing the pieces according their board positions
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (board1.board[i][j].type == "Pawn" && board1.board[i][j].team == "White")
                {
                    piece.setTextureRect(IntRect(100, 100, 100, 100));
                    piece.setPosition(100 * board1.board[i][j].getPos().second, 100 * board1.board[i][j].getPos().first);
                    window.draw(piece);
                }
                if (board1.board[i][j].type == "Pawn" && board1.board[i][j].team == "Black")
                {
                    piece.setTextureRect(IntRect(0, 200, 100, 100));
                    piece.setPosition(100 * board1.board[i][j].getPos().second, 100 * board1.board[i][j].getPos().first);
                    window.draw(piece);
                }

            }

        }


        window.draw(piece);
        window.display();
    }
}

/*


      getAvailableSquares getAvailable = getAvailableSquares(board1.board[i][j], board1);
          vector<pair<ll, ll>>  ans = getAvailable.getSquares();
          for (auto elem : ans)
          {
             validmove.setPosition(100 * elem.second + 38, 100 * elem.first + 38);
             window.draw(validmove);
          }


*/