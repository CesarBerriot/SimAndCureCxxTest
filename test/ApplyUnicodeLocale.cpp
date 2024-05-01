//
// Created by César B. on 5/1/2024.
//

#include <gtest/gtest.h>
#include "Logic/Logic.hpp"

TEST(ApplyUnicodeLocaleTest, CorrectlyApplied)
{	// set the locale to "C"
	char * initialLocale = setlocale(LC_ALL, "C");
	// make sure it's been successfully set
	ASSERT_NE(initialLocale, nullptr) << "setlocale() failed with nullptr while initializing the test";
	ASSERT_EQ(strcmp(initialLocale, "C"), 0) << "setlocale() failed with '" << initialLocale << "' while initializing the test";
	// call ApplyUnicodeLocale()
	Logic::ApplyUnicodeLocale();
	// get the current locale
	char * newLocale = setlocale(LC_ALL, nullptr);
	// make sure it's been successfully set to "C.UTF-8"
	ASSERT_NE(newLocale, nullptr) << "setlocale() failed with nullptr while obtaining the new locale string";
	ASSERT_EQ(strcmp(newLocale, "C.UTF-8"), 0) << "the locale hasn't been set correctly";
}
