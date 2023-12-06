#include "RPN.hpp"

int is_arithmetic_operation(char c)
{
    if ( c == '*' || c == '-' || c == '+' || c == '/')
        return 1;
    return 0;
}

int calcul_expression(std::stack<int> &nmbs_stk, char arithmetic_ope)
{
    int nmb1;
    int nmb2;
    int result;

    if (nmbs_stk.empty() || nmbs_stk.size() == 1)
    {
        std::cout << "Calculation expression incomplete" << std::endl;
        return 1;
    }
    nmb1 = nmbs_stk.top();
    nmbs_stk.pop();
    nmb2 = nmbs_stk.top();
    nmbs_stk.pop();
    if (arithmetic_ope == '+')
        result = nmb2 + nmb1;
    if (arithmetic_ope == '-')
        result = nmb2 - nmb1;
    if (arithmetic_ope == '*')
        result = nmb2 * nmb1;
    if (arithmetic_ope == '/')
        result = nmb2 / nmb1;
    nmbs_stk.push(result);
    return 0;
}

int fill_stacks(char **av, std::stack<int> &nmbs_stk)
{
    int i = 1;
    double nmb;

    while (av[i])
    {
        char *split = strtok(av[i], " ");
        while(split != NULL)
        {
            std::string argv(split);
            std::cout << "\n" << split << "    " << argv <<"\n" <<std::endl;
            if (argv.size() == 1 && isdigit(argv[0]))
            {
                nmb = strtod(split, NULL);
                if (!(nmb < 10 && nmb >= 0))
                    return 1;
                nmbs_stk.push(nmb);
                split = strtok(NULL, " ");
            }
            else if (argv.size() == 1 && is_arithmetic_operation(argv[0]))
            {
                if (calcul_expression(nmbs_stk, argv[0]))
                    return 1;
                split = strtok(NULL, " ");
            }
            else
            {
                std::cout << "invalid input argement" << std::endl;
                return 1;
            }
        }
        i++;
    }
    if (nmbs_stk.size() != 1)
    {
        std::cout << "Calculation expression incomplete e" << std::endl;
        return 1;
    }
    std::cout << "result = "<< nmbs_stk.top() << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    std::stack<int> nmbs_stk;

    if (ac == 1)
        return 1;
    if (fill_stacks(av, nmbs_stk))
        return 1;
}
