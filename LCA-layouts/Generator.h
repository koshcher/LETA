#ifndef Generator_h
#define Generator_h

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class Generator
{
private:
	vector<string> _allWords;
	vector<string> _text;
    int _quantity;

public:
	Generator()
    {
        srand(time(NULL));
        ReadFile();
	}

    void ReadFile()
    {
        string line;
        ifstream in("words.txt");
        if (in.is_open())
        {
            while (getline(in, line))
            {
                _allWords.push_back(line);
            }
        }
        in.close();
    }

    void GenText(const int& quantity) 
    {
        this->_quantity = quantity;
        _text.clear();
        for (int i = 0; i < quantity; i++) 
        {
            _text.push_back(_allWords[rand() % _allWords.size()]);
        }
    }

    string GetText() 
    {
        string res;
        for (int i = 0; i < _quantity; i++) 
        {
            res += _text[i];
            if (i < (_quantity - 1)) 
            {
                res += ' ';
            }
        }
        return res;
    }

    const vector<string>& GetWords() { return _text; }
    int GetCount() { return _quantity; }

};

#endif
