#include "PmergeVect.hpp"

PmergeVect::PmergeVect():vect(), rest()
{

}

PmergeVect::~PmergeVect()
{

}

PmergeVect::PmergeVect(const PmergeVect &obj)
{
    *this = obj;
}

PmergeVect &PmergeVect::operator=(const PmergeVect &obj)
{
    vect = obj.vect;
    rest = obj.rest;
	main_chain = obj.main_chain;
	pend = obj.pend;
	combination = obj.combination;
	tmp = obj.tmp;
    return (*this);
}



