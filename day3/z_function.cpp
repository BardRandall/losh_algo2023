#include <string>
#include <vector>

std::vector<int> z_function(const std::string& s) {
    int n = s.size();
    std::vector<int> z(n, 0);  // z[0] = 0
    int l = -1, r = -1;
    for (int i = 1; i < n; ++i) {
        if (l <= i && i <= r) {
            z[i] = std::min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}