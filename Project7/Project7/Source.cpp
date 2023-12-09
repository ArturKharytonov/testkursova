#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "Game.h"

using namespace std;


//class CheckersAI {
//public:
//    static Move generateMove(const CheckersGame& game, Player currentPlayer, bool isHardLevel) {
//        std::vector<Move> possibleMoves = getAvailableMoves(game, currentPlayer);
//
//        if (possibleMoves.empty()) {
//            return Move{};
//        }
//
//        if (!isHardLevel) {
//            srand(static_cast<unsigned int>(time(0)));
//            int randomIndex = rand() % possibleMoves.size();
//            return possibleMoves[randomIndex];
//        }
//
//        // ������������� �������� ������ � ������� ��� ���������� ������� ����
//        Move bestMove = depthFirstSearch(game, currentPlayer, 3);  // ������� ������ - 3
//
//        return bestMove;
//    }
//
//private:
//    static Move depthFirstSearch(const CheckersGame& game, Player currentPlayer, int depth) {
//        std::vector<Move> possibleMoves = getAvailableMoves(game, currentPlayer);
//
//        if (possibleMoves.empty() || depth == 0) {
//            // ������� ����������� ������� ��� ���� ��������� ����, �������� ���� ���
//            // � ��������� ������ ��� �� ������� (�������� ������� ������ - ���������� ���)
//            srand(static_cast<unsigned int>(time(0)));
//            int randomIndex = rand() % possibleMoves.size();
//            return possibleMoves[randomIndex];
//        }
//
//        Move bestMove;
//        int bestScore = std::numeric_limits<int>::min();
//
//        for (const Move& move : possibleMoves) {
//            // ������ ���
//            CheckersGame newGame = game;
//            newGame.makeMove(move);
//
//            // ���������� ��������� ����� � ������� ��� ���������� ������
//            Move opponentMove = depthFirstSearch(newGame, getOpponent(currentPlayer), depth - 1);
//
//            // �������� ���� ��� (����� ������ ���� ������ ����)
//            int score = evaluateBoard(newGame, currentPlayer) + evaluateMove(move);
//
//            // ���� �������� ������� - ������������, ������� ��� � �������� �������
//            // ���� �������� ������� - �����������, ������� ��� � ��������� �������
//            if ((currentPlayer == Player::WHITE && score > bestScore) ||
//                (currentPlayer == Player::BLACK && score < bestScore)) {
//                bestScore = score;
//                bestMove = move;
//            }
//        }
//
//        return bestMove;
//    }
//
//    // ��������� ������ getAvailableMoves, evaluateBoard �� evaluateMove, �� ��� ������ ��� ���� ���.
//    // getOpponent - �� ������ �������� ������� ��� ��������� �������� ������.
//    // ������ ����� ����������� � ��������� �� ���������� ������ ���.
//    // � �������� ������� �� ������ ��������������� �������� ������.
//};



int main() {
    Game game;

    game.startGame();

    cout << "Game over!" << endl;
    return 0;
}


