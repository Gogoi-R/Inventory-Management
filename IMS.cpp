#include"common.cpp"
#include"input.cpp"
#include"display.cpp"
#include"delete.cpp"
#include"search.cpp"
#include"update.cpp"
#include"login.cpp"

VOID WINAPI SetConsoleColors(WORD attribs);

int main()
{
	if (!login())
	{
		exit(0);
	}
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); //sets window to fullscreen
	SetConsoleColors(BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int sno;	//serial number
	inventory inv;
	int repeat = 1, confirm;	//value of reapeat controls the menu while loop
	while (repeat)
	{
		system("cls");	//clears the console screen
		cout << "INVENTORY MANAGEMENT SYSTEM\n***************************\n\n\n";
		cout << "1. Enter New Record\n\n2. Search Records by Serial Number\n\n3. Display all Records\n\n";
		cout << "4. Delete specific Record\n\n5. Update Existing Record\n\n6. Clear all records\n\n7. Change Login Deatials\n\n0. Exit\n\n";
		int x = inv.key();	//for keystroke input
		switch (x)	//menu
		{
		case 1:		//Enter New Record
			system("cls");
			cout << "ENTER NEW RECORD\n****************\n\n\n";
			input();
			break;
		case 2: //Search Records by Serial Number
			system("cls");
			cout << "SEARCH RECORDS\n**************\n\n\n";
			cout << "Enter Serial Number: "; cin >> sno;
			while (cin.fail() || cin.peek() != '\n')	//int input validation
			{
				cin.clear();
				cin.ignore();
				cout << "You have entered wrong input. Re-Enter: ";
				cin >> sno;
			}
			search(sno);
			cout << "\n\n[SPACE BAR: Return to menu]\n\n";
			confirm = 0;
			while (confirm != 11)
			{
				confirm = inv.key();
			}
			break;
		case 3: //Display all Records
			system("cls");
			cout << "ALL RECORDS\n***********\n\n\n";
			disp();
			cout << "\n\n[SPACE BAR: Return to menu]\n\n";
			confirm = 0;
			while (confirm != 11)
			{
				confirm = inv.key();
			}
			break;
		case 4: //Delete specific Record
			system("cls");
			cout << "DELETE RECORD\n************\n\n\n";
			cout << "Enter Serial Number: "; cin >> sno;
			del(sno);
			cout << "\n\n[SPACE BAR: Return to menu]\n\n";
			confirm = 0;
			while (confirm != 11)
			{
				confirm = inv.key();
			}
			break;
		case 5: //Update Existing Record
			system("cls");
			cout << "UPDATE RECORD\n************\n\n\n";
			cout << "Enter serial number of the item to be updated: "; cin >> sno;
			while (cin.fail() || cin.peek() != '\n')	//int input validation
			{
				cin.clear();
				cin.ignore();
				cout << "You have entered wrong input. Re-Enter: ";
				cin >> sno;
			}
			update(sno);
			cout << "\n\n[SPACE BAR: Return to menu]\n\n";
			confirm = 0;
			while (confirm != 11)
			{
				confirm = inv.key();
			}
			break;
		case 6: //Clear all records
			system("cls");
			cout << "UPDATE RECORD\n************\n\n\n";
			delAll();
			cout << "\n\n[SPACE BAR: Return to menu]\n\n";
			confirm = 0;
			while (confirm != 11)
			{
				confirm = inv.key();
			}
			break;
		case 7: //Change Login Details
			system("cls");
			cout << "CHANGE LOGIN DETAILS\n************\n\n\n";
			newCred();
			cout << "\n\n[SPACE BAR: Return to menu]\n\n";
			confirm = 0;
			while (confirm != 11)
			{
				confirm = inv.key();
			}
			break;
		case 0: //exit
			system("cls");
			cout << "ARE YOU SURE YOU WANT TO EXIT?\n\n\n[SPACE BAR: NO | X: YES]\n\n";
			confirm = 0;
			while (confirm != 22 && confirm !=11)
			{
				confirm = inv.key();
			}
			if (confirm == 22)
			{
				repeat = 0;
			}
			break;
		}
	}
	_getch();
	return 0;
}