//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include "Logic/Logic.hpp"

TEST(ValidateArgumentsTest, CorrectCase)
{	std::vector<char const *> arguments = { "path/to/executable", "path/to/file.txt" };
	Logic::ValidateArguments(arguments.size(), (char **)arguments.data());
}

TEST(ValidateArgumentsTest, NotEnoughArguments)
{	std::vector<char const *> arguments = { "path/to/executable" };
	ASSERT_EXIT(
		Logic::ValidateArguments(arguments.size(), (char **)arguments.data()),
		testing::ExitedWithCode(EXIT_FAILURE),
		"expected 1 argument, received 0"
	);
}

TEST(ValidateArgumentsTest, TooManyArguments)
{	std::vector<char const *> arguments = { "path/to/executable", "path/to/someFile.txt", "path/to/someOtherFile.txt" };
	ASSERT_EXIT(
		Logic::ValidateArguments(arguments.size(), (char **)arguments.data()),
		testing::ExitedWithCode(EXIT_FAILURE),
		"expected 1 argument, received 2"
	);
}

TEST(ValidateArgumentsTest, Directory)
{	std::vector<char const *> arguments = { "path/to/executable", "path/to/someDirectory" };
	ASSERT_EXIT(
		Logic::ValidateArguments(arguments.size(), (char **)arguments.data()),
		testing::ExitedWithCode(EXIT_FAILURE),
		"expected the given path to end with \".txt\""
	);
}

TEST(ValidateArgumentsTest, NotATextFile)
{	std::vector<char const *> arguments = { "path/to/executable", "path/to/someFile.mp4" };
	ASSERT_EXIT(
		Logic::ValidateArguments(arguments.size(), (char **)arguments.data()),
		testing::ExitedWithCode(EXIT_FAILURE),
		"expected the given path to end with \".txt\""
	);
}