//
// Created by César B. on 5/1/2024.
//

#include "Utils.hpp"
#include <iostream>

void Utils::FailWithError(std::string errorMessage)
{	std::cerr << errorMessage;
	exit(EXIT_FAILURE);
}
