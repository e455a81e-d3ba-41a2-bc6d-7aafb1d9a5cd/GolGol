#include "../include/algo.hpp"
#include "data.hpp"
#include <vector>

algo::algo(std::vector<bool>& iGen, int offset)
{
	pGen = iGen;
	width = offset;
	height = pGen.size() / width;
}

algo::~algo()
{

}

int algo::nextGen(std::vector<bool>& nGen)
{
	
}

int algo::fill(bool *pRow, bool *tRow, bool *nRow)
{

}

int algo::islife(bool *pRow, bool *tRow, bool *nRow)
{

}

