#include<iostream>
using namespace std;
//two dimensional array by leemor 
//but the code have one error in 121th line i thing
class XOGame
{
  void PrintNet(char ArrayPrintT[][3], int RowNumber)
  {
	  for (int i = 0; i < RowNumber; i++)
	  {
		  for (int j = 0; j < 3; j++)
		  {
			  cout << ArrayPrintT[i][j];
			  if (j == 0 || j == 1)
				  cout << "  |  ";
		  }
		  if (i == 0 || i == 1)
			  cout << "\n--------------\n";
	  }
  }
  void PrintPlayerTurn(int RoundPlayed) {
	if (RoundPlayed % 2 == 0)
	  cout << "\nX Is Playing";
	else
	  cout << "\nO Is Playing";
  }
  void FillXO(int Site, int CountPlay, char ArrayPrint[][3],int RowSite , int ColumnSite)
  {
	if (CountPlay % 2 == 0)
	  ArrayPrint[RowSite][ColumnSite] = 'O';
	else
	  ArrayPrint[RowSite][ColumnSite] = 'X';
  }
  int CheckCondition(char ArrayPrint[3][3], int CountPlay)
  {
	int WhoWin;
	if (CountPlay % 2 != 0)
	  WhoWin = 1;
	else
	  WhoWin = 2;
	if (ArrayPrint[0][0] == ArrayPrint[0][1] && ArrayPrint[0][1] == ArrayPrint[0][2])
	  return WhoWin;
	else if (ArrayPrint[1][0] == ArrayPrint[1][1] && ArrayPrint[1][1] == ArrayPrint[1][2])
	  return WhoWin;
	else if (ArrayPrint[2][0] == ArrayPrint[2][1] && ArrayPrint[2][1] == ArrayPrint[2][2])
	  return WhoWin;
	else if (ArrayPrint[0][0] == ArrayPrint[1][0] && ArrayPrint[1][0] == ArrayPrint[2][0])
	  return WhoWin;
	else if (ArrayPrint[0][1] == ArrayPrint[1][1] && ArrayPrint[1][1] == ArrayPrint[2][1])
	  return WhoWin;
	else if (ArrayPrint[0][2] == ArrayPrint[1][2] && ArrayPrint[1][2] == ArrayPrint[2][2])
	  return WhoWin;
	else if (ArrayPrint[0][0] == ArrayPrint[1][1] && ArrayPrint[1][1] == ArrayPrint[2][2])
	  return WhoWin;
	else if (ArrayPrint[0][2] == ArrayPrint[1][1] && ArrayPrint[1][1] == ArrayPrint[2][0])
	  return WhoWin;
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
	  }

	} while (true);

	return userInput;
  }
  int ReturnRowNumber(int X)
  {
	  if (X == 1 || X == 2 || X == 3)
		  return 0;
	  else if (X == 4 || X == 5 || X == 6)
		  return 1;
	  else
		  return 2;
  }
  int ReturnColumnNumber(int Y)
  {
	  if (Y == 1 || Y == 4 || Y == 7)
		  return 0;
	  else if (Y == 2 || Y == 5 || Y == 8)
		  return 1;
	  else
		  return 2;
  }

  public: int main2()
  {
	bool RoundEnded = false;
	int CountXWin = 0;
	int CountOWin = 0;
	int RoundPlayed = 0;
	char ArrayPrint[][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char DefaulArray[][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

	while (true)
	{
	  system("cls");
	  cout << "X O Game" << "\n";
	  PrintNet(ArrayPrint,3);
	  cout << "\nX wins:(" << CountXWin << "), O wins:(" << CountOWin << ")";
	  if (RoundEnded) 
	  {
		cout << "\nEnter 1 To Playing again, Enter 0 To Stop.\n";
		int PlayAgain;
		cin >> PlayAgain;
		if (cin.fail() || PlayAgain != 1) {
			//Exit Game;
		  break;
		}
		else {
		 //  Reset game
		  RoundEnded = false;
		  RoundPlayed = 0;

	      std::copy(std::begin(DefaulArray), std::end(DefaulArray), std::begin(ArrayPrint));
		  continue;
		}
	  }

	  PrintPlayerTurn(RoundPlayed);
	  cout << "\n" << "Please Enter The Site Which You Want From 1 To 9" << "\n";
	  int Site = GetIntergerInput("You Entered A String!");

	  int RowSite = ReturnRowNumber(Site);
	  int ColumnSite = ReturnColumnNumber(Site);

	  if (Site < 1 || Site > 9) 
		continue;
	  else if (ArrayPrint[RowSite][ColumnSite] == 'X' || ArrayPrint[RowSite][ColumnSite] == 'O')
		cout << "This Site Has Already Been entered \n";

	  else
	  {
		RoundPlayed++;
		FillXO(Site, RoundPlayed, ArrayPrint , RowSite, ColumnSite); 
	  }
	  int WhoWon = CheckCondition(ArrayPrint, RoundPlayed);

	  if (WhoWon == 1 || WhoWon == 2 || RoundPlayed == 9)
	  {
		RoundEnded = true;
		if (WhoWon == 1) 
		  CountXWin++;
		else if (WhoWon == 2) 
		  CountOWin++;
	  }
	}
	return 0;
  }
};