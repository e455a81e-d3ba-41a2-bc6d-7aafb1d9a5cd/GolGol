#ifndef ALGO_HPP
#define ALGO_HPP

#include <vector>
#include <iostream>

class algo {
	std::vector<bool> pGen;
	int width;

public:
	algo (const std::vector<bool>& iGen, int offset);
	~algo ();
	
	/*returns the next generation to the referenced vector*/
	int nextGen(std::vector<bool>& nGen); 

private:
	int islife(int row, int col, int width);
};
#endif
