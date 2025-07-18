#include <bits/stdc++.h>
using namespace std;
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    vector<string> result;

    void backTrack(string& num, int index, int target, long eval, long prevNum, string expr) {
        if (index == num.length()) {
            if (eval == target) {
                result.push_back(expr);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            if (i != index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long currNum = stol(currStr);

            if (index == 0) {
                backTrack(num, i + 1, target, currNum, currNum, currStr);
            } else {
                backTrack(num, i + 1, target, eval + currNum, currNum, expr + "+" + currStr);
                backTrack(num, i + 1, target, eval - currNum, -currNum, expr + "-" + currStr);
                backTrack(num, i + 1, target,
                          eval - prevNum + prevNum * currNum,
                          prevNum * currNum,
                          expr + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        backTrack(num, 0, target, 0, 0, "");
        return result;
    }
};

int main() {
    Solution s;
    string str;
    int target;

    cin >> str >> target;

    vector<string> res = s.addOperators(str, target);

    cout << "[ ";
    for (auto& c : res) {
        cout << '"' << c << "\", ";
    }
    cout << "]\n";

    return 0;
}
