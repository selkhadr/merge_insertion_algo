#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmergeMe;

    pmergeMe.fill_vector(ac, av);
    pmergeMe.merge(ac, av);
    pmergeMe.insertion();
}
