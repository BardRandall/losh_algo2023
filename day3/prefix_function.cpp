#include <string>
#include <vector>

std::vector<int> p_function(const std::string& s) {
    int n = s.size();
    std::vector<int> p(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}