#include <iostream>
#include <vector>

int main()
{
    std::vector<int> originalVector;
    originalVector.push_back(10);
    // originalVector.push_back(2);
    // originalVector.push_back(3);
    // originalVector.push_back(4);
    // originalVector.push_back(5);
    // originalVector.push_back(6);
    // originalVector.push_back(7);
    // originalVector.push_back(8);
    // originalVector.push_back(9);

    std::cout << originalVector.size() << std::endl;
    std::cout << originalVector[originalVector.size() - 1] << std::endl;

    // Specify the range using iterators
    // std::vector<int>::iterator startIterator = originalVector.begin() + 2;  // Starting at index 2
    // std::vector<int>::iterator endIterator = originalVector.begin() + 5;    // Ending at index 4 (exclusive)

    // // Create a new vector with the specified subsequence
    // std::vector<int> subVector(startIterator, endIterator);

    // // Output the elements of the subsequence
    // std::cout << "Subsequence: ";
    // for (std::vector<int>::iterator it = subVector.begin(); it != subVector.end(); ++it) {
    //     std::cout << *it << " ";
    // }

    return 0;
}
