//
// Created by César B. on 5/1/2024.
//

#pragma once

#include <sstream>

#define MAKE_STRING(...) (std::stringstream() << __VA_ARGS__).str()
#define MAKE_WSTRING(...) (std::wstringstream() << __VA_ARGS__).str()
