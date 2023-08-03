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

int kth_element(std::vector<int>& data, int k) {
    // [l, r)
    int l = 0, r = data.size();
    while (true) {
        int pivot = l + rand() % (r - l);
        int mid = partition(data, l, r, pivot);
        if (mid == k) {
            return data[pivot];
        }
        else if (k < mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
}