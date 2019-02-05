#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

map<char, string> codes;

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
        codes[root -> data] = line;
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


int main()
{
    string text;
    getline(cin, text);

    map<char, int> frequencyMap;

    for(int i=0; i < text.length(); i++)
    {
        if(frequencyMap.count(text[i]) == 0)
        {
            frequencyMap[text[i]] = 1;
        }
        else
        {
            frequencyMap[text[i]]++;
        }
    }

    Huffman(frequencyMap);


    for(auto itr = codes.begin(); itr != codes.end(); itr++)
    {
        cout << itr -> first << " : " << itr -> second << endl;
    }

    return 0;
}
