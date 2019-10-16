#include"common.cpp"

struct cred
{
	char unam[20];
	char pass[20];
};


inline int login()
{
	cred X;
	int tries = 3, correct = 0;
	char unam0[20], pass0[20];
	fstream fbj("CREDENTIALS234.dat", ios::in | ios::binary);
	if (!fbj)	//creats CREDENTIALS.dat file for first time run
	{
		cout << "*********WELCOME NOTE*********\n";
		cout << "------------------------------";
		cout << "\nWelcome to the project 'INVENTORY MANAGEMENT SYSTEM'.";
		cout << "\nCreated by Rishparn Gogoi, Roktim Kamal Senapoty and Sikhar Abhilekh Gogoi.";
		cout << "\nGuided by Mr.Ayan Sengupta\nYEAR: 2018 - 19\n\n";
		cout << "\n\nDefault Authentication Details:\n";
		cout << "Username: admin\nPassword: password\n\n(Username and Password can be changed in the application\n\n";
		cout << "\n\nPress any key to continue.\n";
		_getch();
		fbj.open("CREDENTIALS234.dat", ios::out | ios::binary);
		strcpy_s(X.unam, "admin");
		strcpy_s(X.pass, "password");
		fbj.write((char*)&X, sizeof X);
		fbj.close();
	}
	system("cls");
	fbj.close();
	cout << "INVENTORY MANAGEMENT SYSTEM\n***************************\n\n\n";
	cout << "LOGIN: \n\n";
	//verification
	while (tries)
	{
		fbj.open("CREDENTIALS234.dat", ios::in | ios::binary);
		fbj.seekg(0);
		cout << "USERNAME: "; cin.getline(unam0,20);
		cout << "PASSWORD: "; cin.getline(pass0,20);
		while (fbj.read((char*)&X, sizeof X))
		{
			if (isSame(unam0, X.unam)==1 && isSame(pass0, X.pass)==1)
			{
				correct = 1;
				fbj.close();
				cout << "\n\nWELCOME.\n\nPress any key to continue.";
				_getch();
				return 1;
			}
		}
		fbj.close();
		if (!correct)
		{
			cout << "\nIncorrect username or password. ";
			if (--tries > 0)
				cout << tries << " attempts left.\n";
			else
				cout << "No attempts left. Terminating.";
		}	//decreaments the value each time the loop runs
	
	}
	_getch();
	return 0;
}

inline int newCred()
{
	cred X;
	char unam0[20], pass0[20];
	int flag = 1;
	while (flag)
	{
		cout << "ENTER NEW USERNAME AND PASSWORD:\n\n";
		cout << "USERNAME: "; cin.getline(X.unam, 20);
		cout << "PASSWORD: "; cin.getline(X.pass, 20);
		cout << "\n\nRE-ENTER NEW USERNAME AND PASSWORD:\n\n";
		cout << "USERNAME: "; cin.getline(unam0, 20);
		cout << "PASSWORD: "; cin.getline(pass0, 20);
		if (isSame(unam0, X.unam) == 1 && isSame(pass0, X.pass) == 1)
		{
			flag = 0;
			fstream fbj("CREDENTIALS234.dat", ios::out | ios::binary | ios::trunc);
			fbj.write((char*)&X, sizeof X);
			cout << "\n\nDetails changed.\n\n";
			_getch();
			return 1;
		}
		else
			cout << "MISMATCHED.\n\nPlease Re-enter\n\n";
	}
}