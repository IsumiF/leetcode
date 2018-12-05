#include <leetcode/709.hpp>
#include <cctype>

namespace leetcode::p709 {

std::string Solution::toLowerCase(std::string str) {
    for (char &ch : str) {
        ch = static_cast<char>(std::tolower(ch));
    }
    return str;
}

}
