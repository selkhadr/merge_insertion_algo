#ifndef PMERGEDeque_HPP
# define PMERGEDeque_HPP

# include <deque>
# include <iostream>
# include <cstdlib>
# include <ctime>


class PmergeDeque
{
private:
    std::deque<std::deque<int> >		main_chain;
    std::deque<std::deque<int> >		pend;
    std::deque<int>				    main_iterator;
    std::deque<std::deque<int> >		deque;
    std::deque<std::deque<int> >		rest;
    std::deque<std::deque<int> >		tmp;
    std::deque<int>					combination;
public:
    PmergeDeque();
    ~PmergeDeque();
    PmergeDeque(const PmergeDeque &obj);
    PmergeDeque &operator=(const PmergeDeque &obj);
	//
    int		fill_deque(int ac, char **av);
    int		merge(void);
    int		insertion(void);
    void	print_deque(std::deque<std::deque<int> > deque, std::string string);
    void	creat_tmp_deque();
    void	creat_main_chain();
    void	creat_pend();
    void	insert_pend_inside_main_chain();
	void	increment_indexes(size_t start);
};

#endif