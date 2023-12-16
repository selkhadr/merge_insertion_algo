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

void PmergeMe::creat_combination(void)
{
    long int jacobsthal[36] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

    long i = 0;
    long j = 1;
    int a = 1;
    combination.erase(combination.begin(), combination.end());
    while (a)
    {
        i = jacobsthal[j] - 1;
        while (i > jacobsthal[j - 1] - 1)
        {
            if (i == pend.first.size())
                a = 0;
            combination.push_back(i);
            i--;
        }
        if (jacobsthal[j] > pend.first.size() && jacobsthal[j + 1] > pend.first.size())
            return ;
        j++;
    }
}

void PmergeMe::insert_pend(std::vector<std::vector<int> >::iterator begin, std::vector<std::vector<int> >::iterator end, std::vector<int> value)
{
    std::vector<std::vector<int> >::iterator    middle;

    middle = begin + ((end - begin) / 2);
    if (begin > end)
        return ;
    if (middle[0][middle[0].size() - 1] > value[value.size() - 1])
    {
        if (middle == main_chain.begin())
        {
            main_chain.insert(middle, value);
            return ;
        }
        middle--;
        if (value[value.size() - 1] > middle[0][middle[0].size() - 1])
        {
            main_chain.insert(middle + 1, value);
            return ;
        }
        middle++;
        end = middle - 1;
        insert_pend(begin, end, value);
    }
    else if (middle[0][middle[0].size() - 1] < value[value.size() - 1])
    {
        if (value[value.size() - 1] > main_chain[main_chain.size() - 1][main_chain[main_chain.size() - 1].size() - 1])
        {
            main_chain.insert(main_chain.begin() + main_chain.size(), value);
            return ;
        }
        middle++;
        if (middle == main_chain.end())
            return ;
        if (value[value.size() - 1] < middle[0][middle[0].size() - 1])
        {
            main_chain.insert(middle, value);
            return ;
        }
        middle--;
        begin = middle + 1;
        insert_pend(begin, end, value);
    }
}

int PmergeMe::insertion(void)
{
    main_chain.reserve(10000);
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
            // pend.second.push_back(main_chain.begin() + (main_chain.size() - 1));
            i += 2;
        }
    }
    // //creat pend
    i = 0;
    pend.first.erase(pend.first.begin(), pend.first.end());
    if (tmp.size() > 2)
    {
        while (i < tmp.size())
        {
            std::vector<int> subVector(tmp[i].begin(), tmp[i].end());
            pend.first.push_back(subVector);
            i += 2;
        }
    }
    if (rest.size() > 0 &&  rest[rest.size() - 1].size() == main_chain[0].size())
    {
        pend.first.push_back(rest[rest.size() - 1]);
        // pend.second.push_back(main_chain.begin() + (main_chain.size() - 1));
        rest.pop_back();
    }
    // insert pend inside main_chain
    size_t j = 0;
    creat_combination();
    if (pend.first.size() >= 1 &&  pend.first[0][pend.first[0].size() - 1] <= main_chain[0][main_chain[0].size() - 1])
        main_chain.insert(main_chain.begin() , pend.first[0]);
    if (pend.first.size() >= 1 &&  pend.first[0][pend.first[0].size() - 1] >= main_chain[main_chain.size() - 1][main_chain[0].size() - 1])
        main_chain.insert(main_chain.begin() + main_chain.size(), pend.first[0]);
    while (j < combination.size())
    {
        if (combination[j] < pend.first.size())
            insert_pend(main_chain.begin(), main_chain.end(), pend.first[combination[j]]);
        j++;
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
