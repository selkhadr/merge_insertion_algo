// #include <iostream>
// #include <ctime>


template<typename T>
T    max_(T a, T b)
{
    if (a > b)
        return a - b;
    return b - a;
}

#include <iostream>
#include <sstream>
#include <map>

int main() {
    std::map<int, int> map;

    std::map<int, int>::iterator it;
    it = map.begin();
    map.insert(std::make_pair(1, 2));
    std::cout << it->first << "    " << it->second << std::endl;
    // while (it != map.end())
    // {
    //     std::cout << it->first << "    " << it->second << std::endl;
    //     it++;
    // }
    return 0;
}
