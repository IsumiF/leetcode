#include <leetcode/709.hpp>
#include <cctype>

#ifdef LEETCODE_LOCAL
namespace leetcode {
namespace p709 {
#endif

std::string Solution::toLowerCase(std::string str) {
    for (char &ch : str) {
        ch = static_cast<char>(std::tolower(ch));
    }
    return str;
}

#ifdef LEETCODE_LOCAL
}
}
#endif
