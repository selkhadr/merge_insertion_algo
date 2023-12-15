#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>
# include <cstdlib>
// # include <algorithm>

class PmergeMe
{
private:
public:
    std::vector<std::vector<int> > vect;
    std::vector<std::vector<int> > rest;
    std::vector<std::vector<int> > main_chain;
    std::vector<int>                combination;
    std::pair<std::vector<std::vector<int> >, std::vector<std::vector<std::vector<int> >::iterator> > pend;
    std::vector<std::vector<int> >::iterator lower_bound_it;
    // std::vector<int>::iterator it;
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    int fill_vector(int ac, char **av);
    int merge(int ac, char **av);
    int insertion(void);
    void creat_combination(void);
    void insert_pend(std::vector<std::vector<int> >::iterator begin, std::vector<std::vector<int> >::iterator end, std::vector<int> value);
    //delete_me
    void    print_vect(std::vector<std::vector<int> > vect);
};

#endif