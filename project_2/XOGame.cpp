#include<iostream>
using namespace std;

class XOGame {
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

  public: int main()
  {
	  //jjjj
	bool RoundEnded = false;
	int CountXWin = 0;
	int CountOWin = 0;
	int RoundPlayed = 0;
	//char ArrayPrint[] = { '1', '2', '3', '4', '5' ,'6', '7', '8', '9' };
	//char DefaulArray[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	while (true)
	{
		char ArrayPrint[] = { '1', '2', '3', '4', '5' ,'6', '7', '8', '9' };

	  system("cls");
	  cout << "X O Gameeee" << "\n";
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
		//  std::copy(std::begin(DefaulArray), std::end(DefaulArray), std::begin(ArrayPrint));
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
};


// Fadi Message