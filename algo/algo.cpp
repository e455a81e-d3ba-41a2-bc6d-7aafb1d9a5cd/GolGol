#include "../include/algo.hpp"

algo::algo(const std::vector<bool>& iGen, int offset)
{
	pGen = iGen;
	width = offset;
	height = pGen.size() / width;
	lense.ready = 0;
}

algo::~algo()
{

}

int algo::nextGen(std::vector<bool>& nGen)
{
	for (int i = 0; i < 3; i++) {
		lense.p[i] = pGen[0 + i];
		lense.t[i] = pGen[width + 1 + i];
		lense.n[i] = pGen[width * 2 + 1 + i];
	}
	lense.ready = 1;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			nGen[i * width + j] = islife();

			fill(
				pGen[i * width + j], 
				pGen[(i + 1) * width +j], 
				pGen[(i + 2) * width + j]
			); 
		}
	}

}

int algo::fill(bool pRow, bool tRow, bool nRow)
{
	switch(lense.ready) {
	case 0:
		return -1;
	case 1:
		lense.p[0] = lense.p[1];
		lense.p[1] = lense.p[2];
		lense.p[2] = pRow;

		lense.t[0] = lense.t[1];
		lense.t[1] = lense.t[2];
		lense.t[2] = tRow;

		lense.n[0] = lense.n[1];
		lense.n[1] = lense.n[2];
		lense.n[2] = nRow; /*kill me*/

		break;
	}

}

bool algo::islife()
{
	int result = 0;

	for (int i = 0; i < 3; i++) {
		result += (lense.p[i] + lense.t[i]+ lense.n[i]);
	}

	if (result < 2) {
		return 0;
	} else if (result <=3) {
		return 1;
	} else {
		return 0;
	}
}

