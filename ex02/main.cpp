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
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << " \t\t\t\tpend" << std::endl;
    pmergeMe.print_vect(pmergeMe.pend.first);
    std::cout << " \t\t\t\tmain_chain" << std::endl;
    pmergeMe.print_vect(pmergeMe.main_chain);
    // std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    // pmergeMe.insertion();
    // std::cout << " \t\t\t\tpend" << std::endl;
    // pmergeMe.print_vect(pmergeMe.pend.first);
    // std::cout << " \t\t\t\tmain_chain" << std::endl;
    // pmergeMe.print_vect(pmergeMe.main_chain);
    // pmergeMe.insertion();
    // std::cout << " \t\t\t\tpend" << std::endl;
    // pmergeMe.print_vect(pmergeMe.pend.first);
    // std::cout << " \t\t\t\tmain_chain" << std::endl;
    // pmergeMe.print_vect(pmergeMe.main_chain);
}
