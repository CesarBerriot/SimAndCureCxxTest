#include <cstdlib>
#include <iostream>
#include "Logic/Logic.hpp"
#include "DataTypes/DataTypes.hpp"

int main(int argumentsLength, char ** arguments)
{	// validate program arguments
	Logic::ValidateArguments(argumentsLength, arguments);

	// make sure the global locale supports unicode characters
	Logic::ApplyUnicodeLocale();

	// obtain the file path from said arguments
	std::string filePath = Logic::ObtainFilePathFromArguments(arguments);

	// create a word list and go through all required algorithms
	auto wordList = DataTypes::WordList(filePath);
	wordList.RemoveDuplicates();
	wordList.CountScores();
	wordList.SortByScores();

	// obtain a result from the word list
	DataTypes::EvaluatedWords_t result = wordList.GetWords();

	// obtain the path to the .count.txt file
	std::string countFilePath = Logic::ObtainCountFilePathFromFilePath(filePath);

	// output the resulted information into the .count.txt file
	Logic::OutputListToFile(countFilePath, result);

	// calculate the total file score
	int totalScore = Logic::SumListScore(result);

	// output basic result information to the console
	Logic::OutputResultInfoToConsole(result.size(), totalScore, countFilePath);

	// success
	return EXIT_SUCCESS;
}
