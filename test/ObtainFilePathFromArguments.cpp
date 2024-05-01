//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include "Logic/Logic.hpp"

TEST(ObtainFilePathFromArgumentsTest, CorrectCase)
{	char const * arguments[] = { "1", "2", "3", "4" };
	ASSERT_EQ(Logic::ObtainFilePathFromArguments((char **)arguments).compare("2"), 0);
}
