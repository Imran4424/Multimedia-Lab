#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


map<char, string> codes;
map<string, char> characters;

struct node
{
    char data;
    int frequency;
    node* left;
    node* right;

    node(char data, int frequency)
    {
        left = NULL;
        right = NULL;

        this -> data = data;
        this -> frequency = frequency;
    }

};

class Compare
{
    public: bool operator()(node* left, node* right)
    {
        return (left -> frequency > right -> frequency);
    }
};

void WriteCodes(node *root, string line)
{
    if(!root)
    {
        return;
    }

    if(root -> data != '#')
    {
        // int code;
        // stringstream convert;

        // convert << line;

        // convert >> code;

        codes[root -> data] = line;

        characters[line] = root -> data;
    }

    WriteCodes(root -> left, line + "0");
    WriteCodes(root -> right, line + "1");
}

void Huffman(map<char, int> frequencyMap)
{
    node *left, *right, *top;

    priority_queue < node*, vector<node*>, Compare > minHeap;

    for(auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++)
    {
        minHeap.push(new node(itr -> first, itr -> second));
    }

    while( minHeap.size()!= 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new node('#', left -> frequency + right -> frequency);

        top -> left = left;
        top -> right = right;

        minHeap.push(top);
    }


    WriteCodes(minHeap.top(), "");
}

void Compress()
{
    char c;

    ifstream readFile;
    string fileName = "plain.txt";
    readFile.open(fileName);

    if (readFile.is_open())
    {
        while(readFile >> noskipws >> c)
        {
            ofstream writeFile;

            writeFile.open("compress.txt", ios::app);

            if (writeFile.is_open())
            {
                writeFile << codes[c] << endl;

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
        cout << "can not open the file: " << fileName << endl;
    }
}


void Decompress()
{
    string code;

    ifstream readFile;
    string fileName = "compress.txt";
    readFile.open(fileName);

    if (readFile.is_open())
    {
        while(readFile >> code)
        {
            ofstream writeFile;

            writeFile.open("decompress.txt", ios::app);

            if (writeFile.is_open())
            {
                writeFile << characters[code];

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
        cout << "can not open the file: " << fileName << endl;
    }
}


int main()
{
    map<char, int> frequencyMap;

    char c;

    ifstream readFile;
    string fileName = "plain.txt";
    readFile.open(fileName);

    if (readFile.is_open())
    {
        while(readFile >> noskipws >> c)
        {
            if(frequencyMap.count(char(c)) == 0)
            {
                frequencyMap[c] = 1;
            }
            else
            {
                frequencyMap[c]++;
            }
        }

        readFile.close();
    }
    else
    {
        cout << "can not open the file: " << fileName << endl;
    }


    Huffman(frequencyMap);


    Compress();
    Decompress();   

    return 0;
}
