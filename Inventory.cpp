//Sinclair Community College
//Final Project
//Kevin Gowsell
//May 3rd, 2019

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

const int column_Size = 5;
const int row_Size = 2;
double visitors[row_Size][column_Size];

//display all the data from the banking file
void DisplayData()
{
	cout << endl;
	cout << "      Day    " << "Month " << "   Year " << "   Expense  " << "  Income  " <<endl;
	for (int i = 0; i < row_Size; i++)
	{
		for (int j = 0; j < column_Size; j++)
		{
			std::cout << setw(8) << visitors[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl; 
	cout << endl;
}

//add an new entry to the file. 
void addNewEntry()
{
	double inputDay;
	double inputMonth;
	double inputYear;
	double totalIncome;
	double totalExpense;
	int arrayZero = 0;
	int arrayOne = 0;
	string moreEntry = "Y";

	ofstream writeFile; // Input file stream object to write
	writeFile.open("Banking.txt", ios::in);//open the file

	while (moreEntry != "N" && moreEntry != "n")
	{
		cout << "Please Enter the Day: ";
		cin >> inputDay;
		visitors[arrayOne][arrayZero] = inputDay;
		arrayZero++;
		cout << "Please Enter the Month: ";
		cin >> inputMonth;
		visitors[arrayOne][arrayZero] = inputMonth;
		arrayZero++;
		cout << "Please Enter the Year: ";
		cin >> inputYear;
		visitors[arrayOne][arrayZero] = inputYear;
		arrayZero++;
		cout << "Please Enter total Expenses for that Day: ";
		cin >> totalExpense;
		visitors[arrayOne][arrayZero] = totalExpense;
		arrayZero++;
		cout << "Please Enter total Income for that Day: ";
		cin >> totalIncome;
		visitors[arrayOne][arrayZero] = totalIncome;
		arrayZero = 0; //reset the columns
		arrayOne++; //add one to the rows for next input. 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "The following values will be recorded:" << endl;
		for (int i = 0; i < row_Size; i++)
		{
			for (int j = 0; j < column_Size; j++)
			{
				writeFile << visitors[i][j];
				std::cout << setw(8) << visitors[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "Would you like to add another entry? (Y/N) : ";
		cin >> moreEntry;

	}
	writeFile.close();
	return;
}

void viewFile()
{
	//view the file to double check
	string seeFile = "Y";
	double fileArray[row_Size][column_Size];
	
	ofstream inputFile; // Input file stream object
	inputFile.open("Banking.txt");//open the file
	
		for (int i = 0; i < column_Size; i++)
		{
			for (int j = 0; j < row_Size; j++)
			{
				inputFile << fileArray[j][i];
			}
		}
		std::cout << setw(8) << fileArray[row_Size][column_Size] << ' ';

		inputFile.close();
		system("pause");
		return;
}

//Display balance of the account
void DisplayBalance()
{
	double expenseTotal = 0;
	double incomeTotal = 0;
	int expenseCol = 3;
	int incomeCol = 4;
	double balance;

	//sum the expense column
	cout << endl;
	for (int i = 3; i <= expenseCol; i++) // controls column
	{
		expenseTotal = 0;
		for (int j = 0; j < row_Size; j++) // controls the row
		{
			expenseTotal += visitors[j][i];
			
		}
	}cout << "Expenses total: " << expenseTotal << endl;
	//sum the income column
	for (int i = 4; i <= incomeCol; i++)
	{
		for (int j = 0; j < row_Size; j++)
		{
			incomeTotal += visitors[j][i];
		}
	}cout << "Income Total: " << incomeTotal << endl;
	cout << endl;
	 //Display the sum.
	balance = incomeTotal - expenseTotal;
	cout << "Your Current Balance is: " << balance << endl;
	cout << endl;
	return;
}


//Main - menu
int main()
{
	//Variables
	char menuSelect = '0';
	int count = 0;


	// Title
	cout << "Expense Report" << endl;
	cout << endl;

	//Menu
	while (menuSelect != '4')
	{
		cout << "Enter 1 to Display Current Expense Information." << endl;
		cout << "Enter 2 to Input a New Entry." << endl;
		cout << "Enter 3 to Display the Current Balance." << endl;
		cout << "Enter 4 to Display the File" << endl;
		cout << "Enter 5 to Exit" << endl;
		cout << "Menu Selection: ";
		cin >> menuSelect;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (menuSelect)
		{
		case '1':
			DisplayData();
			break;
		case '2':
			addNewEntry();
			break;
		case '3':
			DisplayBalance();
			break;
		case '4':
			viewFile();
			break;
		case '5':
			system("pause");
			return 0;
		}
	}
}
