#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>

class PmergeMe
{
private:
public:
    std::vector<std::vector<int> > vect;
    std::vector<std::vector<int> > rest;
    std::vector<std::vector<int> > main_chain;
    std::vector<std::vector<int> > pend;
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    int fill_vector(int ac, char **av);
    int merge(int ac, char **av);
    int insertion(void);

    //delete_me
    void    print_vect(std::vector<std::vector<int> > vect);
};

#endif