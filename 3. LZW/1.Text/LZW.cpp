#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

typedef long long int lli;

void compress()
{
	unordered_map < string, int > codes;

	for(lli i = 0; i < 256; i++)
	{
		codes[string(1, char(i))] = i;
	}

	lli nextCode = 257;

	string currentString;

	char c;

	
}



int main(int argc, char const *argv[])
{
	
	return 0;
}