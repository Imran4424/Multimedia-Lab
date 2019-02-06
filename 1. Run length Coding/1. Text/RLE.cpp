#include <iostream>
#include <fstream>
using namespace std;

void Compress()
{
	char c, old_c, count = 0;

	ifstream readFile;

	readFile.open("plain.txt");

	if(readFile.is_open())
	{
		while(readFile >> skipws >> c)
		{

			old_c = c;

			count = 1;

			while(readFile >> skipws >> c && old_c == c)
			{
				count++;
			}

			if (writeFile.is_open())
			{
				writeFile << old_c << " " << count << endl;

				//cout << currentString << endl;

				writeFile.close();
			}
			else
			{
				cout << "can not open the file" << endl;
			}

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