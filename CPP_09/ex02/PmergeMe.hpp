#pragma once

#include <vector>
#include <deque>
#include <cstdlib>

class PmergeMe
{
private:
    std::vector<int> v;
    std::deque<int> d;
    bool isValidNumber(const char *s, int &number);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe& operator=(const PmergeMe &other);
    ~PmergeMe();

    void prepareData(const char **argv);
    void sortVector();
    void sortDeque();
    void printVector() const;
};

template <typename T>
void boundedInsert(T &chain, int value, size_t limit)
{
    typename T::iterator end = chain.begin() + std::min(limit, chain.size());
    typename T::iterator pos = std::lower_bound(chain.begin(), end, value);
    chain.insert(pos, value);
}