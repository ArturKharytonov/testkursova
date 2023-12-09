#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "PieceEnum.h"
#include <array>
#include "Field.h"
#include "PlayerEnum.h"
#include <string>

using namespace std;

class Game
{
private:
    Field field;
    bool step = true;// if true goes first player otherwise second
public:
    Game() {}

    void startGame() {
        bool isEnd = false;
        int cordX;
        int cordY;
        int toMoveX;
        int toMoveY;

        while (!isEnd) {
            field.printBoard();
            string currentPlayer = step ? "First player" : "Bot step";

            if (step) {
                do
                {
                    cout << currentPlayer + " choose your checker" << endl;

                    cout << "Enter cord x: ";
                    cin >> cordX;

                    cout << "Enter cord y: ";
                    cin >> cordY;

                } while (!areValidCords(cordX, cordY) || !doesCordBelongsToUser(cordX, cordY));

                do
                {
                    cout << currentPlayer + " choose where u would like to make step" << endl;

                    cout << "Enter cord x: ";
                    cin >> toMoveX;

                    cout << "Enter cord y: ";
                    cin >> toMoveY;

                } while (!areValidCords(cordX, cordY) || !field.doesProperStep(cordX, cordY, toMoveX, toMoveY, step));
            }
            else {
                // bot step
            }

            field.makeStepForUser(cordX, cordY, toMoveX, toMoveY);

            step = !step;
        }
    }

    bool doesCordBelongsToUser(int x, int y) {
        PieceEnum piece;
        PieceEnum king;

        if (step) {
            piece = PieceEnum::FirstPlayerPiece;
            king = PieceEnum::FirstPlayerKing;
        }
        else {
            piece = PieceEnum::SecondPlayerPiece;
            king = PieceEnum::SecondPlayerKing;
        }
        return field.board[x][y] == piece || field.board[x][y] == king;
    }

    bool areValidCords(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }


    bool hasCycle(int v, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path, int& flag) {
        if (flag == 1) return true; // якщо вже знайшли цикл, то повертаємо true
        else {
            visited[v] = 1; // відзначаємо вершину як відвідану
            path.push_back(v); // додаємо її в порядок обходу графа
            for (int i = 0; i < graph[v].size(); i++) {
                int to = graph[v][i]; // наступна вершина графа
                if (visited[to] == 1) { // якщо ми її вже відвідали, але не вийшли з неї, значить, ми знайшли цикл
                    path.push_back(to); // додаємо наступну вершину в порядок обходу графа
                    flag = 1; // ставимо індикатор, що ми знайшли цикл
                    return true;
                }
                else if (visited[to] == 0 && hasCycle(to, graph, visited, path, flag)) {

                    return true;
                }
            }
            visited[v] = 2; // якщо не знайшли цикл, то виходимо з вершини
            path.pop_back();
        }
        return false;
    }

    bool isValidMove() {
        
        // Визначення графу для перевірки циклів
        vector<vector<int>> graph(8 * 8);
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (areValidCords(i, j)) {

                    if (areValidCords(i - 1, j - 1)) {
                        graph[i * boardSize + j].push_back((i - 1) * boardSize + (j - 1));
                    }
                    if (areValidCords(i - 1, j + 1)) {
                        graph[i * boardSize + j].push_back((i - 1) * boardSize + (j + 1));
                    }
                    if (areValidCords(i + 1, j - 1)) {
                        graph[i * boardSize + j].push_back((i + 1) * boardSize + (j - 1));
                    }
                    if (areValidCords(i + 1, j + 1)) {
                        graph[i * boardSize + j].push_back((i + 1) * boardSize + (j + 1));
                    }

                }
            }
        }

        // Ініціалізація для DFS
        int flag = 0;
        vector<int> visited(boardSize * boardSize, 0);
        vector<int> path;

        // Перевірка циклів перед додаванням нового ходу
        if (hasCycle(fromRow * boardSize + fromCol, graph, visited, path, flag)) {
            return false; // Якщо є цикл, хід недопустимий
        }


        // Приклад: перевірка, чи можна ходити лише на порожні клітинки
        if (board[toRow][toCol] != EMPTY) {
            return false; // клітинка не порожня
        }

        // Приклад: перевірка, чи можна взяти фішку противника (рухаючись по діагоналі на дві клітини)
        if (abs(toRow - fromRow) == 2) {
            int capturedRow = (toRow + fromRow) / 2;
            int capturedCol = (toCol + fromCol) / 2;
            Piece capturedPiece = board[capturedRow][capturedCol];

            if (currentPlayer == PLAYER1 && (capturedPiece == PLAYER2_PIECE || capturedPiece == PLAYER2_KING)) {
                // Можна взяти фішку противника
                // Додайте логіку видалення фішки противника (capturedPiece) з дошки
                return true;
            }
            else if (currentPlayer == PLAYER2 && (capturedPiece == PLAYER1_PIECE || capturedPiece == PLAYER1_KING)) {
                // Можна взяти фішку противника
                // Додайте логіку видалення фішки противника (capturedPiece) з дошки
                return true;
            }
        }

        // Якщо всі перевірки пройшли успішно, повертаємо true
        return true;
    }



    //bool isGameOver() {
    //    bool player1HasPieces = false;
    //    bool player2HasPieces = false;

    //    // Перевірка наявності фішок у гравців
    //    for (int i = 0; i < boardSize; ++i) {
    //        for (int j = 0; j < boardSize; ++j) {
    //            if (board[i][j] == PLAYER1_PIECE || board[i][j] == PLAYER1_KING) {
    //                player1HasPieces = true;
    //            }
    //            else if (board[i][j] == PLAYER2_PIECE || board[i][j] == PLAYER2_KING) {
    //                player2HasPieces = true;
    //            }
    //        }
    //    }


    //    if (!player1HasPieces) {
    //        cout << "Player 1 wins!" << endl;
    //        return true;
    //    }
    //    else if (!player2HasPieces) {
    //        cout << "Player 2 wins!" << endl;
    //        return true;
    //    }

    //    return false;
    //}
};

