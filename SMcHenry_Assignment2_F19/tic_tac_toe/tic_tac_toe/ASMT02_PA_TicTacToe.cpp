#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main()
{
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	displayBoard(board);

	while (true)
	{
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board))
		{
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board))
		{
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board))
		{
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board))
		{
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

// cout entire board to user
void displayBoard(char board[][3])
{
	cout << endl
			 << "-------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << '|' << ' ' << board[i][j] << ' ';
		}
		cout << '|' << endl
				 << "-------------" << endl;
	}
}

// allows the current player to make a move
void makeAMove(char board[][3], char player)
{
	int row;
	int column;

    // will continue to ask for move until it is a valid move
	while (true)
	{
		cout << "Enter a row (0, 1, 2) for player " << player << "    : ";
        // makes sure row is an int and between 0 and 2
		while(!(cin >> row) || !(row >= 0) || !(row <= 2)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter a row (0, 1, 2) for player " << player << "    : ";
		}
        // makes sure column is an int and between 0 and 2
		cout << "Enter a column (0, 1, 2) for player " << player << " : ";
		while(!(cin >> column) || !(column >= 0) || !(column <= 2)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter a column (0, 1, 2) for player " << player << " : ";
		}
        // makes sure the user did not attempt to make a move for a spot that is taken
		if (board[row][column] != ' ')
		{
			cout << "This cell is already occupied. Try a different cell" << endl;
			continue;
		}
		board[row][column] = player;
        // allows the loop to end
        break;
	}
};

// iterates over all possible winning position to dictate is a winning play has been made
bool isWon(char player, char board[][3])
{
    // checks over all rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == player &&
				board[i][1] == player &&
				board[i][2] == player)
		{
			return true;
		}
	}
    
    // checks over all columns
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == player &&
				board[1][i] == player &&
				board[2][i] == player)
		{
			return true;
		}
	}
    
    // checks diagonal from upper left to bottom right
	if (board[0][0] == player &&
			board[1][1] == player &&
			board[2][2] == player)
	{
		return true;
	}
    
    // checks diagonal from upper right to bottom left
	if (board[0][2] == player &&
			board[1][1] == player &&
			board[2][0] == player)
	{
		return true;
	}
	return false;
};

// checks if all spaces are filled without a winner to indicate a draw
bool isDraw(char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
};
