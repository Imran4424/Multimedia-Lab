#include <iostream>
#include <fstream>
using namespace std;

void Compress()
{
	char c, old_c;

	ifstream readFile;

	readFile.open("plain.txt");

	if(readFile.is_open())
	{
		while(readFile >> skipws >> c)
		{

		}


		readFile.close();
	}
	else
	{
		cout << "can not open the file plain.txt" << endl;
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}