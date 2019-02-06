#include <iostream>
#include <fstream>
using namespace std;

void Compress()
{
	char c, old_c;
	int count = 0;

	ifstream readFile;

	readFile.open("smallPlain.txt");

	if(readFile.is_open())
	{
		
		readFile >> noskipws >> c;

		while(readFile)
		{

			old_c = c;

			count = 1;

			while(readFile >> noskipws >> c && old_c == c)
			{
				count++;
			}

			if (c == old_c && count == 1)
			{
				break;
			}

			ofstream writeFile;

			writeFile.open("compress.txt", ios::app);

			if (writeFile.is_open())
			{
				writeFile << int(old_c) << " " << count << endl;

				writeFile.close();
			}
			else
			{
				cout << "can not open the file compress.txt" << endl;
			}

		}
		
		readFile.close();
	}
	else
	{
		cout << "can not open the file plain.txt" << endl;
	}
}



void Decompress()
{

}


int main(int argc, char const *argv[])
{
	Compress();

	Decompress();

	return 0;
}