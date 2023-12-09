#pragma once
#include <iostream>
#include "PieceEnum.h"
#include <array>
#include "PieceEnum.h"
using namespace std;

class Field
{
public:
	array<array<PieceEnum, 8>, 8> board;
    const int size = 8;
	Field()
	{
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(i < 3 && ((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0))){
                    board[i][j] = PieceEnum::SecondPlayerPiece;
                }
                else if (i > 4 && ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))) {
                    board[i][j] = PieceEnum::FirstPlayerPiece;
                }
                else {
                    board[i][j] = PieceEnum::EMPTY;
                }
            }
        }
	}

    void printBoard() {
        cout << "   0   1   2   3   4   5   6   7" << endl;
        for (int i = 0; i < size; i++) {
            cout << i;
            cout << " ";
            for (int j = 0; j < size; j++) {
                switch (board[i][j]) {
                    case PieceEnum::EMPTY:
                        cout << "|.|";
                        break;
                    case PieceEnum::FirstPlayerPiece:
                        cout << "|X|";
                        break;
                    case PieceEnum::SecondPlayerPiece:
                        cout << "|O|";
                        break;
                    case PieceEnum::FirstPlayerKing:
                        cout << "|-|";
                        break;
                    case PieceEnum::SecondPlayerKing:
                        cout << "|*|";
                        break;
                }
                cout << " ";
            }
            cout << endl;
        }
    }

    bool doesProperStep(int cordX, int cordY, int toMoveX, int toMoveY, bool step) {
        int whereToMove = step ? -1 : 1;

        return (cordX + whereToMove == toMoveX &&
            (cordY + whereToMove == toMoveY ||
                cordY - whereToMove == toMoveY) &&
            board[toMoveX][toMoveY] == PieceEnum::EMPTY);
    }

    void makeStepForUser(int cordX, int cordY, int toMoveX, int toMoveY) {
        PieceEnum piece = board[cordX][cordY];
        board[cordX][cordY] = PieceEnum::EMPTY;
        board[toMoveX][toMoveY] = piece;
    }
};

