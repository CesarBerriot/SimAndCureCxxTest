//
// Created by César B. on 5/1/2024.
//

#include "WordList.hpp"
#include <unistd.h>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "Utils/Utils.hpp"
#include "Logic/Logic.hpp"
#include "Macros/Macros.hpp"

bool DataTypes::WordScorePair::operator==(DataTypes::WordScorePair other) const
{	return word == other.word && score == other.score;
}

DataTypes::WordList::WordList(std::string filePath)
{	Logic::ApplyUnicodeLocale();

	// open the file for reading
	std::wifstream stream(filePath);
	if(!stream.is_open())
		Utils::FailWithError("failed to open the requested file.");

	// read the file into a wstring
	std::wstring fileData = MAKE_WSTRING(stream.rdbuf());

	// separate words and write them into our list
	std::wstring currentWord;
	std::vector separatorCharacters = { L' ', L',', L'.', L';', L'’', L'\'', L'\r', L'\n', L'\t' };
	for(wchar_t character : fileData)
	{	bool separates = std::count(separatorCharacters.begin(), separatorCharacters.end(), character);
		if(separates)
		{	if(currentWord.length())
				words.push_back({ currentWord, 0 });
			currentWord.erase(currentWord.begin(), currentWord.end());
		}
		else
			currentWord.push_back(character);
	}
	if(currentWord.length())
		words.push_back({ currentWord, 0 });
}

void DataTypes::WordList::RemoveDuplicates()
{	for(size_t i = 0; i < words.size();)
		if(std::count(words.begin(), words.end(), words[i]) > 1)
			words.erase(words.begin() + i);
		else
			++i;
}

void DataTypes::WordList::CountScores()
{	for(auto & pair : words)
		pair.score = Logic::SumWordScore(pair.word);
}

void DataTypes::WordList::SortByScores()
{	std::sort(words.begin(), words.end(), [](auto a, auto b) { return a.score < b.score; });
}
