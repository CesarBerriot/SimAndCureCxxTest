//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include "Utils/Utils.hpp"

TEST(FailWithErrorTest, CorrectCase)
{	std::string errorMessage = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	ASSERT_EXIT(Utils::FailWithError(errorMessage), testing::ExitedWithCode(EXIT_FAILURE), errorMessage);
}
