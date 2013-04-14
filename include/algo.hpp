#ifndef ALGO_HPP
#define ALGO_HPP

#include <vector>

class algo {
	/*previous generation*/
	struct focus {
		bool p[3];
		bool t[3];
		bool n[3];
		bool ready;
	};
	std::vector<bool> pGen;
	int width;
	int height;
	struct focus lense;
public:
	algo (const std::vector<bool>& iGen, int offset);
	~algo ();
	
	/*returns the next generation to the referenced vector*/
	int nextGen(std::vector<bool>& nGen); 

private:
	bool islife();
	int fill(bool pRow, bool tRow, bool nRow);
};
#endif
