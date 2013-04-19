#include "../include/algo.hpp"

algo::algo(const std::vector<bool>& iGen, int offset)
{
	pGen = iGen;
	width = offset;
	lense.ready = 0;
}

algo::~algo()
{

}

int algo::nextGen(std::vector<bool>& nGen)
{
	int cellSet, row, col, life;
	for (row = 0; row < width; row++) {
		for (col = 0; col < width; col++) {
			life = islife(row, col, width);
			cellSet = pGen[width * row + col];
			if (cellSet) {
				if((life > 3) || (life < 2)) {
					nGen[width * row + col] = 0;
				} else {
					nGen[width * row + col] = 1;
				}
			} else {
				if(life == 3) {
					nGen[width * row + col] = 1;
				} else {
					nGen[width * row + col] = 0;
				}
			}
		}
	}
	return 0;

}

int algo::islife(int row, int col, int size)
{
	int x, y, a = 0;
	for(x = row - 1; x <= (row + 1); x++) {

		for(y = col - 1; y <= (col + 1); y++) {

			if ((x == row) && (y== col)) {
				continue;
			}
			if ((y < size) && (x < size) && (x>=0) && (y>=0)) {
				a += (int)pGen[size * x + y];
			}
		}
	}
	return a;
}

