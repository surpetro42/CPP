#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
    {
        _vect = copy._vect;
        _deque = copy._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::insertionSortVector(std::vector<int> &vec)
{
    for (std::size_t i = 1; i < vec.size(); ++i)
    {
        int key = vec[i];
        std::size_t j = i;
        while (j > 0 && vec[j - 1] > key)
        {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int> &deq)
{
    for (std::size_t i = 1; i < deq.size(); ++i)
    {
        int key = deq[i];
        std::size_t j = i;
        while (j > 0 && deq[j - 1] > key)
        {
            deq[j] = deq[j - 1];
            --j;
        }
        deq[j] = key;
    }
}

std::size_t PmergeMe::binarySearch(const std::vector<int> &vec, int value)
{
    std::size_t left = 0;
    std::size_t right = vec.size();
    while (left < right)
    {
        std::size_t mid = (left + right) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void PmergeMe::printTime(const char* containerName, double timeTaken)
{
    std::cout << "Time to process a range of " << _vect.size() << " elements with " << containerName << ": "
              << timeTaken << " us" << std::endl;
}

void PmergeMe::sort()
{
    std::cout << "Before: ";
    for (std::size_t i = 0; i < _vect.size(); ++i)
        std::cout << _vect[i] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    insertionSortVector(_vect);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1e6; // us
    printTime("std::vector", timeTaken);

    std::cout << "After: ";
    for (std::size_t i = 0; i < _vect.size(); ++i)
        std::cout << _vect[i] << " ";
    std::cout << std::endl;

    start = clock();
    insertionSortDeque(_deque);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1e6; // us
    printTime("std::deque", timeTaken);
}

void PmergeMe::initialize(const std::vector<std::string> &vectelem)
{
    for (std::size_t i = 0; i < vectelem.size(); ++i)
    {
        long val = std::strtol(vectelem[i].c_str(), NULL, 10);
        if (val > INT_MAX || val < 0)
            std::cout << "The number exceeds INT_MAX or is negative" << std::endl;

        _vect.push_back(static_cast<int>(val));
        _deque.push_back(static_cast<int>(val));
    }
}
