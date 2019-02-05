#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

typedef long long int lli;

void Compress()
{
	unordered_map < string, lli > codes;

	for(lli i = 0; i < 256; i++)
	{
		codes[string(1, char(i))] = i;
	}

	lli nextCode = 257;

	string currentString;

	char c;

	ifstream readFile;

	string fileName = "plain.txt";

	readFile.open(fileName);

	if (readFile.is_open())
	{
		while( readFile >> c)
		{
			currentString = currentString + c;

			if (codes.count(string(currentString)) == 0)
			{
				codes[currentString] = nextCode++;

				currentString.erase(currentString.length() - 1);

				ofstream writeFile;

				writeFile.open("compress.txt");

				if (writeFile.open())
				{
					writeFile << currentString;

					writeFile.close();
				}
				else
				{
					cout << "can not open the file" << endl;
				}

				currentString = c;
			}
		}

		writeFile.open("compress.txt");

		if (writeFile.open())
		{
			writeFile << codes[currentString];

			writeFile.close();
		}
		else
		{
			cout << "can not open the file" << endl;
		}


		readFile.close();
	}
	else
	{
		cout << "can not open the file: " << fileName << endl;
	}
}


void Decompress()
{
	unordered_map < lli, string > strings;

	for(lli i = 0; i < 256; i++)
	{
		codes[i] = string(1, char(i));
	}

	string previousString;

	lli code;
	lli nextCode = 257;

	ifstream readFile;

	readFile.open("compress.txt");

	if (readFile.open())
	{

		while( readFile >> code)
		{

			if (strings.count(lli(code)) == 0)
			{
				strings[code] = previousString + previousString[0];
			}

			ofstream writeFile;
			writeFile.open("decompress.txt");

			if (writeFile.open())
			{

				writeFile << strings[code];

				writeFile.close();
			}
			else
			{
				cout << ""
			}
		}

		readFile.close();
	}
	else
	{
		cout << "can not open the file compress" << endl;
	}
}



int main(int argc, char const *argv[])
{
	
	return 0;
}