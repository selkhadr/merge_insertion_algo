#include "PmergeMe.hpp"

PmergeMe::PmergeMe():vect(), rest()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    vect = obj.vect;
    rest = obj.rest;
    return (*this);
}

// int PmergeMe::insertion(int ac, char **av)
// {

// }

int PmergeMe::fill_vector(int ac, char **av)
{
    int i;
    char    **endl;

    i = 1;
    endl = NULL;
    while (i < ac)
    {
        std::vector<int> tmp;
        int nmb = static_cast<int>(strtod(av[i], endl));
        tmp.push_back(nmb);
        vect.push_back(tmp);
        std::cout << vect[i-1][0] << std::endl;
        i++;
    }
    std::cout << "\n\n\n" << std::endl;
    std::vector<std::vector<int> >::iterator it;
    it = vect.begin();
    while (it != vect.end())
    {
        std::vector<int>::iterator j = (*it).begin();
        while (j != (*it).end())
        {
            std::cout << *j << std::endl;
            j++;
        }
        it++;
    }
    return 0;
}
