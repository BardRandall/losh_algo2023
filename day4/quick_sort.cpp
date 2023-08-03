#include <vector>

int partition(std::vector<int>& data, int left, int right, int pivot) {
    // [l, r]
    int i = left, j = right;
    while (i <= j) {
        while (data[i] <= pivot) ++i;
        while (data[j] > pivot) --j;
        if (i <= j) break;
        std::swap(data[i], data[j]);
        ++i;
        --j;
    }
    return j;
}