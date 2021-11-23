#ifndef TEST_H
#define TEST_H

#include "wx/wx.h"

class Test
{
private:
	int _allWordsCount;
	int _rightWordsCount;
	double _time;

	int _wpm;
	int _acc;

public:
	Test() : _rightWordsCount{ 0 }, _allWordsCount{ 0 }, _time{ 1 }, _wpm{ 0 }, _acc{ 0 } {}

	void SetTime(double timer)
	{
		_time = timer;
	}

	void SetWords(int all_words_count) 
	{
		_allWordsCount = all_words_count;
	}

	void Reset() 
	{
		_allWordsCount = 0;
		_rightWordsCount = 0;
		_time = 1;
		_wpm = 0; 
		_acc = 0;
	}

	void operator++(int) 
	{
		_rightWordsCount++;
	}

	void Result() 
	{
		_wpm = _rightWordsCount * (60 / _time) * (-1);
		if (_allWordsCount == 0)
		{
			_acc = 0;
		}
		else 
		{
			_acc = (_rightWordsCount * 1.0 / _allWordsCount * 1.0) * 100;
		}
	}
	
	int WPM() { return _wpm; }
	int ACC() { return _acc; }
};

#endif