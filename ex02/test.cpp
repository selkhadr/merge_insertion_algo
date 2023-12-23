#include <deque>
#include <iostream>

int main() {
    std::deque<int> myDeque;

    // Reserve space for at least 10 elements
    myDeque.reserve(10);

    // Adding elements to the deque
    for (int i = 1; i <= 10; ++i) {
        myDeque.push_back(i);
    }

    // Print the elements in the deque
    for (const auto& element : myDeque) {
        std::cout << element << " ";
    }

    return 0;
}
