#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

std::vector<std::string> ReadFileForVector(std::string filePath);
std::string ReadFile(std::string filePath);
std::vector<std::string> ReadTalkTextFile(std::string filePath);