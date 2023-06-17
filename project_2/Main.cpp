#include<iostream>
using namespace std;

void PrintNet(char arrayPRINT[9])
{
	int count = 1;
	for (int i = 0; i < 9; i++)
	{
		cout << " " << arrayPRINT[i] << " ";
		if (count != 3 && count != 6 && count != 9)
			cout << "|";
		if (count == 3 || count == 6)
			cout << "\n" << "~~~~~~~~~~~" << "\n";
		count++;
	}
}
void FillXO(int site, int CountPlay, char arrayPRINT[9])
{
	if (CountPlay % 2 == 0)
	{

		arrayPRINT[site-1] = 'O';
	}
	else
	{
		arrayPRINT[site - 1] = 'X';
	}
}
int checkCondition(char arrayPRINT[9] , int CountPlay)
{
	char Win;
	int x = 1;
	int i = 0;
	if (CountPlay % 2 != 0)
		Win = 'X';
	else
		Win = 'O';

	if (arrayPRINT[i] == arrayPRINT[i + 1] && arrayPRINT[i + 1] == arrayPRINT[i + 2])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else if (arrayPRINT[i + 3] == arrayPRINT[i + 4] && arrayPRINT[i + 4] == arrayPRINT[i + 5])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else if (arrayPRINT[i + 6] == arrayPRINT[i + 7] && arrayPRINT[i + 7] == arrayPRINT[i + 8])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else if (arrayPRINT[i + 0] == arrayPRINT[i + 3] && arrayPRINT[i + 3] == arrayPRINT[i + 6])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else if (arrayPRINT[i + 1] == arrayPRINT[i + 4] && arrayPRINT[i + 4] == arrayPRINT[i + 7])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else if (arrayPRINT[i + 2] == arrayPRINT[i + 5] && arrayPRINT[i + 5] == arrayPRINT[i + 8])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else if (arrayPRINT[i + 0] == arrayPRINT[i + 4] && arrayPRINT[i + 4] == arrayPRINT[i + 8])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else if (arrayPRINT[i + 2] == arrayPRINT[i + 4] && arrayPRINT[i + 4] == arrayPRINT[i + 6])
	{
		cout << "\n" << Win << "  is Winner";
	}
	else
		x = 0;
	return x;
}

int main()
{
	char arrayPRINT[9] = {'1','2','3','4','5','6','7','8','9'};
	PrintNet(arrayPRINT);

	for (int CountPlay = 1; CountPlay < 10; CountPlay++)
	{
		int site;
		AgainSite :
		cout << "\n" << "please enter the site which you want from 1 to 9" << "\n";
		cin >> site;
		if (site < 1 || site > 9)
			goto AgainSite;
		if (arrayPRINT[site - 1] == 'X' || arrayPRINT[site - 1] == 'O')
			goto AgainSite;
		system("cls");
		FillXO(site, CountPlay, arrayPRINT);
		PrintNet(arrayPRINT);
		if (CountPlay > 4)
		{
			int x = checkCondition(arrayPRINT, CountPlay);
			if (x == 1)
				break;
		}
		if (CountPlay == 9)
		{
			cout << "\n" << " no one is winner";
		}
	}
	return 0;
}