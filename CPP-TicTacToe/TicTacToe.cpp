#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe()
{
    playerTurn = 'X';
    gameOver = false;

    for (int i = 0; i < 9; i++)
    {
        board[i] = '0' + i; // fill board with '0' to '8'
    }
}

bool TicTacToe::IsGameOver() const
{
    return gameOver;
}

void TicTacToe::TakeTurn()
{
    int move;

    std::cout << "Player " << playerTurn << ", enter a position (0-8): ";
    std::cin >> move;

    if (move < 0 || move > 8 || board[move] == 'X' || board[move] == 'O')
    {
        std::cout << "You Cant Move There. Try again: ";
        std::cin >> move;
    }

    board[move] = playerTurn;

    if (CheckWin())
    {
        std::cout << "Player " << playerTurn << " wins!\n";
        gameOver = true;
    }
    else if (CheckDraw())
    {
        std::cout << "It's a draw!\n";
        gameOver = true;
    }
    else
    {
        SwitchPlayer();
    }
}

void TicTacToe::Display() const
{
    std::cout << "\n";
    std::cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "--|---|--\n";
    std::cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "--|---|--\n";
    std::cout << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

void TicTacToe::SwitchPlayer()
{
    if (playerTurn == 'X')
        playerTurn = 'O';
    else
        playerTurn = 'X';
}

bool TicTacToe::CheckWin() const
{
    // Rows
    if (board[0] == playerTurn && board[1] == playerTurn && board[2] == playerTurn) return true;
    if (board[3] == playerTurn && board[4] == playerTurn && board[5] == playerTurn) return true;
    if (board[6] == playerTurn && board[7] == playerTurn && board[8] == playerTurn) return true;

    // Columns
    if (board[0] == playerTurn && board[3] == playerTurn && board[6] == playerTurn) return true;
    if (board[1] == playerTurn && board[4] == playerTurn && board[7] == playerTurn) return true;
    if (board[2] == playerTurn && board[5] == playerTurn && board[8] == playerTurn) return true;

    // Diagonals
    if (board[0] == playerTurn && board[4] == playerTurn && board[8] == playerTurn) return true;
    if (board[2] == playerTurn && board[4] == playerTurn && board[6] == playerTurn) return true;

    return false;
}


bool TicTacToe::CheckDraw() const
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    }
    return true;
}
