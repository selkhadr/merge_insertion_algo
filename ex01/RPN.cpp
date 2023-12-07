#include "RPN.hpp"

RPN::RPN():nmbs_stk()
{

}

RPN::~RPN()
{
    
}

RPN::RPN(const RPN& obj)
{
    *this = obj;
}

RPN& RPN::operator=(const RPN& obj)
{
    nmbs_stk = obj.nmbs_stk;
    return (*this);
}
