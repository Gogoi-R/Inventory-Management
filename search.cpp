#include"common.cpp"

inline int search(int n)	//argument contains the serial number being searched for
{
	int notFound = 1;	//if the searched item is not in the record the value stays unchanged
	inventory inv;
	fstream fbj("TEST0.dat", ios::in | ios::binary);	//opens file in read mode
	fbj.seekg(0);	//resets file to start
	if (!fbj)	//if file doesn't exist
	{
		cout << "FAILED TO OPEN FILE!";
		_getche();
	}
	while (!fbj.eof())	//runs till the file end is reached
	{
		fbj.read((char*)&inv, sizeof inv);
		if (n == inv.serial())
		{
			notFound = 0;	//indicates that the file has been found 
			cout << "RECORD FOUND:\n\n";
			inv.output();
			break;
		}
	}
	fbj.close();
	if (notFound) //if the searched item is not in the record
		cout << "Record not found.\n";
	return 0;
}