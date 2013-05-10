#include "../include/algo.hpp"

algo::algo(const std::vector<bool>& iGen, int offset)
{
	pGen = iGen;
	width = offset;
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
	pGen = nGen;
	return 0;

}

int algo::islife(int row, int col, int width)
{
	int x, y, a = 0;
	int nx, ny;
	for(x = row - 1; x <= (row + 1); x++) {

		for(y = col - 1; y <= (col + 1); y++) {

			nx = x;
			ny = y;

			if ((x == row) && (y== col)) {
				continue;
			}

			if ((y < width) && (x < width) && (x>=0) && (y>=0)) {
				a += (int)pGen[width * x + y];
			} else {
			
				if (x >= width) {
					nx = x - width;
				} else if (x<0) {
					nx = x + width;
				}


				if (y >= width) {
					ny = y - width;
				} else if (y<0)
				{
					ny = y + width;
				}
				a += (int)pGen[width * nx + ny];
			}

		}
	}
	return a;
}
