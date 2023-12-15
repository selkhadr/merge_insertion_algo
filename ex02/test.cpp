#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<long>  vec;


    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(9);
    vec.push_back(91);
    vec.push_back(92);
    vec.push_back(93);
    vec.push_back(94);
    vec.push_back(95);
    std::vector<long>::iterator  begin= vec.begin();
    std::vector<long>::iterator  end = vec.end();
    std::vector<long>::iterator  middle;
    middle = begin + (end - begin) / 2;
    begin = middle + 1;
    middle = begin + (end - begin) / 2;
    std::cout << *middle << std::endl;
}
