#include <cstdlib>
#include <iostream>
#include <vector>
#include "../../include/algo.hpp"

int show(std::vector<bool>& out, int width) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
		std::cout << out[i * width + j];
		}
		std::cout << std::endl;
	}
	return 0;
}

int main(int argc, const char *argv[])
{

	int width = 10;

	std::cout << "Hello, GolGol" << std::endl;
	std::vector<bool> test(width * width);
	std::vector<bool> out(width * width);
	for (int i = 0; i < (width * width); i++) {
			test.push_back(0);
	}

	test[39] = 1;
	test[48] = 1;
	test[49] = 1;
	test[59] = 1;
	test[50] = 1;
	
	show(test, width);
	algo *generations = new algo(test, width);
	for(int i = 0; i < 100; i++) {
		generations->nextGen(out);
		show(out, width);
	}
	return EXIT_SUCCESS;
}
