#include <vector>

void merge(std::vector<int>& data, int left, int mid, int right) {
    // [left, mid), [mid, right)
    int i = 0, j = 0;
    std::vector<int> result(right - left);
    while (left + i < mid && mid + j < right) {
        if (data[left + i] < data[mid + j]) {
            result[i + j] = data[left + i];
            ++i;
        } else {
            result[i + j] = data[mid + j];
            // cnt += mid - i;
            ++j;
        }
    }
    while (left + i < mid) {
        result[i + j] = data[left + i];
        ++i;
    }
    while (mid + j < right) {
        result[i + j] = data[mid + j];
        ++j;
    }
    std::copy(result.begin(), result.end(), data.begin() + left);
}
