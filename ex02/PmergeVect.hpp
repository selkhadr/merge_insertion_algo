#ifndef PMERGEVECT_HPP
# define PMERGEVECT_HPP

# include <vector>
# include <iostream>
# include <cstdlib>
# include <ctime>


class PmergeVect
{
private:
    std::vector<std::vector<int> >		main_chain;
    std::vector<std::vector<int> >		pend;
    std::vector<int>				    main_iterator;
    std::vector<std::vector<int> >		vect;
    std::vector<std::vector<int> >		rest;
    std::vector<std::vector<int> >		tmp;
    std::vector<int>					combination;
public:
    PmergeVect();
    ~PmergeVect();
    PmergeVect(const PmergeVect &obj);
    PmergeVect &operator=(const PmergeVect &obj);
	//
    int		fill_vector(int ac, char **av);
    int		merge(void);
    int		insertion(void);
    void	print_vect(std::vector<std::vector<int> > vect, std::string string);
    void	creat_tmp_vector();
    void	creat_main_chain();
    void	creat_pend();
    void	insert_pend_inside_main_chain();
	void	increment_indexes(size_t start);
};

#endif