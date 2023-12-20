#include "PmergeVect.hpp"

extern int global_counter;

int check_arg(char *str)
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

int PmergeVect::fill_vector(int ac, char **av)
{
    int     i;
    char    **endl;

    i = 1;
    endl = NULL;
    while (i < ac)
    {
        std::vector<int> tmp;
        if (check_arg(av[i]))
            return 1;
        int nmb = static_cast<int>(strtod(av[i], endl));
        tmp.push_back(nmb);
        vect.push_back(tmp);
        i++;
    }
    print_vect(vect, "befor");
    return 0;
}

void    PmergeVect::print_vect(std::vector<std::vector<int> > vect, std::string string)
{
    int i = 0;
    std::vector<std::vector<int> >::iterator it = vect.begin();

    std::cout << string << ": ";
    std::cout << vect.size() << std::endl;
    while (it != vect.end())
    {
        std::vector<int>::iterator ite = vect[i].begin();
        while (ite != vect[i].end())
        {
            std::cout << *ite << " ";
            ite++;
        }
        i++;
        it++;
    }
    std::cout << std::endl;
}

int PmergeVect::merge(void)
{
    std::vector<std::vector<int> >	tmp_vect;
    size_t							i = 0;
    int								size1;
    int								size2;

    while (i < vect.size())
    {
        if (i + 1 < vect.size())
        {
            global_counter++;
            size1 = vect[i].size() - 1;
            size2 = vect[i + 1].size() - 1;
            if (size1 == size2)
            {
                global_counter++;
                if (vect[i][size1] > vect[i + 1][size2] && size1 == size2)
                {
                    global_counter++;
                    vect[i + 1].insert(vect[i + 1].end(), vect[i].begin(), vect[i].end());
                    tmp_vect.push_back(vect[i + 1]);
                }
                else
                {
                    vect[i].insert(vect[i].end(), vect[i + 1].begin(), vect[i + 1].end());
                    tmp_vect.push_back(vect[i]);
                }
            }
            else
                rest.push_back(vect[i]);
        }
        else
            rest.push_back(vect[i]);
        i += 2;
    }
    vect = tmp_vect;
    if (vect.size() == 1)
        return (0);
    merge();
    return 0;
}
