#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>

class PmergeMe
{
private:
    std::vector<std::vector<int> > vect;
    std::vector<std::vector<int> > rest;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    int fill_vector(int ac, char **av);
    // int insertion(int ac, char **av);
};

#endif