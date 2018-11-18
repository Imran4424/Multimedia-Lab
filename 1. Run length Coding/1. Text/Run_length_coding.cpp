#include <iostream>
#include <string>
using namespace std;

string Encoding(string text)
{
    string encoded_text;

    for(int i = 0; i < text.length(); i++)
    {
        int count = 1;

        encoded_text += text[i];

        while(i < text.length()  && text[i] == text [i+1])
        {
            count++;

            i++;
        }

        if(count > 9)
        {
            int result = count / 9;

            int remain = count % 9;


            for(int i = 0; i <= (result*2) - 1; i++)
            {
                if( i % 2 == 0)
                {
                    encoded_text += '9';
                }
                else
                {
                    encoded_text += text[i];
                }
            }

            encoded_text += (char)remain + 48;
        }
        
        else
        {
            encoded_text += (char)count + 48;
        }
        
        //cout << "char num : " << count << (char) count + 48 << endl;

        
    }

    return encoded_text;
}

string Decoding(string encoded_text)
{
    string decoded_text;

    for(int i=0; i < encoded_text.length(); i = i + 2)
    {
        int temp = (int) encoded_text[i+1] - 48;

        decoded_text.append(temp, encoded_text[i]);
    }

    return decoded_text;
}

main(int argc, char const *argv[])
{
    string text;

    getline(cin, text);

    cout << "Orininal text: " << text << endl;

    string encoded_text = Encoding(text);

    cout << "Encoded text: " << encoded_text << endl;

    string decoded_text = Decoding(encoded_text);
    
    cout << "Decoded text: " << decoded_text << endl;

    return 0;
}
