#include"common.cpp"

int sort()
{
	int n, f;
	char confirm;
	inventory inv;
	cout << "Enter Serial Number: ";
	cin >> n;
	fstream fbj("TEST.dat", ios::in | ios::binary);
	fstream _fbj("~TEST.dat", ios::out | ios::binary);
	fbj.seekg(0);
	if (!fbj)
	{
		cout << "FAILED TO OPEN FILE!";
		_getche();
	}
	while (!fbj.eof())
	{
		system("cls");
		fbj.read((char*)&inv, sizeof inv);
		if (n == inv.serial())
		{
			inv.output();
			cout << "\n\nDelete this item? (y/n)";
			f = 0;
			do
			{
				cin >> confirm;
				if (confirm == 'n')
					_fbj.write((char*)&inv, sizeof inv);
				if (f)
					cout << "\nPlese give a valid input.\n";
				++f;
			} while (confirm != 'y' || confirm != 'n');
		}
		else
			_fbj.write((char*)&inv, sizeof inv);
	}
	_fbj.close();
	fbj.close();
	remove("TEST.dat");
	rename("~TEST.dat", "TEST.dat");
	return 0;
}