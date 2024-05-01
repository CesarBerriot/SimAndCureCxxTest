//
// Created by César B. on 5/1/2024.
//

#pragma once

#include <string>
#include "DataTypes/DataTypes.hpp"

namespace Logic
{	void ValidateArguments(int argumentsLength, char ** arguments);
	void ApplyUnicodeLocale();
	std::string ObtainFilePathFromArguments(char ** arguments);
	std::string ObtainCountFilePathFromFilePath(std::string filePath);
	int SumWordScore(std::wstring word);
	int SumListScore(DataTypes::EvaluatedWords_t);
	void OutputListToFile(std::string filePath, DataTypes::EvaluatedWords_t);
	void OutputResultInfoToConsole(int resultListLength, int totalScore, std::string countFilePath);
}
