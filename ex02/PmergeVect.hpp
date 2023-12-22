#ifndef PMERGEVECT_HPP
# define PMERGEVECT_HPP

# include <vector>
# include <iostream>
# include <cstdlib>
# include <ctime>


class PmergeVect
{
private:
public:
    std::vector<std::vector<int> >		main_chain;
    std::vector<std::vector<int> >		pend;
    std::vector<int>				    main_iterator;
    std::vector<std::vector<int> >		vect;
    std::vector<std::vector<int> >		rest;
    std::vector<std::vector<int> >		tmp;
    std::vector<int>					combination;
    PmergeVect();
    ~PmergeVect();
    PmergeVect(const PmergeVect &obj);
    PmergeVect &operator=(const PmergeVect &obj);
	//
    int		fill_vector(int ac, char **av);
    int		merge(void);
    int		insertion(void);
    void	creat_combination(void);
    void	insert_pend(std::vector<std::vector<int> >::iterator begin, std::vector<std::vector<int> >::iterator end, std::vector<int> value);
    void	print_vect(std::vector<std::vector<int> > vect, std::string string);
    void	creat_tmp_vector();
    void	creat_main_chain();
    void	creat_pend();
    void	insert_pend_inside_main_chain();
	void	increment_indexes(size_t start);
    void    print_main_iter();
};

#endif