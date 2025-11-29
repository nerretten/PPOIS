#include <iterator>
#include <vector>
#include <cstring>
#include <type_traits>
#include <algorithm>

template<typename T, typename KeyExtractor>
void lsdRadixSort(T* arr, size_t n, KeyExtractor key_fn) {
    if (n <= 1) return;

    using KeyType = typename std::decay<decltype(key_fn(arr[0]))>::type;
    static_assert(std::is_integral<KeyType>::value, "Key extracted must be an integral type");

    KeyType min_val = key_fn(arr[0]);
    KeyType max_val = min_val;
    for (size_t i = 1; i < n; ++i) {
        KeyType k = key_fn(arr[i]);
        if (k < min_val)
            min_val = k;
        if (k > max_val)
            max_val = k;
    }

    bool has_negative = min_val < 0;
    KeyType offset = has_negative ? -min_val : 0;

    std::vector<KeyType> keys(n);
    for (size_t i = 0; i < n; ++i) {
        keys[i] = key_fn(arr[i]) + offset;
    }

    const int bytes = sizeof(KeyType);
    std::vector<T> output(n);
    T* current = arr;
    T* next = output.data();
    KeyType* current_keys = keys.data();
    std::vector<KeyType> next_keys(n);
    KeyType* next_keys_ptr = next_keys.data();

    for (int byte = 0; byte < bytes; ++byte) {
        int count[256] = {0};

        for (size_t i = 0; i < n; ++i) {
            unsigned char digit = (current_keys[i] >> (byte * 8)) & 0xFF;
            count[digit]++;
        }

        for (int i = 1; i < 256; ++i) {
            count[i] += count[i - 1];
        }

        for (long i = n - 1; i >= 0; --i) {
            unsigned char digit = (current_keys[i] >> (byte * 8)) & 0xFF;
            int pos = --count[digit];
            next[pos] = current[i];
            next_keys_ptr[pos] = current_keys[i];
        }

        std::swap(current, next);
        std::swap(current_keys, next_keys_ptr);
    }

    if (current != arr) {
        std::memcpy(arr, current, n * sizeof(T));
    }
}

template<typename T, typename KeyExtractor>
void lsdRadixSort(std::vector<T>& vec, KeyExtractor key_fn) {
    if (vec.empty()) return;
    lsdRadixSort(vec.data(), vec.size(), key_fn);
}

template<typename T, size_t N, typename KeyExtractor>
void lsdRadixSort(T (&arr)[N], KeyExtractor key_fn) {
    lsdRadixSort(arr, N, key_fn);
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
lsdRadixSort(T* arr, size_t n) {
    lsdRadixSort(arr, n, [](T x) { return x; });
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
lsdRadixSort(std::vector<T>& vec) {
    lsdRadixSort(vec, [](T x) { return x; });
}

template<typename T, size_t N>
typename std::enable_if<std::is_integral<T>::value, void>::type
lsdRadixSort(T (&arr)[N]) {
    lsdRadixSort(arr, [](T x) { return x; });
}