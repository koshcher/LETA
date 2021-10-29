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
	string text;

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

    string GenText(const int& quantity) {
        text.clear();
        for (int i = 0; i < quantity; i++) {
            text += all_words[rand() % all_words.size()];
            if (i < (quantity - 1)) {
                text += ' ';
            }
        }
        return text;
    }

    string Get_text() {
        return text;
    }

    void Add(string& src_str) {
        all_words.push_back(src_str);
    }

    void Save() {

        ofstream out;
        out.open("words.txt"); 
        
        if (out.is_open())
        {
            for (int i = 0; i < all_words.size(); i++) {
                out << all_words[i] << endl;
            }
        }
        out.close();
    }

};

#endif
