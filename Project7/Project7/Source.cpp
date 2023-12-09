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
//        // ¬икористовуЇмо алгоритм пошуку в глибину дл€ визначенн€ кращого ходу
//        Move bestMove = depthFirstSearch(game, currentPlayer, 3);  // √либина пошуку - 3
//
//        return bestMove;
//    }
//
//private:
//    static Move depthFirstSearch(const CheckersGame& game, Player currentPlayer, int depth) {
//        std::vector<Move> possibleMoves = getAvailableMoves(game, currentPlayer);
//
//        if (possibleMoves.empty() || depth == 0) {
//            // ƒос€гли максимальноњ глибини або немаЇ доступних ход≥в, оц≥нюЇмо стан гри
//            // ≥ повертаЇмо кращий х≥д за оц≥нкою (поточний простий вар≥ант - випадковий х≥д)
//            srand(static_cast<unsigned int>(time(0)));
//            int randomIndex = rand() % possibleMoves.size();
//            return possibleMoves[randomIndex];
//        }
//
//        Move bestMove;
//        int bestScore = std::numeric_limits<int>::min();
//
//        for (const Move& move : possibleMoves) {
//            // –обимо х≥д
//            CheckersGame newGame = game;
//            newGame.makeMove(move);
//
//            // –екурсивно викликаЇмо пошук в глибину дл€ наступного гравц€
//            Move opponentMove = depthFirstSearch(newGame, getOpponent(currentPlayer), depth - 1);
//
//            // ќц≥нюЇмо стан гри (зараз просто сума оц≥нок ход≥в)
//            int score = evaluateBoard(newGame, currentPlayer) + evaluateMove(move);
//
//            // якщо поточний гравець - максим≥зуючий, обираЇмо х≥д з найвищою оц≥нкою
//            // якщо поточний гравець - миним≥зуючий, обираЇмо х≥д з найменшою оц≥нкою
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
//    // –еал≥зуйте методи getAvailableMoves, evaluateBoard та evaluateMove, €к≥ вам потр≥бн≥ дл€ вашоњ гри.
//    // getOpponent - це просто допом≥жна функц≥€ дл€ отриманн€ опонента гравц€.
//    // ќц≥нки можна обчислювати в залежност≥ в≥д конкретних правил гри.
//    // ” простому випадку ви можете використовувати випадков≥ оц≥нки.
//};



int main() {
    Game game;

    game.startGame();

    cout << "Game over!" << endl;
    return 0;
}


