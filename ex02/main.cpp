#include "PmergeVect.hpp"
#include "PmergeDeque.hpp"

int global_counter;

int PmergeDeque_fnct(int ac, char **av)
{
    PmergeDeque pmergeDeque;

    clock_t startTime = clock();
    if (ac <= 2)
    {
        std::cout << "please enter arguments" << std::endl;
        return 1;
    }
    if (pmergeDeque.fill_deque(ac, av))
        return 1;
    pmergeDeque.merge();
    pmergeDeque.insertion();
    clock_t endTime = clock();
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

    // Display the elapsed time
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << elapsedTime << " seconds" << std::endl;
    return 0;
}

int PmergeVector_fnct(int ac, char **av)
{
    PmergeVect pmergeVect;

    clock_t startTime = clock();
    if (ac <= 2)
    {
        std::cout << "please enter arguments" << std::endl;
        return 1;
    }
    if (pmergeVect.fill_vector(ac, av))
        return 1;
    pmergeVect.merge();
    pmergeVect.insertion();
    clock_t endTime = clock();
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

    // Display the elapsed time
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << elapsedTime << " seconds" << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    if (PmergeVector_fnct(ac, av))
        return 1;
    if (PmergeDeque_fnct(ac, av))
        return 1;
    std::cout << global_counter << std::endl;
    return 0;
}
