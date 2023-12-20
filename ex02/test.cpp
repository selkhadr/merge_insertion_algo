#include <iostream>
#include <list>

#include <list>
#include <algorithm>

class PmergeList {
public:
    int merge();

private:
    std::list<std::list<int> > lst;
    std::list<std::list<int> > rest;

    void mergeLists(std::list<int>& list1, std::list<int>& list2);
};

int PmergeList::merge() {
    std::list<std::list<int> > tmp_lst;
    std::list<std::list<int> >::iterator it = lst.begin();

    while (it != lst.end()) {
        std::list<int>& list1 = *it;
        ++it;

        if (it != lst.end()) {
            std::list<int>& list2 = *it;

            if (list1.size() == list2.size()) {
                if (list1.back() > list2.back()) {
                    list2.insert(list2.end(), list1.begin(), list1.end());
                    tmp_lst.push_back(list2);
                } else {
                    list1.insert(list1.end(), list2.begin(), list2.end());
                    tmp_lst.push_back(list1);
                }
                ++it;  // Move to the next pair of lists
            } else {
                // Unequal sizes, move the current list to the rest list
                rest.push_back(list1);
            }
        } else {
            // If there's an odd number of lists, move the last one to the rest list
            rest.push_back(list1);
        }
    }

    lst = tmp_lst;

    if (lst.size() == 1) {
        return 0;
    }

    merge();  // Recursively call merge until there is only one list left
    return 0;
}


// int PmergeList::merge(void)
// {
//     std::list<std::list<int> >	tmp_list;
//     size_t							i = 0;
//     int								size1;
//     int								size2;

//     while (i < list.size())
//     {
//         if (i + 1 < list.size())
//         {
//             size1 = list[i].size() - 1;
//             size2 = list[i + 1].size() - 1;
//             if (size1 == size2)
//             {
//                 if (list[i][size1] > list[i + 1][size2] && size1 == size2)
//                 {
//                     list[i + 1].insert(list[i + 1].end(), list[i].begin(), list[i].end());
//                     tmp_list.push_back(list[i + 1]);
//                 }
//                 else
//                 {
//                     list[i].insert(list[i].end(), list[i + 1].begin(), list[i + 1].end());
//                     tmp_list.push_back(list[i]);
//                 }
//             }
//         }
//         else
//             rest.push_back(list[i]);
//         i += 2;
//     }
//     list = tmp_list;
//     if (list.size() == 1)
//         return (0);
//     merge();
//     return 0;
// }
