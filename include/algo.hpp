#ifndef ALGO_HPP
#define ALGO_HPP

class algo {
	/*previous generation*/
	std::vector<gboolean> p_gen;
public:
	algo (const std::vector<gboolean>& i_gen, int size);
	~algo ();
	
	/*returns the next generation to the referenced vector*/
	int next_gen(std::vector<gboolean>& n_gen); 

private:
	/* data */
};
#endif
