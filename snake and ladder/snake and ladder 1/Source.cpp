#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
using namespace std;
struct players
{
	string playername;
	int score = 0;
	int fruits;
};
struct snake
{
	int headx, heady, tailx, taily;
};
struct ladder
{
	int topx, topy, bottomx, bottomy;
};
void input(int& num_players, int& level, players player[10]);
void snakeandladder(snake s[10], ladder l[10]);
void showboard(snake s[10], ladder l[10], int&level, int random[50]);
void fruits(int level, int random[50], int& length);
void showfruit(bool& fruit, bool& s, int m);
void score(int& num_players, players player[10], snake s[10], ladder l[10], int& level,int random[50],int& length);
void output(int& num_players, players player[10]);
void game(int& num_players, int& level, players player[10], snake s[10], ladder l[10], int random[50],int& length);
int main() {
	int length;
	int random[50];
	int num_players;
	int level;
	players player[10] = {};
	snake s[10] = {};
	ladder l[10] = {};
	input(num_players, level, player);
	game(num_players, level, player, s, l,random,length);
	system("pause");
	return 0;
}
void input(int& num_players, int& level, players player[10]) {
	cout << "\t\t\t\t\t" << "welcame in snake and ladder game" << "\t\t\t\t\t\n";
	cout << "How many players ?\n";
	cin >> num_players;
	do {
		if (num_players == 1) {
			cout << "you should play at least 2 player or more.......please enter number of player again \n";
			cin >> num_players;
		}
		else if (num_players > 10)
		{
			cout << "the maximum players number equal ten players \n ";
			cout << " How many players ?\n";
			cin >> num_players;
		}
		else if (num_players == 0)
		{
			cout << "you should play at least 2 player or more.......please enter number of player again \n";
			cin >> num_players;
		}

	} while (num_players == 1 || num_players > 10 || num_players == 0);

	for (int i = 0; i < num_players; i++)
	{
		cout << "please Enter the name of player" << i + 1 << "\n";
		cin >> player[i].playername;
	}
	cout << "please Enter the level\n for normal please Enter 1 \n for difficut please Enter 2 \n for very diffcult please Enter 3\n ";
	cin >> level;
	while (level != 1 && level != 2 && level != 3)
	{
		cout << " wrong answer please return \n";
		cout << "please Enter the level\n for normal please Enter 1 \n for difficut please Enter 2 \n for very diffcult please Enter 3 ";
		cin >> level;
	}


}
void snakeandladder(snake s[10], ladder l[10]) {

	int arr[10][10] = {};
	arr[9][9] = 1;
	for (int i = 0; i < 10; i++)
	{
		srand(time(NULL));

		s[i].headx = rand() % 10;
		s[i].heady = rand() % 10;
		s[i].tailx = rand() % 10;
		s[i].taily = rand() % 10;

		while (s[i].heady == s[i].taily)
		{
			s[i].heady = rand() % 10;
			s[i].taily = rand() % 10;

		}
		if (arr[s[i].heady][s[i].headx] == 0)
		{
			arr[s[i].heady][s[i].headx] = 1;

		}
		else
		{
			while (arr[s[i].heady][s[i].headx] == 1)
			{
				s[i].headx = rand() % 10;
				s[i].heady = rand() % 10;
			}
			arr[s[i].heady][s[i].headx] = 1;
		}

		if (arr[s[i].taily][s[i].tailx] == 0)
		{
			arr[s[i].taily][s[i].tailx] = 1;

		}
		else
		{
			while (arr[s[i].taily][s[i].tailx] == 1)
			{
				s[i].tailx = rand() % 10;
				s[i].taily = rand() % 10;
			}
			arr[s[i].taily][s[i].tailx] = 1;
		}
		if (s[i].taily>s[i].heady)
		{

			swap(s[i].taily, s[i].heady);
			swap(s[i].tailx, s[i].headx);

		}

		l[i].topx = rand() % 10;
		l[i].topy = rand() % 10;
		l[i].bottomx = rand() % 10;
		l[i].bottomy = rand() % 10;
		while (l[i].topy == l[i].bottomy)
		{
			l[i].topy = rand() % 10;
			l[i].bottomy = rand() % 10;

		}
		if (arr[l[i].topy][l[i].topx] == 0)
		{
			arr[l[i].topy][l[i].topx] = 1;

		}
		else
		{
			while (arr[l[i].topy][l[i].topx] == 1)
			{
				l[i].topx = rand() % 10;
				l[i].topy = rand() % 10;
			}
			arr[l[i].topy][l[i].topx] = 1;
		}

		if (arr[l[i].bottomy][l[i].bottomx] == 0)
		{
			arr[l[i].bottomy][l[i].bottomx] = 1;

		}
		else
		{
			while (arr[l[i].bottomy][l[i].bottomx] == 1)
			{
				l[i].bottomx = rand() % 10;
				l[i].bottomy = rand() % 10;
			}
			arr[l[i].bottomy][l[i].bottomx] = 1;
		}
		if (l[i].bottomy>l[i].topy)
		{

			swap(l[i].bottomy, l[i].topy);
			swap(l[i].bottomx, l[i].topx);

		}




	}

}
void showboard(snake s[10], ladder l[10], int& level, int random[50]) {

	int length;
	int Squares[10][10] = { { 1,2,3,4,5,6,7,8,9,10 },{ 11,12,13,14,15,16,17,18,19,20 },{ 21,22,23,24,25,26,27,28,29,30 },{ 31,32,33,34,35,36,37,38,39,40 },{ 41,42,43,44,45,46,47,48,49,50 },{ 51,52,53,54,55,56,57,58,59,60 },{ 61,62,63,64,65,66,67,68,69,70 },{ 71,72,73,74,75,76,77,78,79,80 },{ 81,82,83,84,85,86,87,88,89,90 },{ 91,92,93,94,95,96,97,98,99,100 } };
	cout << "__________________________________________________________________________________________________________________________________________________________________\n";
	int x;
	if (level == 1)
	{
		x = 5;
		length=50;

	}
	else if (level == 2)
	{
		x = 7;
		length = 35;
	}
	else if (level == 3)
	{
		x = 10;
		length = 20;
		
	}
	for (int i = 9; i >= 0; i--) {
		if (i % 2 == 1)
		{
			for (int j = 9; j >= 0; j--)
			{

				bool sh = false;               //show
				bool fruit = false;
				for (int c = 0; c < length; c++)
				{
					if (Squares[i][j] == random[c])
					{
						fruit = true;
					}
				}

				for (int m = 0; m < x; m++)
				{
					if (i == s[m].heady&&j == s[m].headx)
					{
						bool s = true;
						showfruit(fruit, s, m);
						sh = true;
						break;
					}
					else if (i == l[m].topy&&j == l[m].topx)
					{
						bool s = false;
						showfruit(fruit, s, m);
						sh = true;
						break;
					}
					else if (i == s[m].taily&&j == s[m].tailx)
					{
						bool s = true;
						showfruit(fruit, s, m);
						sh = true;
						break;
					}
					else if (i == l[m].bottomy&&j == l[m].bottomx)
					{
						bool s = false;
						showfruit(fruit, s, m);
						sh = true;
						break;
					}
				}
				if (sh == false) {
					if (fruit)
					{
						cout << " " << " " << " " << Squares[i][j] << "        . ";
						cout << "|";
					}
					else {
						cout << " " << " " << " " << Squares[i][j] << "\t\t";
						cout << "|";
					}
				}

			}


		}
		else
		{
			for (int j = 0; j < 10; j++)
			{

				bool sh = false;
				bool fruit = false;
				for (int c = 0; c < length; c++)
				{
					if (Squares[i][j] == random[c])
					{
						fruit = true;
					}
				}

				for (int m = 0; m < x; m++)
				{
					if (i == s[m].heady&&j == s[m].headx)
					{
						bool s = true;
						showfruit(fruit, s, m);
						sh = true;
						break;
					}
					else if (i == l[m].topy&&j == l[m].topx)
					{
						bool s = false;
						showfruit(fruit, s, m);
						sh = true;
						break;

					}
					else if (i == s[m].taily&&j == s[m].tailx)
					{
						bool s = true;
						showfruit(fruit, s, m);
						sh = true;
						break;
					}
					else if (i == l[m].bottomy&&j == l[m].bottomx)
					{
						bool s = false;
						showfruit(fruit, s, m);
						sh = true;
						break;

					}
				}
				if (sh == false) {
					if (fruit)
					{
						cout << " " << " " << " " << Squares[i][j] << "        . ";
						cout << "|";
					}
					else {
						cout << " " << " " << " " << Squares[i][j] << "\t\t";
						cout << "|";
					}
				}
			}
		}

		cout << endl;
		cout << "__________________________________________________________________________________________________________________________________________________________________\n";
	}

}
void score(int& num_players, players player[10], snake s[10], ladder l[10], int& level,int random[50],int& length) {
	int i = 0;
	int arr[10][10] = { { 1,2,3,4,5,6,7,8,9,10 },{ 11,12,13,14,15,16,17,18,19,20 },{ 21,22,23,24,25,26,27,28,29,30 },{ 31,32,33,34,35,36,37,38,39,40 },{ 41,42,43,44,45,46,47,48,49,50 },{ 51,52,53,54,55,56,57,58,59,60 },{ 61,62,63,64,65,66,67,68,69,70 },{ 71,72,73,74,75,76,77,78,79,80 },{ 81,82,83,84,85,86,87,88,89,90 },{ 91,92,93,94,95,96,97,98,99,100 } };
	do
	{
		bool found = false;
		int enter;
		int nrd;
		int x;
		for (i = 0; i < num_players; i++) {
			cout << player[i].playername << " throw the nrd\n";
			nrd = 1 + rand() % 6;
			int num;
			cout << "press num 1 for throw the nrd : " "";
			cin >> num;
			while (num != 1)
			{

				cout << "press the right number please : " "";
				cin >> num;
			}

			cout << nrd << "\n";
			srand(time(NULL));
			if (nrd == 1)
				player[i].score += 1;
			else if (nrd == 2)
				player[i].score += 2;
			else if (nrd == 3)
				player[i].score += 3;
			else if (nrd == 4)
				player[i].score += 4;
			else if (nrd == 5)
				player[i].score += 5;
			else if (nrd == 6)
				player[i].score += 6;
			system("cls");
			
			for (int  k = 0; k < length; k++)
			{
				if (player[i].score== random[k])
				{
					found = true;
					player[i].fruits++;
					random[k] = -5456;
				}

			}
			if (level == 1)
				x = 5;
			else if (level == 2)
				x = 7;
			else if (level == 3)
				x = 10;
			for (int n = 0; n < x; n++)
			{
				if (arr[s[n].heady][s[n].headx] == player[i].score)
					player[i].score = arr[s[n].taily][s[n].tailx];
				else if (arr[l[n].bottomy][l[n].bottomx] == player[i].score)
					player[i].score = arr[l[n].topy][l[n].topx];

			}
			showboard(s, l, level,random);
			for (int j = 0; j < num_players; j++) {
				cout << player[j].playername << "--> " << player[j].score << "\t"<<player[j].fruits<<"   is fruits \t\n";
				if (player[j].fruits >= 3)
				{
					cout << "you can play again if you need  press 2 or press 0 if you don't need \n ";
					cin >> enter;
					while (enter !=2&& enter !=0 )
					{
						cout << "enter a right answer ";
						cin >> enter;
					}
					if (enter==2)
					{
						player[j].fruits -= 3;
						i--;
					}
				}
			}


			if (player[i].score >= 100)
				break;

		}

	} while (player[i].score < 100);

}
void showfruit(bool& fruit, bool& s, int m) {
	if (s)
	{
		if (fruit)
		{
			cout << " " << " " << " " << "s" << m + 1 << "        . ";
			cout << "|";

		}
		else if (fruit == false)
		{
			cout << " " << " " << " " << "s" << m + 1 << "\t\t";
			cout << "|";

		}
	}
	else
	{

		if (fruit)
		{
			cout << " " << " " << " " << "l" << m + 1 << "        . ";
			cout << "|";

		}
		else if (fruit == false)
		{
			cout << " " << " " << " " << "l" << m + 1 << "\t\t";
			cout << "|";

		}
	}
}
void fruits(int level, int  randam[50], int& length) {

	srand(time(NULL));
	if (level == 1)
		length = 50;
	else if (level == 2)
		length = 35;
	else if (level == 3)
		length = 20;
	for (int i = 0; i < length; i++)
	{


		randam[i] = rand() % 100;
	}
}
void output(int& num_players, players player[10])
{   


	cout << "\n                       _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n";
	int win = 0;  int i = 0;
	for (int i = 0; i < num_players; i++) {
		if (player[i].score > win)
			win = player[i].score;
	}

	cout << "\n" << "win is    " <<	player[i].playername<< "\n" << "score" << "---->  " << win << "\n" << "End Game\n";
}
void game(int& num_players, int& level, players player[10], snake s[10] , ladder l[10], int random[50],int& length) {
	system("cls");
	snakeandladder(s, l);
	fruits(level, random, length);
	showboard(s, l, level,random);
	score(num_players, player, s, l, level,random,length);
	output(num_players, player);


}
