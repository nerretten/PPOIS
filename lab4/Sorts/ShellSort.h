#include <iterator>

template <typename RandomIt>
void ShellSort(RandomIt first, RandomIt last) {
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

template<typename T>
void ShellSort(std::vector<T>& vec) {
    ShellSort(vec.begin(), vec.end());
}

template<typename T, size_t N>
void ShellSort(T (&arr)[N]) {
    ShellSort(std::begin(arr), std::end(arr));
}



