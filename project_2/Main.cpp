#include<iostream>
#include "XOGame.cpp"
using namespace std;

/*class XOGame { // first try by fady
	void PrintNet(char ArrayPrintT[9])
	{
		int Count = 1;
		for (int i = 0; i < 9; i++)
		{
			cout << " " << ArrayPrintT[i] << " ";
			if (Count != 3 && Count != 6 && Count != 9)
				cout << "|";
			if (Count == 3 || Count == 6)
				cout << "\n" << "~~~~~~~~~~~" << "\n";
			Count++;
		}
	}

	void PrintPlayerTurn(int RoundPlayed) {
		if (RoundPlayed % 2 == 0)
			cout << "\nX Is Playing";
		else
			cout << "\nO Is Playing";
	}

	void FillXO(int Site, int CountPlay, char ArrayPrint[9])
	{
		if (CountPlay % 2 == 0)
		{
			ArrayPrint[Site - 1] = 'O';
		}
		else
		{
			ArrayPrint[Site - 1] = 'X';
		}
	}

	int CheckCondition(char ArrayPrint[9], int CountPlay)
	{
		int WhoWin;

		if (CountPlay % 2 != 0)
			WhoWin = 1;
		else
			WhoWin = 2;

		if (ArrayPrint[0] == ArrayPrint[1] && ArrayPrint[1] == ArrayPrint[2])
		{
			return WhoWin;
		}
		else if (ArrayPrint[3] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[5])
		{
			return WhoWin;
		}
		else if (ArrayPrint[6] == ArrayPrint[7] && ArrayPrint[7] == ArrayPrint[8])
		{
			return WhoWin;
		}
		else if (ArrayPrint[0] == ArrayPrint[3] && ArrayPrint[3] == ArrayPrint[6])
		{
			return WhoWin;
		}
		else if (ArrayPrint[1] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[7])
		{
			return WhoWin;
		}
		else if (ArrayPrint[2] == ArrayPrint[5] && ArrayPrint[5] == ArrayPrint[8])
		{
			return WhoWin;
		}
		else if (ArrayPrint[0] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[8])
		{
			return WhoWin;
		}
		else if (ArrayPrint[2] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[6])
		{
			return WhoWin;
		}

		return WhoWin = 0;
	}

	int GetIntergerInput(string validationMessage) {
		int userInput;
		do
		{
			cin >> userInput;
			if (!cin.fail()) break;
			else {
				cout << "\n" << validationMessage << "\n";
				cin.clear();
				cin.ignore(123, '\n');
			}

		} while (true);

		return userInput;
	}

public: int main2()
{
	bool RoundEnded = false;
	int CountXWin = 0;
	int CountOWin = 0;
	int RoundPlayed = 0;
	char ArrayPrint[] = { '1', '2', '3', '4', '5' ,'6', '7', '8', '9' };
	char DefaulArray[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	while (true)
	{
		system("cls");
		cout << "X O Game" << "\n";
		PrintNet(ArrayPrint);
		cout << "\nX wins:(" << CountXWin << "), O wins:(" << CountOWin << ")";

		if (RoundEnded) {
			cout << "\nEnter 1 To Playing again, Enter 0 To Stop.\n";
			int PlayAgain;
			cin >> PlayAgain;

			if (cin.fail() || PlayAgain != 1) {
				// Exit Game!
				break;
			}
			else {
				// Reset game
				RoundEnded = false;
				RoundPlayed = 0;

				//  i am here
				std::copy(std::begin(DefaulArray), std::end(DefaulArray), std::begin(ArrayPrint));
				continue;
			}
		}

		PrintPlayerTurn(RoundPlayed);

		cout << "\n" << "Please Enter The Site Which You Want From 1 To 9" << "\n";
		int Site = GetIntergerInput("You Entered A String!");

		if (Site < 1 || Site > 9) {
			continue;
		}
		else if (ArrayPrint[Site - 1] == 'X' || ArrayPrint[Site - 1] == 'O') {
			cout << "This Site Has Already Been entered \n";
		}
		else {
			RoundPlayed++;
			FillXO(Site, RoundPlayed, ArrayPrint);
		}

		int WhoWon = CheckCondition(ArrayPrint, RoundPlayed);

		if (WhoWon == 1 || WhoWon == 2 || RoundPlayed == 9) {
			RoundEnded = true;

			if (WhoWon == 1) {
				CountXWin++;
			}
			else if (WhoWon == 2) {
				CountOWin++;
			}
		}
	}
	return 0;
}
};*/


/* class XOByLee  //first try by leemor
{
	void PrintNet(char ArrayPrintT[9])
	{
		int Count = 1;
		for (int i = 0; i < 9; i++)
		{
			cout << " " << ArrayPrintT[i] << " ";
			if (Count != 3 && Count != 6 && Count != 9)
				cout << "|";
			if (Count == 3 || Count == 6)
				cout << "\n" << "~~~~~~~~~~~" << "\n";
			Count++;
		}
	}
	void FillXO(int Site, int CountPlay, char ArrayPrint[9])
	{
		if (CountPlay % 2 == 0)
		{

			ArrayPrint[Site - 1] = 'O';
		}
		else
		{
			ArrayPrint[Site - 1] = 'X';
		}
	}
	int CheckCondition(char ArrayPrint[9], int CountPlay)
	{
		int WhoWin;

		if (CountPlay % 2 != 0)
			WhoWin = 1;
		else
			WhoWin = 2;
		if (ArrayPrint[0] == ArrayPrint[1] && ArrayPrint[1] == ArrayPrint[2])
		{
			return WhoWin;
		}
		else if (ArrayPrint[3] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[5])
		{
			return WhoWin;
		}
		else if (ArrayPrint[6] == ArrayPrint[7] && ArrayPrint[7] == ArrayPrint[8])
		{
			return WhoWin;
		}
		else if (ArrayPrint[0] == ArrayPrint[3] && ArrayPrint[3] == ArrayPrint[6])
		{
			return WhoWin;
		}
		else if (ArrayPrint[1] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[7])
		{
			return WhoWin;
		}
		else if (ArrayPrint[2] == ArrayPrint[5] && ArrayPrint[5] == ArrayPrint[8])
		{
			return WhoWin;
		}
		else if (ArrayPrint[0] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[8])
		{
			return WhoWin;
		}
		else if (ArrayPrint[2] == ArrayPrint[4] && ArrayPrint[4] == ArrayPrint[6])
		{
			return WhoWin;
		}
		return WhoWin = 0;
	}
public:  int main3()
{
	int AgainPlaying;
	int CountXWin = 0;
	int CountOWin = 0;

	do
	{
		cout << "X O Game" << "\n";
		char ArrayPrint[9] = { '1','2','3','4','5','6','7','8','9' };
		PrintNet(ArrayPrint);

		for (int CountPlay = 1; CountPlay < 10; CountPlay++)
		{
			if (CountPlay % 2 != 0)
				cout << "\nX Is Playing";
			else
				cout << "\nO Is Playing";
			int Site;
		AgainSite:
			cout << "\n" << "Please Enter The Site Which You Want From 1 To 9" << "\n";
			try
			{
				if (!(cin >> Site))
				{
					cout << "\nYou Entered A String";
					cin.clear();
					cin.ignore(123, '\n');
					goto AgainSite;
				}
				cin.ignore(123, ' ');
				if (Site < 1 || Site > 9)
					goto AgainSite;
				if (ArrayPrint[Site - 1] == 'X' || ArrayPrint[Site - 1] == 'O')
					throw"This Site Has Already Been entered \n";

			}
			catch (const char* ErrorMessage)
			{
				cout << "EXCEPTION : " << ErrorMessage;
				goto AgainSite;
			}
			system("cls");
			FillXO(Site, CountPlay, ArrayPrint);
			PrintNet(ArrayPrint);
			if (CountPlay > 4)
			{
				int x = CheckCondition(ArrayPrint, CountPlay);
				if (x == 1)
				{
					CountXWin++;
					break;
				}
				else if (x == 2)
				{
					CountOWin++;
					break;
				}
			}
		}
		do
		{
			cout << "\nDo You Want Play Again. Enter 1 To Playing, Enter 0 To Stop.";
			cin >> AgainPlaying;
			system("cls");
		} while (AgainPlaying != 1 && AgainPlaying != 0);

	} while (AgainPlaying);
	cout << "X :" << CountXWin << " " << CountOWin << ": O";
	if (CountXWin > CountOWin)
		cout << "\nX Is Winner";
	else if (CountOWin > CountXWin)
		cout << "\nO Is Winner";
	else
		cout << "\nNo One Is Winner";
	return 0;
}
};
*/

int main()
{
	//XOByLee FirstLee;
	//FirstLee.main3();

	//XOGame FirstFady;
	//FirstFady.main2();
	cout << "leemorrrrrrrrr";
	XOGame SecondLeemor;
	SecondLeemor.main2();
	cout << "leeeeeeeeeeemor";
}