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

void    PmergeMe::print_vect(std::vector<std::vector<int> > vect)
{
    int i = 0;
    std::vector<std::vector<int> >::iterator it = vect.begin();

    std::cout << "\tprint_vect" << std::endl;
    while (it != vect.end())
    {
        std::vector<int>::iterator ite = vect[i].begin();
        while (ite != vect[i].end())
        {
            std::cout << *ite << " with size = " << vect[i].size() << std::endl;
            ite++;
        }
        i++;
        it++;
    }
}

int PmergeMe::insertion(int ac, char **av)
{
    std::vector<std::vector<int> > tmp_vect;
    size_t i = 0;
    int size1;
    int size2;

    (void)ac;
    (void)av;
    while (i < vect.size())
    {
        if (i + 1 < vect.size())
        {
            size1 = vect[i].size() - 1;
            size2 = vect[i + 1].size() - 1;
            if (size1 == size2)
            {
                if (vect[i][size1] > vect[i + 1][size2] && size1 == size2)
                {
                    vect[i + 1].insert(vect[i + 1].end(), vect[i].begin(), vect[i].end());
                    tmp_vect.push_back(vect[i + 1]);
                }
                else
                {
                    vect[i].insert(vect[i].end(), vect[i + 1].begin(), vect[i + 1].end());
                    tmp_vect.push_back(vect[i]);
                }
            }
        }
        else
            rest.push_back(vect[i]);
        i += 2;
    }
    vect = tmp_vect;
    if (vect.size() == 1)
        return (0);
    insertion(ac, av);
    return 0;
}

int PmergeMe::fill_vector(int ac, char **av)
{
    int     i;
    char    **endl;

    i = 1;
    endl = NULL;
    while (i < ac)
    {
        std::vector<int> tmp;
        int nmb = static_cast<int>(strtod(av[i], endl));
        tmp.push_back(nmb);
        vect.push_back(tmp);
        i++;
    }
    // print_vect(vect);
    return 0;
}
