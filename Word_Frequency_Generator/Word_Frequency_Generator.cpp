#include "stdafx.h"
#include "Word_Frequency.h"


int main()
{
	map<string, size_t> word_count;
	CountWordFrequencyFromFile("../word.txt",word_count);
	
	auto word_freq = SortWordFrequency(word_count);
	
	for (auto element : word_freq)
		cout << element.first << " " << element.second << endl;
	return 0;
}

