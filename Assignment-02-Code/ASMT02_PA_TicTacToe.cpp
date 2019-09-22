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

void makeAMove(char board[][3], char player)
{
	int row;
	int column;
	bool isValid = false;

	while (!isValid)
	{
		cout << "Enter a row (0, 1, 2) for player " << player << "    : ";
		cin >> row;
		cout << "Enter a column (0, 1, 2) for player " << player << " : ";
		cin >> column;
		if (board[row][column] != ' ')
		{
			cout << "This cell is already occupied. Try a different cell" << endl;
			continue;
		}
		board[row][column] = player;
		isValid = true;
	}
};

bool isWon(char player, char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == player &&
				board[i][1] == player &&
				board[i][2] == player)
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == player &&
				board[1][i] == player &&
				board[2][i] == player)
		{
			return true;
		}
	}
	if (board[0][0] == player &&
			board[1][1] == player &&
			board[2][2] == player)
	{
		return true;
	}
	if (board[0][2] == player &&
			board[1][1] == player &&
			board[2][0] == player)
	{
		return true;
	}
	return false;
};

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