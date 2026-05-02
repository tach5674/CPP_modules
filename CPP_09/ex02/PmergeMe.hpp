#pragma once

#include <vector>
#include <deque>
#include <cstdlib>
#include <string>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> v;
    std::deque<int> d;
    static const double timeScale;

    bool isValidNumber(const char *s, int &number);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe& operator=(const PmergeMe &other);
    ~PmergeMe();

    void prepareData(const char **argv);
    std::clock_t sortVector();
    std::clock_t sortDeque();
    void printVector(const std::string &label) const;
    size_t getSize();
};

template <typename T>
void boundedInsert(T &chain, int value, size_t limit)
{
    typename T::iterator end = chain.begin() + std::min(limit, chain.size());
    typename T::iterator pos = std::lower_bound(chain.begin(), end, value);
    chain.insert(pos, value);
}