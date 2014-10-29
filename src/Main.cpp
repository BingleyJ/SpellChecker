#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

typedef set<string> Dictionary;

Dictionary LoadFile(Dictionary inDick);
void CheckWords(Dictionary inDick);

int main()
{
    clock_t start;
    double duration;
    cout << "|-- Spell Checker --|\n";
    Dictionary dictionary;
    start = clock();
    dictionary = LoadFile(dictionary);
    bool quit = false;
    string inWord;
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Loaded "<< dictionary.size() << " words in " << duration << " seconds.\n";

   // cout << (string)dictionary.find("aaa");
    CheckWords(dictionary);
    return 0;
}


void CheckWords(Dictionary inDick )
{
    int badwordcount = 0;
    int goodwordcount = 0;

    string filename;
    bool goodfilename = false;
    while (!goodfilename)
    {
        cout << "\nPlease enter the file to spell check :";
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
    clock_t start;
    double duration;
    start = clock();
    while (file >> inWord)
    {
        char badchars[] = ".,}{[]();:!@#$%^&*/?><=-+_'12345567890\"";
        for (unsigned int i = 0; i < strlen(badchars); ++i)
        {
            inWord.erase(remove(inWord.begin(), inWord.end(), badchars[i]), inWord.end()); // thanks stack overflow strips badchars
        }
        transform(inWord.begin(), inWord.end(), inWord.begin(), ::tolower); // thanks stack overflow lower case the string
        bool exists = inDick.find(inWord)!=inDick.end();
        if (exists) {goodwordcount++;}
        else{
            cout << "Misspelled Word @ Entry #" << badwordcount+goodwordcount << " [" << inWord << "]\n";
            //suggest shtuff :(
        badwordcount++;
        }
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "\n" << badwordcount << " misspelled words detected.\n";
    cout <<  goodwordcount << " correctly spelled words detected.\n";
    cout << badwordcount + goodwordcount << " words checked in " << duration << " seconds.";

}

Dictionary LoadFile(Dictionary inDick)
{
    string word;
    ifstream dictionaryfile ("dictionary.txt");
    cout<<"Loading Dictionary File ...\n";
    if ( dictionaryfile.is_open())
    {
        while (getline(dictionaryfile, word))
        {
            inDick.insert(word);
        }
        dictionaryfile.close();
        cout << "Loading Complete!\n";
        return inDick;
    }
    else
    {
        cout << "Unable to load file.";
    }
}
