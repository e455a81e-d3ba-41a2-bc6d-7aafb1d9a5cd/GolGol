#ifndef ALGO_HPP
#define ALGO_HPP

class algo {
	/*previous generation*/
	std::vector<bool> p_gen;
	int width;
	int height;
public:
	algo (const std::vector<bool>& i_gen, int width);
	~algo ();
	
	/*returns the next generation to the referenced vector*/
	int next_gen(std::vector<bool>& n_gen); 

private:
	/* data */
};
#endif
