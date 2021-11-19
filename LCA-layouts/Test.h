#ifndef TEST_H
#define TEST_H

#include "wx/wx.h"

class Test
{
private:
	int all_words;
	int right_words;
	double time;

	int wpm;
	int acc;

public:
	Test() : right_words{ 0 }, all_words{ 0 }, time{ 1 }, wpm{ 0 }, acc{ 0 } {}

	void SetTime(double timer)
	{
		time = timer;
	}

	void SetWords(int all_words_count) 
	{
		all_words = all_words_count;
	}

	void Reset() 
	{
		all_words = 0;
		right_words = 0;
		time = 1;
		wpm = 0; 
		acc = 0;
	}

	void operator++(int) 
	{
		right_words++;
	}

	void Result() 
	{
		wpm = right_words * (60 / time) * (-1);
		if (all_words == 0)
		{
			acc = 0;
		}
		else 
		{
			acc = (right_words * 1.0 / all_words * 1.0) * 100;
		}
	}
	
	int WPM() { return wpm; }
	int ACC() { return acc; }
};

#endif