#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>

std::string simplifyEmailAddress(const std::string &email);

class Solution {
public:
    int numUniqueEmails(const std::vector<std::string> &emails);
};

int Solution::numUniqueEmails(const std::vector<std::string> &emails) {
    std::set<std::string> uniqueEmails;
    for (const std::string &email : emails) {
        uniqueEmails.insert(simplifyEmailAddress(email));
    }
    return static_cast<int>(uniqueEmails.size());
}

std::string simplifyEmailAddress(const std::string &email) {
    size_t sep = email.find('@');

    std::string simplifiedEmail;
    for (size_t i = 0; i < sep; ++i) {
        char ch = email[i];
        if (ch == '.') {
            continue;
        } else if (ch == '+') {
            break;
        } else {
            simplifiedEmail += ch;
        }
    }
    simplifiedEmail += email.substr(sep);
    return simplifiedEmail;
}

int main() {
    Solution solution;
    std::cout << solution.numUniqueEmails({
                                     "test.email+alex@leetcode.com",
                                     "test.e.mail+bob.cathy@leetcode.com",
                                     "testemail+david@lee.tcode.com"
                             });

    return 0;
}
