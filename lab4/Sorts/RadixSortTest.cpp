#include <UnitTest++.h>
#include <vector>
#include <algorithm>
#include <cstring>

#include "Person.h"
#include "RadixSort.h"

template<typename Iterator>
bool my_is_sorted(Iterator begin, Iterator end) {
    return std::is_sorted(begin, end);
}

bool persons_equal(const std::vector<Person>& a, const std::vector<Person>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].age != b[i].age || a[i].name != b[i].name)
            return false;
    }
    return true;
}

SUITE(LsdRadixSortTests) {

    TEST(ArrayIntSort) {
        int arr[] = {170, -45, 75, -90, 2, 24, -802, 66};
        const size_t n = sizeof(arr) / sizeof(arr[0]);
        int expected[] = {-802, -90, -45, 2, 24, 66, 75, 170};

        lsdRadixSort(arr, n, [](int x) { return x; });

                CHECK_ARRAY_EQUAL(expected, arr, n);
                CHECK(my_is_sorted(arr, arr + n));
    }

    TEST(VectorIntSort) {
        std::vector<int> vec = {170, -45, 75, -90, 2, 24, -802, 66};
        std::vector<int> expected = {-802, -90, -45, 2, 24, 66, 75, 170};

        lsdRadixSort(vec, [](int x) { return x; });

                CHECK_ARRAY_EQUAL(expected.data(), vec.data(), vec.size());
                CHECK(my_is_sorted(vec.begin(), vec.end()));
    }

    TEST(CStyleArrayIntSort) {
        int arr[6] = {5, -3, 0, 100, -100, 1};
        int expected[6] = {-100, -3, 0, 1, 5, 100};

        lsdRadixSort(arr, [](int x) { return x; });

                CHECK_ARRAY_EQUAL(expected, arr, 6);
                CHECK(my_is_sorted(arr, arr + 6));
    }

    TEST(PersonVectorSortByAge) {
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

        lsdRadixSort(people, [](const Person& p) { return p.age; });

                CHECK(persons_equal(expected, people));
        for (size_t i = 1; i < people.size(); ++i) {
                    CHECK(people[i - 1].age <= people[i].age);
        }
    }

    TEST(EmptyVector) {
        std::vector<int> vec;
        lsdRadixSort(vec, [](int x) { return x; });
                CHECK(vec.empty());
    }

    TEST(SingleElementArray) {
        int arr[] = {42};
        lsdRadixSort(arr, 1, [](int x) { return x; });
                CHECK_EQUAL(42, arr[0]);
    }

    TEST(AllSameElements) {
        std::vector<int> vec = {5, 5, 5, 5};
        lsdRadixSort(vec, [](int x) { return x; });
                CHECK(my_is_sorted(vec.begin(), vec.end()));
                CHECK_EQUAL(5, vec[0]);
                CHECK_EQUAL(5, vec.back());
    }

    TEST(NegativeNumbersOnly) {
        std::vector<int> vec = {-1, -10, -100, -5};
        std::vector<int> expected = {-100, -10, -5, -1};
        lsdRadixSort(vec, [](int x) { return x; });
                CHECK_ARRAY_EQUAL(expected.data(), vec.data(), vec.size());
                CHECK(my_is_sorted(vec.begin(), vec.end()));
    }

    TEST(PositiveNumbersOnly) {
        int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
        int expected[] = {1, 1, 2, 3, 4, 5, 6, 9};
        lsdRadixSort(arr, 8, [](int x) { return x; });
                CHECK_ARRAY_EQUAL(expected, arr, 8);
                CHECK(my_is_sorted(arr, arr + 8));
    }
}

int main() {
    return UnitTest::RunAllTests();
}