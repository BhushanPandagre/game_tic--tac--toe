#include <iostream>

using namespace std;

const int size = 3;
char board[size][size];

// <---------------------------Function to initialize the board with empty spaces---------------------------------->
void bhushan()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// <--------------------------Function to draw the Tic-Tac-Toe board--------------------------------->
void drawBoard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "| ";
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl
             << "-------------" << endl;
    }
}

// <---------------------------Function to check if a player has won------------------------------------------------->
bool checkWin(char player)
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < size; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true; // Check diagonal (top-right to bottom-left)
    }
    return false;
}

int main()
{
    int row, col;
    char currentPlayer = 'X';
    bool gameover = false;

    bhushan();

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameover)
    {
        drawBoard();

        // <-----------------------Get player move-------------------------->
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // <-----------------Check if the selected position is valid and update the board----------------->
        if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;

            //  <--------------------Check if the current player has won----------------------->
            if (checkWin(currentPlayer))
            {
                drawBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                gameover = true;
            }
            else
            {
                //  <--------------------- Switch player------------------->
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else

        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
