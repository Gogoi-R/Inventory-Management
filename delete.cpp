#include"common.cpp"

inline int del(int n)	//deletes specific record
{
	int notFound=1;	//if the searched item is not in the record the value stays unchanged
	char confirm;	//for various use as confirmatory flags
	inventory inv;
	fstream fbj("TEST0.dat", ios::in | ios::binary);	//opens file in read mode
	fstream _fbj("~TEST0.dat", ios::out | ios::binary);	//opens temp file in write mode
	fbj.seekg(0);	//resets the file to start
	if (!fbj)	//if file doesn't exist
	{
		cout << "FAILED TO OPEN FILE!";
		_getche();
	}
	while (fbj.read((char*)&inv, sizeof inv))	//runs till file end
	{
		if (n == inv.serial())
		{
			notFound = 0;	//indicates that the file has been found 
			cout << "\nRECORD FOUND:\n\n";
			inv.output();
			cout << "\n\nDelete this item? (y/n) : ";	//delete confirmation prompt
			do
			{
				cin >> confirm;
				if (confirm == 'n')
					_fbj.write((char*)&inv, sizeof inv);
				if (confirm == 'y')
				{
					cout << "\nRecord deleted.\n";
					break;
				}
			} while (confirm != 'y' && confirm != 'n');	//user input validation
		}
		else
			_fbj.write((char*)&inv, sizeof inv);
	}
	_fbj.close();
	fbj.close();
	remove("TEST0.dat");
	rename("~TEST0.dat", "TEST0.dat");
	//original file is deleted. Temp file is renamed to the original file's name.
	if (notFound)
		cout << "Record not found.\n";
	_getch();
	return 0;
}

inline void delAll()	//deletes all records
{
	inventory inv;
	int confirm = 0;
	cout << "ARE YOU SURE YOU WANT TO DELETE ALL RECORDS?\n\n\n[SPACE BAR: NO | X: YES]\n\n";
	while (confirm != 22 && confirm != 11)
	{
		confirm = inv.key();
	}
	if (confirm == 22)
	{
		remove("TEST0.dat");
		fstream fbj("TEST0.dat", ios::out | ios::binary);
		fbj.close();
		cout << "\nAll records deleted.\n";
	}
}