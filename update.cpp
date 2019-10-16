#include"common.cpp"

inline void update(int n)
{
	int notFound = 1;
	char confirm;
	inventory inv;
	fstream fbj("TEST0.dat", ios::in | ios::out | ios::ate | ios::binary);
	fbj.seekg(0);
	if (!fbj)
	{
		cout << "FAILED TO OPEN FILE!";
		_getche();
	}
	while (!fbj.eof())
	{
		fbj.read((char*)&inv, sizeof inv);
		if (n == inv.serial())
		{
			notFound = 0;
			cout << "RECORD FOUND:\n\n";
			inv.output();
			cout << "\n\nUpdate this item? (y/n) : ";
			do
			{
				cin >> confirm;
				if (confirm == 'n')
					break;
				if (confirm == 'y')
				{
					cout << "\n\nENTER NEW DETAILS:\n\n";
					inv.input();
					long x = fbj.tellp(), y = sizeof(inv);
					fbj.seekp(x - y);
					fbj.write((char*)&inv, sizeof inv);
					cout << "\n\nRecord updated.\n\n";
					break;
				}
			} while (confirm != 'y' || confirm != 'n');
			break;
		}
	}
	fbj.close();	
	if (notFound)
		cout << "Record not found.\n";
}