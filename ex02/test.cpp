#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect;
    vect.reserve(20);
    std::vector<std::vector<int>::iterator> it;
    it.push_back(vect.begin() + vect.size() - 1);
    std::vector<int>::iterator ite = it[0];
    std::cout << *ite << std::endl;
    // vect.insert(vect.begin(), 7);
    // vect.push_back(5);
    // std::cout << *ite << std::endl;
}
