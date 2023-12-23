#include "PmergeVect.hpp"

extern int global_counter;

void    PmergeVect::insert_pend(std::vector<std::vector<int> >::iterator begin, std::vector<std::vector<int> >::iterator end, std::vector<int> value)
{
    std::vector<std::vector<int> >::iterator    middle;

    middle = begin + ((end - begin) / 2);
    if (begin > end)
    {
        global_counter++;
        std::cout << "\n\n\nchofi wach aydkhal lhad khiti\n\n\n" << std::endl;
        return ;
    }
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

    main_iterator.erase(main_iterator.begin(), main_iterator.end());
    main_iterator.reserve(10000);
	if (tmp.size() == 1 || tmp.size() == 2)
    {
        global_counter++;
        main_chain = tmp;
    }
    else
    {
        i = 1;
		main_chain.push_back(tmp[0]);
        main_iterator.push_back(main_chain.size());
        while (i < tmp.size())
        {
            main_chain.push_back(tmp[i]);
            main_iterator.push_back(main_chain.size());
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
        main_iterator.push_back(main_chain.size());
        rest.pop_back();
    }
}

/*insert mn lwal hta lkhir*/

void	PmergeVect::increment_indexes(size_t start)
{
    size_t i = start;
    while (i < main_iterator.size())
    {
        main_iterator[i]++;
        i++;
    }
}

bool	comp(std::vector<int> v1, std::vector<int> v2)
{
    if (v1.back() < v2.back())
    {
        global_counter++;
        return true ;
    }
    return false ;
}

void	PmergeVect::insert_pend_inside_main_chain()
{
	size_t j = 1;

    if (pend.size() == 1)
    {
    	main_chain.insert(lower_bound(main_chain.begin(),main_chain.end(), pend[0], comp), pend[0]);
        global_counter++;
    }
    else
	{
		while (j < pend.size())
    	{
			main_chain.insert(lower_bound(main_chain.begin(), main_chain.begin() + main_iterator[j], pend[j], comp), pend[j]);
			increment_indexes(j);
    	    j++;
   		}
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
