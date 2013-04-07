#ifndef ALGO_HPP
#define ALGO_HPP

class algo {
	/*previous generation*/
	struct focus {
		bool p[3];
		bool t[3];
		bool n[3];
	};
	std::vector<bool> pGen;
	int width;
	int height;
public:
	algo (const std::vector<bool>& iGen, int offset);
	~algo ();
	
	/*returns the next generation to the referenced vector*/
	int nextGen(std::vector<bool>& nGen); 

private:
	int islife(bool *pRow, bool *tRow, bool *nRow);
	int fill(bool *pRow, bool *tRow, bool *nRow);
};
#endif
