#include <string>
#include <unordered_set>
#include <iostream>

class Solution {
public:

    int numJewelsInStones(const std::string &J, const std::string &S) {
        std::unordered_set<char> jewels(J.cbegin(), J.cend());
        int count = 0;
        for (char ch : S) {
            if (jewels.find(ch) != jewels.cend()) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::cout << solution.numJewelsInStones("aA", "aAAbbbb") << std::endl;
    std::cout << solution.numJewelsInStones("z", "ZZ") << std::endl;
    return 0;
}