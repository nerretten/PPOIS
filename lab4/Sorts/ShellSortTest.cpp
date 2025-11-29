#include <UnitTest++.h>
#include <vector>

#include <string>
#include <algorithm>
#include <iostream>


#include "Person.h"
#include <ShellSort.h>

template <typename RandomIt>
bool my_is_sorted(RandomIt first, RandomIt last) {
    if (first == last) return true;
    RandomIt next = first;
    ++next;
    for (; next != last; ++first, ++next) {
        if (*next < *first) return false;
    }
    return true;
}

TEST(ShellSort_Array) {
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        const size_t N = sizeof(arr) / sizeof(arr[0]);

        ShellSorter::sort(arr);

        CHECK(my_is_sorted(std::begin(arr), std::end(arr)));

        int expected[] = {11, 12, 22, 25, 34, 64, 90};
        for (size_t i = 0; i < N; ++i) {
            CHECK_EQUAL(expected[i], arr[i]);
        }
}


TEST(ShellSort_VectorInt) {
        std::vector<int> vec = {5, 2, 9, 1, 5, 6};
        std::vector<int> expected = {1, 2, 5, 5, 6, 9};

        ShellSorter::sort(vec);

        CHECK(is_sorted(vec.begin(), vec.end()));
        CHECK_ARRAY_EQUAL(expected.data(), vec.data(), vec.size());
}


TEST(ShellSort_VectorPerson) {
        std::vector<Person> people = {
            {"Alice", 30},
            {"Bob", 25},
            {"Charlie", 30},
            {"Diana", 25}
        };

        std::vector<Person> expected = {
            {"Bob", 25},
            {"Diana", 25},
            {"Alice", 30},
            {"Charlie", 30}
        };

        ShellSorter::sort(people);

        CHECK(is_sorted(people.begin(), people.end()));
        CHECK_EQUAL(expected.size(), people.size());

        for (size_t i = 0; i < people.size(); ++i) {
            CHECK_EQUAL(expected[i].age, people[i].age);
            CHECK(expected[i].name == people[i].name);
        }
}

TEST(ShellSort_EmptyVector) {
        std::vector<int> vec;
        ShellSorter::sort(vec);
        CHECK(vec.empty());
        CHECK(is_sorted(vec.begin(), vec.end()));
}

TEST(ShellSort_SingleElement) {
        int arr[] = {42};
        ShellSorter::sort(arr);
        CHECK_EQUAL(42, arr[0]);

        std::vector<Person> vec = {{"Zoe", 20}};
        ShellSorter::sort(vec);
        CHECK_EQUAL("Zoe", vec[0].name);
        CHECK_EQUAL(20, vec[0].age);
}

TEST(ShellSort_AlreadySorted) {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::vector<int> copy = vec;
        ShellSorter::sort(vec);
        CHECK_ARRAY_EQUAL(copy.data(), vec.data(), vec.size());
        CHECK(is_sorted(vec.begin(), vec.end()));
}

TEST(ShellSort_ReverseOrder) {
        int arr[] = {5, 4, 3, 2, 1};
        ShellSorter::sort(arr);
        int expected[] = {1, 2, 3, 4, 5};
        CHECK_ARRAY_EQUAL(expected, arr, 5);
        CHECK(my_is_sorted(std::begin(arr), std::end(arr)));
}

int main() {
    return UnitTest::RunAllTests();
}