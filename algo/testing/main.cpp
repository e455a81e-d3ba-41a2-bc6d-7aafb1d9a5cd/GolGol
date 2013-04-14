#include <cstdlib>
#include <iostream>
#include <vector>
#include "../../include/algo.hpp"

int main(int argc, const char *argv[])
{

	int height = 5;
	int width = 5;

	std::cout << "Hello, GolGol";
	std::vector<bool> test;
	std::vector<bool> out;
	for (int i = 0; i < (height * width); i++) {
		test[i] = 1;
	}
	
	algo generations = new algo(std::vector<bool>& test);
	generations.nextGen(std::vector<bool>& out);

	return EXIT_SUCCESS;
}
