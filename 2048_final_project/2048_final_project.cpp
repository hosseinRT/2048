
#include <iostream>
#include <conio.h>
using namespace std;
void Meno();
int main()
{
	int Me;
	Meno();
	Me = _getch();
	return 0;


	
  
}
void list();
void Credits();
void Game();
void Meno()
{
	list();
	int ch;
	ch = _getch();
	system("cls");
	if (ch == '1')
		Game();
	if (ch == '2')
		Credits();
	if (ch == '3')
		cout<<"Good Bye";
}
void list()
{
	cout << "1. Start Game\n2. Credits\n3. Exit";
}
void Credits()
{
		cout << "Hossein Rahbartalab\n990122680021\n\nEnter the any key to return to the Meno";
		int input;

		input = _getch();
		system("cls");
		Meno();
	
}
void moveRight(int board[4][4])
{
	
	int i, j, Copyindex, last_right_Matrix_row;
	for (i = 0; i < 4; i++)
	{
		Copyindex = i, last_right_Matrix_row = 3;
		for (j = 2; j >= 0; j--)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j + 1] == 0 || board[i][j + 1] == board[i][j])
				{
					if (board[Copyindex][last_right_Matrix_row] == board[i][j])
					{
						board[Copyindex][last_right_Matrix_row] *= 2;
						board[i][j] = 0;
					}
					else
					{
						if (board[Copyindex][last_right_Matrix_row] == 0)
						{
							board[Copyindex][last_right_Matrix_row] = board[i][j];
							board[i][j] = 0;
						}
						else
						{
							board[Copyindex][--last_right_Matrix_row] = board[i][j];
							board[i][j] = 0;
						}
					}
				}
				else last_right_Matrix_row--;
			}
		}
	}
}
void moveLeft(int board[4][4])
{
	int i, j, copyindex, first_left_Matrix_row;
	for (i = 0; i < 4; i++)
	{
		copyindex = i, first_left_Matrix_row = 0;
		for (j = 1; j < 4; j++)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j - 1] == 0 || board[i][j - 1] == board[i][j])
				{
					if (board[copyindex][first_left_Matrix_row] == board[i][j])
					{
						board[copyindex][first_left_Matrix_row] *= 2;
						board[i][j] = 0;
					}
					else
					{
						if (board[copyindex][first_left_Matrix_row] == 0)
						{
							board[copyindex][first_left_Matrix_row] = board[i][j];
							board[i][j] = 0;
						}
						else
						{
							board[copyindex][++first_left_Matrix_row] = board[i][j];
							board[i][j] = 0;
						}
					}
				}
				else first_left_Matrix_row++;
			}
		}
	}

}
void moveDown(int board[4][4])
{
	int i, j, copyjindex, last_down_Matrix_column;
	for (j = 0; j < 4; j++)
	{
		 copyjindex = j,last_down_Matrix_column = 3;
		for (i = 2; i >= 0; i--)
		{
			if (board[i][j] != 0)
			{
				if (board[i + 1][j] == 0 || board[i + 1][j] == board[i][j])
				{
					if (board[last_down_Matrix_column][copyjindex] == board[i][j])
					{
						board[last_down_Matrix_column][copyjindex] *= 2;
						board[i][j] = 0;
					}
					else
					{
						if (board[last_down_Matrix_column][copyjindex] == 0)
						{
							board[last_down_Matrix_column][copyjindex] = board[i][j];
							board[i][j] = 0;
						}
						else
						{
							board[--last_down_Matrix_column][copyjindex] = board[i][j];
							board[i][j] = 0;
						}
					}
				}
				else last_down_Matrix_column--;
			}
		}
	}

}
void moveUp(int board[4][4])
{
	int i, j, first_down_Matrix_column, copyjindex;
	for (j = 0; j < 4; j++)
	{
		first_down_Matrix_column = 0, copyjindex = j;
		for (i = 1; i < 4; i++)
		{
			if (board[i][j] != 0)
			{
				if (board[i - 1][j] == 0 || board[i - 1][j] == board[i][j])
				{
					if (board[first_down_Matrix_column][copyjindex] == board[i][j])
					{
						board[first_down_Matrix_column][copyjindex] *= 2;
						board[i][j] = 0;
					}
					else
					{
						if (board[first_down_Matrix_column][copyjindex] == 0)
						{
							board[first_down_Matrix_column][copyjindex] = board[i][j];
							board[i][j] = 0;
						}
						else
						{
							board[++first_down_Matrix_column][copyjindex] = board[i][j];
							board[i][j] = 0;
						}
					}
				}
				else first_down_Matrix_column++;
			}
		}
	}

}
void render(int board[4][4])
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (board[i][j] != 0)
				cout << "[   " << board[i][j] << "   ]";
			else
				cout << "[       ]";
		cout << "\n";
	}
	int score;
	score = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)

			score += board[i][j];

	}
	cout<<"Score"<<": "<< score<<"\n";
	cout << "Move : [ W(up) D(right) S(down) A(left) ]\nExit : [ E ]";
}
void Random(int a[4][4])
{
	int index_random,jindex_random;
	srand(time(0));
	while (true)
	{
		index_random = rand() % 4;
		jindex_random = rand() % 4;
		if (a[index_random][jindex_random] == 0)
		{
			a[index_random][jindex_random] = 2;
			break;
		}
	}

}
int Board_different(int temp[4][4],int board[4][4])
{
	int  ِDifferent= 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (temp[i][j] != board[i][j])
			{
				ِDifferent = 1;
				break;
			}
	return  ِDifferent;

}
int GameOver(int board[4][4])
{
	int empty = 0, Two_houses_are_equal = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] == 0)
			{
				empty = 1;
				break;
			}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i + 1][j] == board[i][j] || board[i][j + 1] == board[i][j])
			{
				Two_houses_are_equal = 1;
				break;
			}

	if (empty || Two_houses_are_equal) return 0;
	else return 1;
}

void Game()
{
	int random_index1, random_index2, i, j;
	int board[4][4] = { 0 }, temp[4][4] = { 0 };
	srand(time(0));
	random_index1 = rand() % 4;
	random_index2 = rand() % 4;
	board[random_index1][random_index2] = 2;
	render(board);
	int Move;
	while (true)
	{
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				temp[i][j] = board[i][j];
		Move = _getch();
		system("cls");
		if (Move == 'w' || Move == 'W')
			moveUp(board);
		else if (Move == 's' || Move == 'S')
			moveDown(board);
		else if (Move == 'a' || Move == 'A')
			moveLeft(board);
		else if (Move == 'd' || Move == 'D')
			moveRight(board);
		else if (Move == 'e' || Move == 'E')
			break;
		else
		{
			cout << "!Eror";
			cout << "\n";
		}
		if (Board_different(temp,board))
			Random(board);
		render(board);

		if (GameOver(board))
		{
			cout << "Oops ! You lost You can try again";
			int End;
			End = _getch();
			break;

		}	
	}
}