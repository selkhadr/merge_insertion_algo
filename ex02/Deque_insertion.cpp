#include "PmergeDeque.hpp"

extern int global_counter;

void	PmergeDeque::creat_tmp_deque()
{
	size_t i = 0;

	tmp.erase(tmp.begin(), tmp.end());
    while (i < deque.size())
    {
        std::deque<int> subdeque(deque[i].begin(), deque[i].begin() + deque[i].size() / 2);
        tmp.push_back(subdeque);
        subdeque.assign(deque[i].begin() + deque[i].size() / 2, deque[i].end());
        tmp.push_back(subdeque);
        i++;
    }
}

void	PmergeDeque::creat_main_chain()
{
	size_t i = 0;

    main_iterator.erase(main_iterator.begin(), main_iterator.end());
    // main_iterator.reserve(10000);
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

void	PmergeDeque::creat_pend()
{
	size_t i = 0;

	i = 0;
    pend.erase(pend.begin(), pend.end());
    // pend.reserve(10000);
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

void	PmergeDeque::increment_indexes(size_t start)
{
    size_t i = start;
    while (i < main_iterator.size())
    {
        main_iterator[i]++;
        i++;
    }
}

bool	comp(std::deque<int> v1, std::deque<int> v2)
{
    if (v1.back() < v2.back())
    {
        global_counter++;
        return true ;
    }
    return false ;
}

void	PmergeDeque::insert_pend_inside_main_chain()
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
    deque = main_chain;
}

int	PmergeDeque::insertion(void)
{
    main_chain.erase(main_chain.begin(), main_chain.end());
    // main_chain.reserve(10000);
	creat_tmp_deque();
    creat_main_chain();
	creat_pend();
    insert_pend_inside_main_chain();
    if (main_chain.size() > 1 &&  main_chain[0].size() == 1)
    {
        global_counter++;
        // print_deque(main_chain, "after");
        return (0);
    }
    insertion();
    return (0);
}
