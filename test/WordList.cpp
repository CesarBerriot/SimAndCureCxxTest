//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include <fstream>
#include "DataTypes/DataTypes.hpp"

TEST(WordListTest, InvalidPath)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

	DataTypes::WordList * wordList;
	ASSERT_EXIT(wordList = new DataTypes::WordList("/invalid/file/path.txt"), testing::ExitedWithCode(EXIT_FAILURE), "");

#pragma GCC diagnostic pop
}

TEST(WordListTest, CorrectCase)
{	// constants
	std::string filePath = "WordListTestFile.txt";
	std::string fileContents = "rô+s  dîne, Dès.\n\nglaçons;\tvêt’mûr. vêt'rô+s";
	DataTypes::EvaluatedWords_t expectedPostCtorList = { { L"rô+s", 0 }, { L"dîne", 0 }, { L"Dès", 0 }, { L"glaçons", 0 }, { L"vêt", 0 }, { L"mûr", 0 }, { L"vêt", 0 }, { L"rô+s", 0 }, };
	DataTypes::EvaluatedWords_t expectedPostDuplicatesRemovalList = { { L"dîne", 0 }, { L"Dès", 0 }, { L"glaçons", 0 }, { L"mûr", 0 }, { L"vêt", 0 }, { L"rô+s", 0 }, };
	DataTypes::EvaluatedWords_t expectedPostScoreCountingList = { { L"dîne", 88 }, { L"Dès", 113 }, { L"glaçons", 121 }, { L"mûr", 98 }, { L"vêt", 93 }, { L"rô+s", 91 }, };
	DataTypes::EvaluatedWords_t expectedPostSortingList = { { L"dîne", 88 }, { L"rô+s", 91 }, { L"vêt", 93 }, { L"mûr", 98 }, { L"Dès", 113 }, { L"glaçons", 121 }, };

	// create a test file and write fileContents into it
	std::ofstream stream(filePath);
	ASSERT_TRUE(stream.is_open()) << "failed to open/create the test file";
	stream << fileContents;
	stream.close();

	// construct a WordList
	DataTypes::WordList wordList(filePath);
	ASSERT_EQ(wordList.GetWords(), expectedPostCtorList) << "WordList ctor failed";

	// remove duplicates
	wordList.RemoveDuplicates();
	ASSERT_EQ(wordList.GetWords(), expectedPostDuplicatesRemovalList) << "WordList duplicates removal failed";

	// count scores
	wordList.CountScores();
	ASSERT_EQ(wordList.GetWords(), expectedPostScoreCountingList) << "WordList score counting failed";

	// sort by score
	wordList.SortByScores();
	ASSERT_EQ(wordList.GetWords(), expectedPostSortingList) << "WordList sorting by scores failed";
}