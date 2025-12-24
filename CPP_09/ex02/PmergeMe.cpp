#include "PmergeMe.hpp"
#include <stdexcept>
#include <errno.h>
#include <limits>
#include <iostream>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : v(other.v), d(other.d) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->v = other.v;
        this->d = other.d;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const char *s, int &number)
{
    char *end;
    long val;

    if (!s || !*s)
        return false;

    errno = 0;
    val = strtol(s, &end, 10);

    if (*end != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    if (val <= 0 || val > std::numeric_limits<int>::max())
        return false;

    number = static_cast<int>(val);
    return true;
}

void PmergeMe::prepareData(const char **argv)
{
    int val;

    while (*argv)
    {
        if (!isValidNumber(*argv, val))
            throw std::invalid_argument("Invalid input");
        this->v.push_back(val);
        this->d.push_back(val);
        argv++;
    }
}

void PmergeMe::printVector() const
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

static size_t jacobsthal(size_t k)
{
    size_t pow2 = 1ULL << (k + 1);
    return (pow2 + ((k % 2 == 0) ? 1 : -1)) / 3;
}

static void fordJohnsonVector(std::vector<int> &v)
{
    if (v.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pendings;

    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        mainChain.push_back(std::max(v[i], v[i + 1]));
        pendings.push_back(std::min(v[i], v[i + 1]));
    }

    bool hasOdd = (v.size() % 2 != 0);
    int odd = v.size() % 2 ? v.back() : 0;

    fordJohnsonVector(mainChain);

    mainChain.insert(mainChain.begin(), pendings[0]);

    size_t inserted = 1;
    size_t k = 2;

    while (true)
    {
        size_t tk = jacobsthal(k);
        size_t tkm1 = jacobsthal(k - 1);

        if (tk >= pendings.size())
            break;

        size_t limit = (1ULL << k) - 1;

        for (size_t j = tk; j > tkm1; --j)
        {
            boundedInsert(mainChain, pendings[j - 1], limit);
            ++inserted;
        }
        ++k;
    }

    for (size_t j = pendings.size(); j > inserted; --j)
        boundedInsert(mainChain, pendings[j - 1], mainChain.size());

    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(),
                                                          mainChain.end(),
                                                          odd);
        mainChain.insert(pos, odd);
    }

    v = mainChain;
}

static void fordJohnsonDeque(std::deque<int> &d)
{
    if (d.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pendings;

    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        mainChain.push_back(std::max(d[i], d[i + 1]));
        pendings.push_back(std::min(d[i], d[i + 1]));
    }

    bool hasOdd = (d.size() % 2 != 0);
    int odd = d.size() % 2 ? d.back() : 0;

    fordJohnsonDeque(mainChain);

    mainChain.insert(mainChain.begin(), pendings[0]);

    size_t inserted = 1;
    size_t k = 2;

    while (true)
    {
        size_t tk = jacobsthal(k);
        size_t tkm1 = jacobsthal(k - 1);

        if (tk >= pendings.size())
            break;

        size_t limit = (1ULL << k) - 1;

        for (size_t j = tk; j > tkm1; --j)
        {
            boundedInsert(mainChain, pendings[j - 1], limit);
            ++inserted;
        }
        ++k;
    }

    for (size_t j = pendings.size(); j > inserted; --j)
        boundedInsert(mainChain, pendings[j - 1], mainChain.size());

    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(),
                                                          mainChain.end(),
                                                          odd);
        mainChain.insert(pos, odd);
    }

    d = mainChain;
}

void PmergeMe::sortVector()
{
    printVector();
    fordJohnsonVector(v);
    printVector();
}

void PmergeMe::sortDeque()
{
    printVector();
    fordJohnsonVector(v);
    printVector();
}