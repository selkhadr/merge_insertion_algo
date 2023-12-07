#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>

class   RPN
{
    std::stack<int> nmbs_stk;
public:
    RPN();
    ~RPN();
    RPN(const RPN& obj);
    RPN& operator=(const RPN& obj);
    int calcul_expression(char arithmetic_ope);
    int is_arithmetic_operation(char c);
    int fill_stacks(char **av);
};

#endif