#include <string>
#include <vector>

std::vector<int> manaker_for_odd(const std::string& s) {  // для нечётных
    int n = s.size();
    std::vector<int> answer(n);
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        if (i <= r) {
            k = std::min(answer[l + r - i], r - i + 1);
        }
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            ++k;
        }
        answer[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    return answer;
}

std::vector<int> manaker_for_even(const std::string& s) {  // для чётных
    int n = s.size();
    std::vector<int> answer(n);
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if (i <= r) {
            k = std::min(answer[l + r - i + 1], r - i + 1);
        }
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            ++k;
        }
        answer[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
    return answer;
}