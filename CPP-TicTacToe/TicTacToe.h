#pragma once

#include "game.h"

class TicTacToe : public Game
{
public:
    TicTacToe();
    ~TicTacToe() {}

    bool IsGameOver() const override;
    void TakeTurn() override;
    void Display() const override;

private:
    char board[9];
    char playerTurn;
    bool gameOver;

    void SwitchPlayer();
    bool CheckWin() const;
    bool CheckDraw() const;
};
