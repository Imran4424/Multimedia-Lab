#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

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

void PrintCodes(node *root, string line)
{
    if(!root)
    {
        return;
    }

    if(root -> data != '#')
    {
        cout << root -> data << " : " << line << endl;
    }

    PrintCodes(root -> left, line + "0");
    PrintCodes(root -> right, line + "1");
}

void Huffman(map<char, int> frequencyMap)
{
    node *left, *right, *top;

    priority_queue < node*, vector<node*>, Compare > minHeap;

    map<char, int>::iterator itr;

    for(itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++)
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


    PrintCodes(minHeap.top(), "");
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

    return 0;
}
