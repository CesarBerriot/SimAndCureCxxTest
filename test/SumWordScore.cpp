//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include "Logic/Logic.hpp"

TEST(SumWordScoreTest, CorrectCase)
{	EXPECT_EQ(Logic::SumWordScore(L"würmiens"), 166);
	EXPECT_EQ(Logic::SumWordScore(L"Noël"), 127);
	EXPECT_EQ(Logic::SumWordScore(L"glaçons"), 121);
	EXPECT_EQ(Logic::SumWordScore(L"Dès"), 113);
	EXPECT_EQ(Logic::SumWordScore(L"zéphyr"), 142);
}
