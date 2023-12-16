#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmergeMe;

    if (ac <= 2)
    {
        std::cout << "please enter arguments" << std::endl;
        return 1;
    }
    pmergeMe.fill_vector(ac, av);
    pmergeMe.merge(ac, av);
    pmergeMe.insertion();
    pmergeMe.print_vect(pmergeMe.main_chain);
}
