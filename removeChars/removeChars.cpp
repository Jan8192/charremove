// removeChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>

std::string removeChars(const std::string& source, const std::string& chars) {
	std::string result = "";
	for (unsigned int i = 0; i < source.length(); i++) {
		bool foundany = false;
		for (unsigned int j = 0; j < chars.length() && !foundany; j++) {
			foundany = (source[i] == chars[j]);
		}
		if (!foundany) {
			result += source[i];
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	// open the file
	std::ifstream inFile(argv[1]);

	// get file content as string.
	std::string fileString((std::istreambuf_iterator<char>(inFile)),
		std::istreambuf_iterator<char>());

	std::string outString = removeChars(fileString, argv[2]);

	std::ofstream outStream("result.txt");

	outStream << outString;

	outStream.close();

	std::cin.get();
	return 0;
}