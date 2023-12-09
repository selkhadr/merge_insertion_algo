#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vector1;
    vector1.push_back(1);
    vector1.push_back(2);
    vector1.push_back(3);

    std::vector<int> vector2;
    vector2.push_back(11);
    vector2.push_back(22);
    vector2.push_back(33);

    std::vector<int> vector3;
    vector3.push_back(11);
    vector3.push_back(22);
    vector3.push_back(33);

    std::vector<std::vector<int> > vect;
    vect.push_back(vector1);
    vect.push_back(vector2);
    vect.push_back(vector3);
    std::vector<std::vector<int> >::iterator it = vect.begin();
    int i = 0;
    while(it != vect.end())
    {
        if (it +1 != vect.end())
            std::cout << vect[i][0] << std::endl;
        i += 2;
        it += 2;
    }
    // std::cout << vect[i][0] << std::endl;
    return 0;
}
