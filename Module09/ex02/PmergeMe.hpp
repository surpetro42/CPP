#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> _vect;
    std::deque<int> _deque;

    void insertionSortVector(std::vector<int> &vec);
    void insertionSortDeque(std::deque<int> &deq);
    std::size_t binarySearch(const std::vector<int> &vec, int value);

    void printTime(const char* containerName, double timeTaken);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &);
    PmergeMe &operator=(const PmergeMe &);
    ~PmergeMe();

    void initialize(const std::vector<std::string> &);
    void sort();
};
