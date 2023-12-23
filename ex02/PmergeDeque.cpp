#include "PmergeDeque.hpp"

PmergeDeque::PmergeDeque():deque(), rest()
{

}

PmergeDeque::~PmergeDeque()
{

}

PmergeDeque::PmergeDeque(const PmergeDeque &obj)
{
    *this = obj;
}

PmergeDeque &PmergeDeque::operator=(const PmergeDeque &obj)
{
    deque = obj.deque;
    rest = obj.rest;
	main_chain = obj.main_chain;
	pend = obj.pend;
	combination = obj.combination;
	tmp = obj.tmp;
    return (*this);
}
