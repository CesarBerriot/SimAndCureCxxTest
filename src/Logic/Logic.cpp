//
// Created by César B. on 5/1/2024.
//

#include "logic.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include "Utils/Utils.hpp"
#include "Macros/Macros.hpp"
#include "Constants/Constants.hpp"
#include "Globals/Globals.hpp"

void Logic::ValidateArguments(int argumentsLength, char ** arguments)
{	// validate argument vector length
	if(argumentsLength != 2)
		Utils::FailWithError(MAKE_STRING("expected 1 argument, received " << (argumentsLength - 1) << ".\n" << Constants::MSG_USAGE));

	std::string filePath = arguments[1];

	// make sure filePath ends with ".txt"
	std::string expectedExtension = ".txt";
	if(filePath.length() < expectedExtension.length() || expectedExtension.compare(filePath.data() + filePath.length() - expectedExtension.length()))
		Utils::FailWithError(MAKE_STRING("expected the given path to end with \".txt\".\n" << Constants::MSG_USAGE));
}

void Logic::ApplyUnicodeLocale()
{	char targetLocale[] = "C.UTF-8";
	char * result = setlocale(LC_ALL, targetLocale);
	if(!result || strcmp(result, targetLocale))
		Utils::FailWithError(MAKE_STRING("failed to set the global locale to " << targetLocale << '.'));
}

std::string Logic::ObtainFilePathFromArguments(char ** arguments)
{	return arguments[1];
}

std::string Logic::ObtainCountFilePathFromFilePath(std::string filePath)
{	filePath.erase(filePath.end() - strlen(".txt"), filePath.end());
	filePath.append(".count.txt");
	return filePath;
}

int Logic::SumWordScore(std::wstring word)
{	int result = 0;
	for(wchar_t character : word)
		if(Globals::wordScoresMap.count(character))
			result += Globals::wordScoresMap[character];
	return result;
}

int Logic::SumListScore(DataTypes::EvaluatedWords_t words)
{	int result = 0;
	for(auto pair : words)
		result += pair.score;
	return result;
}

void Logic::OutputListToFile(std::string filePath, DataTypes::EvaluatedWords_t words)
{	std::wofstream stream(filePath);
	if(!stream.is_open())
		Utils::FailWithError(MAKE_STRING("failed to open '" << filePath << "'."));
	for(auto pair : words)
		stream << pair.word << ", " << pair.score << '\n';
}

void Logic::OutputResultInfoToConsole(int resultListLength, int totalScore, std::string countFilePath)
{
	std::wcout << "scored " << resultListLength << " words with a total of " << totalScore << " points.\n"
			   << "outputted detailed score information to '" << countFilePath.c_str() << "'.\n";
}
