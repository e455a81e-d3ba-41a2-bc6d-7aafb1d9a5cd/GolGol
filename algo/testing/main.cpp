#include <cstdlib>
#include <iostream>
#include <vector>
#include "../../include/algo.hpp"

int main(int argc, const char *argv[])
{

	int width = 10;

	std::cout << "Hello, GolGol" << std::endl;
	std::vector<bool> test(width * width);
	std::vector<bool> out(width * width);
	for (int i = 0; i < (width * width); i++) {
			test.push_back(0);
	}

	test[45] = 1;
	test[46] = 1;
	test[47] = 1;
	
	algo *generations = new algo(test, width);
	generations->nextGen(out);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
		std::cout << out[i * width + j];
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
