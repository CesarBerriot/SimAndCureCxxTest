//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include "Logic/Logic.hpp"
#include "DataTypes/DataTypes.hpp"

extern DataTypes::EvaluatedWords_t list;

TEST(SumListScoreTest, CorrectCase)
{	EXPECT_EQ(Logic::SumListScore(list), 860);
}

DataTypes::EvaluatedWords_t list =
{	{ L"vêt", 93 },
	{ L"mûr", 98 },
	{ L"Dès", 113 },
	{ L"glaçons", 121 },
	{ L"Noël", 127 },
	{ L"zéphyr", 142 },
	{ L"würmiens", 166 },
};
