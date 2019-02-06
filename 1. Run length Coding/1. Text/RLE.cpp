#include <iostream>
#include <fstream>
using namespace std;

void Compress()
{
	char c, old_c;
	int count = 0;

	ifstream readFile;

	readFile.open("plain.txt");

	if(readFile.is_open())
	{
		
		readFile >> noskipws >> c;

		while(true)
		{

			old_c = c;

			count = 1;

			while(readFile >> noskipws >> c)
			{
				if(old_c == c)
				{
					count++;
				}
				else
				{
					break;
				}
				
			}

			ofstream writeFile;

			writeFile.open("compress2.txt", ios::app);

			if (writeFile.is_open())
			{
				writeFile << old_c << " " << count << endl;

				writeFile.close();
			}
			else
			{
				cout << "can not open the file compress.txt" << endl;
			}

			if (readFile.eof())
			{
				break;
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
	int asciiCode, count;

	ifstream readFile;

	readFile.open("compress2.txt");

	if (readFile.is_open())
	{
		while(readFile >> asciiCode >> count)
		{
			ofstream writeFile;

			writeFile.open("decompress.txt", ios::app);

			if (writeFile.is_open())
			{
				for (int i = 0; i < count; ++i)
				{
					writeFile << char(asciiCode);
				}
				

				writeFile.close();
			}
			else
			{
				cout << "can not open the file decompress.txt" << endl;
			}

		}

		readFile.close();
	}
	else
	{
		cout << "can not open the file compress.txt" << endl;
	}
}

int main(int argc, char const *argv[])
{
	Compress();

	Decompress();

	return 0;
}