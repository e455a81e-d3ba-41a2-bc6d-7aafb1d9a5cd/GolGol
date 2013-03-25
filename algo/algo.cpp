#include "../include/algo.hpp"
#include <vector>

algo::algo(std::vector<bool> i_gen, int offset)
{
	p_gen = i_gen;
	width = offset;
	height = p_gen.size() / width;
}

algo::~algo()
{

}

int algo::next_gen(std::vector<bool>& n_gen)
{
	int value = 0;
	for (unsigned pos = 0; pos < p_gen.size(); pos++) {
		
	}
}
