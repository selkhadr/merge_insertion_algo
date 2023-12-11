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
        std::cout << "\nvector[i] = " << std::endl;
        while (ite != vect[i].end())
        {
            std::cout << *ite << " with size = " << vect[i].size() << std::endl;
            ite++;
        }
        i++;
        it++;
    }
}

int PmergeMe::merge(int ac, char **av)
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
    merge(ac, av);
    return 0;
}

int PmergeMe::insertion(void)
{
    std::vector<std::vector<int> > tmp;

    //creat tmp_vector
    size_t i = 0;
    while (i < vect.size())
    {
        std::vector<int> subVector(vect[i].begin(), vect[i].begin() + vect[i].size() / 2);
        tmp.push_back(subVector);
        subVector.assign(vect[i].begin() + vect[i].size() / 2, vect[i].end());
        tmp.push_back(subVector);
        i++;
    }
    i = 0;
    // creat main_chain
    main_chain.erase(main_chain.begin(), main_chain.end());
    if (tmp.size() == 1 || tmp.size() == 2)
        main_chain = tmp;
    else
    {
        i = 1;
        while (i < tmp.size())
        {
            std::vector<int> subVector(tmp[i].begin(), tmp[i].end());
            main_chain.push_back(subVector);
            i += 2;
        }
    }
    // //creat pend
    i = 0;
    if (tmp.size() > 2)
    {
        while (i < tmp.size())
        {
            std::vector<int> subVector(tmp[i].begin(), tmp[i].end());
            pend.push_back(subVector);
            i += 2;
        }
    }
    if (rest[rest.size() - 1].size() == main_chain[0].size())
    {
        pend.push_back(rest[rest.size() - 1]);
        rest.pop_back();
    }
    //insert pend inside main_chain
    size_t j = 0;
    while (j < pend.size())
    {
        if (pend[0][pend[0].size() - 1] <= main_chain[0][main_chain[0].size() - 1])
        {
            main_chain.insert(main_chain.begin() , pend[0]);
            pend.erase(pend.begin());
            continue;
        }
        if (pend[0][pend[0].size() - 1] >= main_chain[main_chain.size() - 1][main_chain[0].size() - 1])
        {
            main_chain.insert(main_chain.begin() + main_chain.size(), pend[0]);
            pend.erase(pend.begin());
            continue;
        }
        i = 0;
        size_t s = main_chain.size();
        while (i < s)
        {
            if (i + 1 < s && pend[j][pend[j].size() - 1] >= main_chain[i][main_chain[i].size() - 1] && pend[j][pend[j].size() - 1] <= main_chain[i + 1][main_chain[i + 1].size() - 1])
            {
                main_chain.insert(main_chain.begin() + i + 1, pend[j]);
                pend.erase(pend.begin() + j);
                break;
            }
            i++;
        }
        continue;
    }
    vect = main_chain;
    if (main_chain.size() > 1 &&  main_chain[0].size() == 1)
        return (0);
    insertion();
    return (0);
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
    return 0;
}
