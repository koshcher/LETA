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
	vector<string> all_words;
	vector<string> text;
    int quantity;

public:
	Generator() {
        srand(time(NULL));
        ReadFile();
	}

    void ReadFile() {
        string line;
        ifstream in("words.txt");
        if (in.is_open())
        {
            while (getline(in, line))
            {
                all_words.push_back(line);
            }
        }
        in.close();
    }

    void GenText(const int& quantity) {
        this->quantity = quantity;
        text.clear();
        for (int i = 0; i < quantity; i++) {
            text.push_back(all_words[rand() % all_words.size()]);
            
        }
    }

    string GetText() {
        string res;
        for (int i = 0; i < quantity; i++) {
            res += text[i];
            if (i < (quantity - 1)) {
                res += ' ';
            }
        }
        return res;
    }
    const vector<string>& GetWords() { return text; }
    int GetCount() { return quantity; }

};

#endif
