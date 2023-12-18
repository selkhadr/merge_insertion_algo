#include "PmergeVect.hpp"

int PmergeVector(int ac, char **av)
{
    PmergeVect PmergeVect;

    clock_t startTime = clock();
    if (ac <= 2)
    {
        std::cout << "please enter arguments" << std::endl;
        return 1;
    }
    if (PmergeVect.fill_vector(ac, av))
        return 1;
    PmergeVect.merge();
    PmergeVect.insertion();
    clock_t endTime = clock();
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

    // Display the elapsed time
    std::cout << "Elapsed time: " << elapsedTime << " seconds" << std::endl;
    return 0;
}


int main(int ac, char **av)
{
    if (PmergeVector(ac, av))
        return 1;
    return 0;
}