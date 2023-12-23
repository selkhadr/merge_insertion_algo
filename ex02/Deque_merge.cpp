#include "PmergeDeque.hpp"

extern int global_counter;

static int check_arg(char *str)
{
    std::string string(str);

    size_t i = 0;
    while(i < string.size())
    {
        if (!isdigit(string[i]))
        {
            std::cout << "invalid argument" << std::endl;
            return 1;
        }
        i++;
    }
    return 0;
}

int PmergeDeque::fill_deque(int ac, char **av)
{
    int     i;
    char    **endl;

    i = 1;
    endl = NULL;
    while (i < ac)
    {
        std::deque<int> tmp;
        if (check_arg(av[i]))
            return 1;
        int nmb = static_cast<int>(strtod(av[i], endl));
        tmp.push_back(nmb);
        deque.push_back(tmp);
        i++;
    }
    // print_deque(deque, "befor");
    return 0;
}

void    PmergeDeque::print_deque(std::deque<std::deque<int> > deque, std::string string)
{
    int i = 0;
    std::deque<std::deque<int> >::iterator it = deque.begin();

    std::cout << string << ": ";
    while (it != deque.end())
    {
        std::deque<int>::iterator ite = deque[i].begin();
        while (ite != deque[i].end())
        {
            std::cout << *ite << " ";
            ite++;
        }
        i++;
        it++;
    }
    std::cout << std::endl;
}

int PmergeDeque::merge(void)
{
    std::deque<std::deque<int> >	tmp_deque;
    size_t							i = 0;
    int								size1;
    int								size2;

    while (i < deque.size())
    {
        if (i + 1 < deque.size())
        {
            global_counter++;
            size1 = deque[i].size() - 1;
            size2 = deque[i + 1].size() - 1;
            if (size1 == size2)
            {
                global_counter++;
                if (deque[i][size1] > deque[i + 1][size2] && size1 == size2)
                {
                    global_counter++;
                    deque[i + 1].insert(deque[i + 1].end(), deque[i].begin(), deque[i].end());
                    tmp_deque.push_back(deque[i + 1]);
                }
                else
                {
                    deque[i].insert(deque[i].end(), deque[i + 1].begin(), deque[i + 1].end());
                    tmp_deque.push_back(deque[i]);
                }
            }
            else
                rest.push_back(deque[i]);
        }
        else
            rest.push_back(deque[i]);
        i += 2;
    }
    deque = tmp_deque;
    if (deque.size() == 1)
    {
        global_counter++;
        return (0);
    }
    merge();
    return 0;
}
