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
    int counter_words;
public:
	Generator() {
        srand(time(NULL));
        string line;
        ifstream in("word.txt");
        counter_words = 0;
        if (in.is_open())
        {
            while (getline(in, line))
            {
                   all_words.push_back(line);
                   counter_words++;
            }
        }
        in.close();   
	}
    void Read_from_file() {
        string line;
        ifstream in("word.txt");
        counter_words = 0;
        if (in.is_open())
        {
            while (getline(in, line))
            {
                all_words.push_back(line);
                counter_words++;
            }
        }
        in.close();
    }
    string& Generating_text(const int& quantity) {
        text.clear();
        for (int i = 0; i < quantity; i++) {
            text += all_words[rand() % counter_words];
            if (i < (quantity - 1)) {
                text += ' ';
            }
        }
        return text;
    }
    string& Get_text() {
        return text;
    }

    void Add(string& src_str) {
        all_words.push_back(src_str);
    }

    void Save() {

        ofstream out;
        out.open("word.txt"); 
        
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
