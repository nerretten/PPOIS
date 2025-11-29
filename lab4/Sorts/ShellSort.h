#include <iterator>

class ShellSorter {
private:
    template <typename RandomIt>
    static void sort_implementation(RandomIt first, RandomIt last) {
        if (first >= last)
            return;

        auto n = last - first;

        for (auto gap = n / 2; gap > 0; gap /= 2) {
            for (auto i = gap; i < n; ++i) {
                auto temp = *(first + i);
                auto j = i;

                while (j >= gap && temp < *(first + j - gap)) {
                    *(first + j) = *(first + j - gap);
                    j -= gap;
                }
                *(first + j) = temp;
            }
        }
    }
public:
    template <typename T>
    static void sort(std::vector<T>& vec) {
        sort_implementation(vec.begin(), vec.end());
    }

    template <typename T, size_t N>
    static void sort(T (&arr)[N]) {
        sort_implementation(std::begin(arr), std::end(arr));
    }

};

