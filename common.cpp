#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<limits>
#include<ctype.h>

#define KEY_SPACE 32	//Space Bar
#define KEY_x 120		//x key
#define KEY_X 88		//X key
#define KEY_0 48		//0
#define KEY_1 49		//1
#define KEY_2 50		//2
#define KEY_3 51		//3
#define KEY_4 52		//4
#define KEY_5 53		//5
#define KEY_6 54		//6
#define KEY_7 55		//7
#define KEY_8 56		//8
#define KEY_9 57		//9


using namespace std;

#ifndef INVENTORY
#define INVENTORY

class inventory
{
private:
	int sno;		//serial number
	char nam[30];	//name of item
	char typ[20];	//type of item
	float cst;		//cost
	int qnt;		//quantity
	//date of manufacture
	int dd;
	int mm;
	int yy;
public:
	int serial()	//accessor funtion for serial number
	{
		return sno;
	}
	char*type()
	{
		return typ;
	}
	char*name()
	{
		return nam;
	}
	void input()		//takes input from user
	{
		cout << "SERIAL NUMBER: "; cin >> sno;
		while (cin.fail() || cin.peek() != '\n')	//int input validation
		{
			cin.clear();
			cin.ignore();
			cout << "You have entered wrong input. Re-Enter: ";
			cin >> sno;
		}
		cin.ignore();
		cout << "TYPE OF ITEM: "; cin.getline(typ,20);
		cout << "NAME OF ITEM: "; cin.getline(nam,30);
		cout << "COST OF ITEM: ";  cin >> cst;
		while (cin.fail() || cin.peek() != '\n')	//int input validation
		{
			cin.clear();
			cin.ignore();
			cout << "You have entered wrong input. Re-Enter: ";
			cin >> cst;
		}
		cin.ignore();
		cout << "QUANTITY OF ITEM: "; cin >> qnt;
		while (cin.fail() || cin.peek() != '\n')	//int input validation
		{
			cin.clear();
			cin.ignore();
			cout << "You have entered wrong input. Re-Enter: ";
			cin >> qnt;
		}
		cin.ignore(); 
		cout << "Enter Date (DD/MM/YY): ";
		while (inDates(dd, mm, yy));
	}
	void output()	//displays the details of the data members
	{
		cout << "SERIAL NUMBER: " << sno << endl;
		cout << "TYPE OF ITEM: " << typ << endl;
		cout << "NAME OF ITEM: " << nam << endl;
		cout << "COST OF ITEM: " << cst << endl;
		cout << "QUANTITY OF ITEM: " << qnt << endl;
		cout << "Enter Date: " << dd << "/" << mm << "/" << yy << endl;
	}
	int key()	//key input fuction
	{
		char key = _getch();
		int value = key;
		while (value != KEY_0 && value != KEY_1 && value != KEY_2 && value != KEY_3 && value != KEY_4 && value != KEY_5 && value != KEY_6 && value != KEY_7 && value != KEY_8 && value != KEY_9 && value != KEY_SPACE && value != KEY_X && value != KEY_x)
		{
			key = _getch();
			value = key;
		}
		if (value == KEY_0)
			return 0;
		if (value == KEY_1)
			return 1;
		if (value == KEY_2)
			return 2;
		if (value == KEY_3)
			return 3;
		if (value == KEY_4)
			return 4;
		if (value == KEY_5)
			return 5;
		if (value == KEY_6)
			return 6;
		if (value == KEY_7)
			return 7;
		if (value == KEY_8)
			return 8;
		if (value == KEY_9)
			return 9;
		if (value == KEY_SPACE)
			return 11;
		if (value == KEY_X || value == KEY_x)
			return 22;
	}
	//dates date;
	int inDates(int&d, int&m, int&y)	//takes date input in [day of year]/[month]/[year] format
	{
		cin >> d; // read the day
		if (cin.get() != '/') // make sure there is a slash between DD and MM
		{
			cout << "Expected '/'. Re-Enter Date: ";
			return 1;
		}
		cin >> m; // read the month
		if (cin.get() != '/') // make sure there is a slash between MM and YYYY
		{
			cout << "Expected '/'. Re-Enter Date: ";
			return 1;
		}
		cin >> y;	//read the year
		return 0;
	}
};

inline int isSame(char a[], char b[])
{
	int flag = 0;
	if (strlen(a) == strlen(b))
	{
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] != b[i])
			{
				flag = 1;
				break;
			}
		}
	}
	else
		return 0;
	if (flag)
		return 0;
	else
		return 1;
}


#endif // !COMMON