#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

bool is_prime(int a) {
    if (a < 3)
        return true;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main() {
    size_t size;
    std::cout << "Enter the size of sequence: ";
    std::cin >> size;
    std::vector<int> p1(size);
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> dist(1, 10);
    for (auto& a : p1)
        a = dist(generator);
    std::cout << "\nCurrent state of p1:\n";
    for (auto a : p1)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nHow much elements do you want to add: ";
    int add;
    std::cin >> add;
    p1.reserve(p1.size() + static_cast<size_t>(add));
    std::cout << "\nAdd " << add << " elements:\n";
    for (int i = 0; i != add; ++i) {
        int a;
        std::cin >> a;
        p1.push_back(a);
    }
    std::cout << "Current state of p1:\n";
    for (auto a : p1)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nShuffling...\n";
    std::random_shuffle(p1.begin(), p1.end());
    std::cout << "Current state of p1:\n";
    for (auto a : p1)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nRemoving duplicates...\n";
    std::unique(p1.begin(), p1.end());
    std::cout << "Current state of p1:\n";
    for (auto a : p1)
        std::cout << a << ' ';
    std::cout << '\n';
    int odd_count = 0;
    for (auto a : p1) {
        if (a % 2 == 1)
            ++odd_count;
    }
    std::cout << "\nCount of odd elements: " << odd_count << '\n';
    std::cout << "\nMin element " << p1[std::min_element(p1.begin(), p1.end()) - p1.begin()] << '\n';
    std::cout << "Max element " << p1[std::max_element(p1.begin(), p1.end()) - p1.begin()] << '\n';
    bool prime_found = false;
    for (auto a : p1) {
        if (is_prime(a)) {
            prime_found = true;
            std::cout << "\nThere is a prime number: " << a << '\n';
            break;
        }
    }
    if (!prime_found)
        std::cout << "\nThere are no prime numbers\n";
    std::cout << "\nMaking all elements squared...\n";
    for (auto& a : p1)
        a *= a;
    std::cout << "Current state of p1:\n";
    for (auto a : p1)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nCreating p2...\n";
    std::vector<int> p2(p1.size());
    for (auto& a : p2)
        a = dist(generator);
    std::cout << "Current state of p2:\n";
    for (auto a : p2)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nSum of elements: ";
    int sum = 0;
    for (auto a : p2)
        sum += a;
    std::cout << sum << '\n';
    std::cout << "\nReplacing first elements on 1...\n";
    std::replace_if(p2.begin(), p2.begin() + std::max(1, static_cast<int>(p2.size() / 5)), [] (auto a) {return true;}, 1);
    std::cout << "Current state of p2:\n";
    for (auto a : p2)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nCreating p3...\n";
    std::vector<int> p3(p1.size());
    for (size_t i = 0; i != p1.size(); ++i)
        p3[i] = p1[i] - p2[i];
    std::cout << "Current state of p3:\n";
    for (auto a : p3)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nReplacing negative elements in p3...\n";
    std::replace_if(p3.begin(), p3.end(), [] (int a) {return a < 0;}, 0);
    std::cout << "Current state of p3:\n";
    for (auto a : p3)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nRemoving null elements from p3...\n";
    std::remove(p3.begin(), p3.end(), 0);
    std::cout << "Current state of p3:\n";
    for (auto a : p3)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nReversing p3...\n";
    std::reverse(p3.begin(), p3.end());
    std::cout << "Current state of p3:\n";
    for (auto a : p3)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nTop 3 biggest elements:\n";
    std::vector<int> p3s(3);
    std::partial_sort_copy(p3.begin(), p3.end(), p3s.begin(), p3s.end(), [] (int a, int b) {return a > b;});
    for (auto a : p3s)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nSorting p1 and p2...\n";
    std::sort(p1.begin(), p1.end());
    std::sort(p2.begin(), p2.end());
    std::cout << "Current state of p1:\n";
    for (auto a : p1)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "Current state of p2:\n";
    for (auto a : p2)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nMerging p1 and p2...\n";
    std::vector<int> p4(p1.size() + p2.size());
    std::merge(p1.begin(), p1.end(), p2.begin(), p2.end(), p4.begin());
    std::cout << "Current state of p4:\n";
    for (auto a : p4)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "\nRange for inserting 1 is:\n";
    std::cout << "[" << (std::lower_bound(p4.begin(), p4.end(), 1) - p4.begin()) << ", " << (std::upper_bound(p4.begin(), p4.end(), 1) - p4.begin() - 1) << ']';
    std::cout << "\nCurrent state of p1:\n";
    for (auto a : p1)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "Current state of p2:\n";
    for (auto a : p2)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "Current state of p3:\n";
    for (auto a : p3)
        std::cout << a << ' ';
    std::cout << '\n';
    std::cout << "Current state of p4:\n";
    for (auto a : p4)
        std::cout << a << ' ';
    std::cout << '\n';
}