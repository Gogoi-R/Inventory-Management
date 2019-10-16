#include"common.cpp"

inline int input()
{
	inventory inv;
	fstream fbj("TEST0.dat", ios::app | ios::binary);
	int x = 11;		//value of x controls the loop below
	while (x!=22)	//takes multiple inputs
	{
		inv.input();
		fbj.write((char*)&inv, sizeof inv);
		cout << "\n[SPACE BAR: Enter next entry | X: Return to Menu]\n\n";
		x = inv.key();
	}
	fbj.close();
	return 0;
}