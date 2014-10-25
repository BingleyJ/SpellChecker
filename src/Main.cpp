#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <cstring>
//#include <stdio.h>
#include <algorithm>

using namespace std;

typedef set<string> Dictionary;

Dictionary LoadFile(Dictionary inDick);
void CheckWords(Dictionary inDick);

int main()
{
    Dictionary dictionary;
    dictionary = LoadFile(dictionary);
    bool quit = false;
    string inWord;
    cout << "-- Spell Checker --\n";
    cout << dictionary.size() << " words in Dictionary file.\n";
    CheckWords(dictionary);
    return 0;
}


void CheckWords(Dictionary inDick )
{
    string filename;
    bool goodfilename = false;
    while (!goodfilename)
    {
        cout << "\nPlease enter the file name you would like to spell check :";
        cin >> filename;
        ifstream file (filename.c_str());
        if (file)
            goodfilename = true;
        else
            cout << "\nHorrible File Name. Try Again.\n";
        file.close();
    }
    ifstream file (filename.c_str());
    string inWord = "loser";
    while (file >> inWord)
    {
        char badchars[] = ".,}{[]();:!@#$%^&*/?><\"";
        for (unsigned int i = 0; i < strlen(badchars); ++i)
        {
            inWord.erase(remove(inWord.begin(), inWord.end(), badchars[i]), inWord.end()); // thanks stack overflow
        }
        transform(inWord.begin(), inWord.end(), inWord.begin(), ::tolower);
        bool exists = inDick.find(inWord)!=inDick.end();
        if (exists) {}
        else
            cout << "Misspelled Word Detected = " << inWord << "\n";
    }
}

Dictionary LoadFile(Dictionary inDick)
{
    string word;
    ifstream dictionaryfile ("dictionary.txt");
    if ( dictionaryfile.is_open())
    {
        while (getline(dictionaryfile, word))
        {
            inDick.insert(word);
            //cout << word << "\n";
        }
        dictionaryfile.close();
        return inDick;
    }
    else
    {
        cout << "Unable to load file.";
    }
}
