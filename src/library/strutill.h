#pragma once
#include <vector>
#include <string>

std::vector<std::string> split(std::string input, char delimiter);
std::string join(std::vector<std::string> input, char insertStr);
std::string trim(std::string input);