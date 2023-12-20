#include "PmergeVect.hpp"

extern int global_counter;

void PmergeVect::creat_combination(void)
{
    long int	jacobsthal[36] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};
    long		int i = 0;
    long		int j = 1;
    int			a = 1;

    combination.erase(combination.begin(), combination.end());
    while (a)
    {
        i = jacobsthal[j] - 1;
        while (i > jacobsthal[j - 1] - 1)
        {
            if (i == static_cast<long int>(pend.size()))
                a = 0;
            combination.push_back(i);
            i--;
        }
        if (jacobsthal[j] > static_cast<long int>(pend.size()) && jacobsthal[j + 1] > static_cast<int>(pend.size()))
            return ;
        j++;
    }
}

void PmergeVect::insert_pend(std::vector<std::vector<int> >::iterator begin, std::vector<std::vector<int> >::iterator end, std::vector<int> value)
{
    std::vector<std::vector<int> >::iterator    middle;

    middle = begin + ((end - begin) / 2);
    if (begin > end)
        return ;
    if (middle[0][middle[0].size() - 1] > value[value.size() - 1])
    {
        global_counter++;
        if (middle == main_chain.begin())
        {
            global_counter++;
            main_chain.insert(middle, value);
            return ;
        }
        middle--;
        if (value[value.size() - 1] > middle[0][middle[0].size() - 1])
        {
            global_counter++;
            main_chain.insert(middle + 1, value);
            return ;
        }
        middle++;
        end = middle - 1;
        insert_pend(begin, end, value);
    }
    else if (middle[0][middle[0].size() - 1] < value[value.size() - 1])
    {
        middle++;
        if (value[value.size() - 1] > main_chain[main_chain.size() - 1][main_chain[0].size() - 1])
        {
            global_counter++;
            main_chain.insert(main_chain.begin() + main_chain.size(), value);
            return ;
        }
        if (middle == main_chain.end())
        {
            global_counter++;
            return ;
        }
        if (value[value.size() - 1] < middle[0][middle[0].size() - 1])
        {
            global_counter++;
            main_chain.insert(middle, value);
            return ;
        }
        middle--;
        begin = middle + 1;
        insert_pend(begin, end, value);
    }
}

void	PmergeVect::creat_tmp_vector()
{
	size_t i = 0;

	tmp.erase(tmp.begin(), tmp.end());
    while (i < vect.size())
    {
        std::vector<int> subVector(vect[i].begin(), vect[i].begin() + vect[i].size() / 2);
        tmp.push_back(subVector);
        subVector.assign(vect[i].begin() + vect[i].size() / 2, vect[i].end());
        tmp.push_back(subVector);
        i++;
    }
}

void	PmergeVect::creat_main_chain()
{
	size_t i = 0;

    pend_iterator.erase(pend_iterator.begin(), pend_iterator.end());
    pend_iterator.reserve(10000);
	if (tmp.size() == 1 || tmp.size() == 2)
    {
        global_counter++;
        main_chain = tmp;
    }
    else
    {
        i = 1;
        while (i < tmp.size())
        {
            main_chain.push_back(tmp[i]);
            pend_iterator.push_back(main_chain.end());
            i += 2;
        }
    }
}

void	PmergeVect::creat_pend()
{
	size_t i = 0;

	i = 0;
    pend.erase(pend.begin(), pend.end());
    pend.reserve(10000);
    if (tmp.size() > 2)
    {
        global_counter++;
        while (i < tmp.size())
        {
            pend.push_back(tmp[i]);
            i += 2;
        }
    }
    if (rest.size() > 0 &&  rest[rest.size() - 1].size() == main_chain[0].size())
    {
        global_counter++;
        pend.push_back(rest[rest.size() - 1]);
        pend_iterator.push_back(main_chain.begin() + main_chain.size());
        rest.pop_back();
    }
}

/*insert mn lwal hta lkhir*/

void	PmergeVect::insert_pend_inside_main_chain()
{
	size_t j = 0;

    creat_combination();
    if (pend.size() >= 1 &&  pend[0][pend[0].size() - 1] < main_chain[0][main_chain[0].size() - 1])
    {
        global_counter++;
        main_chain.insert(main_chain.begin() , pend[0]);
    }
    if (pend.size() >= 1 &&  pend[0][pend[0].size() - 1] > main_chain[main_chain.size() - 1][main_chain[0].size() - 1])
    {
        global_counter++;
        main_chain.insert(main_chain.begin() + main_chain.size(), pend[0]);
    }
    if (main_chain.size() == 2 && pend.size() >= 1)
    {
        global_counter++;
        main_chain.insert(main_chain.begin() + 1, pend[0]);
    }
    while (j < combination.size())
    {
        if (combination[j] < static_cast<int>(pend.size()))
        {
            global_counter++;
            insert_pend(main_chain.begin(), main_chain.end(), pend[combination[j]]);
        }
        j++;
    }
    vect = main_chain;
}

int	PmergeVect::insertion(void)
{
    main_chain.erase(main_chain.begin(), main_chain.end());
    main_chain.reserve(10000);
	creat_tmp_vector();
    creat_main_chain();
	creat_pend();
    insert_pend_inside_main_chain();
    if (main_chain.size() > 1 &&  main_chain[0].size() == 1)
    {
        global_counter++;
        print_vect(main_chain, "after");
        return (0);
    }
    insertion();
    return (0);
}
