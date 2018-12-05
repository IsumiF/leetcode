#include <leetcode/5.hpp>

#include <tuple>
#include <vector>
#include <algorithm>

namespace leetcode {
namespace p5 {

using Result = std::tuple<size_t, std::string::const_iterator, std::string::const_iterator>;

template<typename RandIt>
std::tuple<size_t, RandIt, RandIt> longestPalindromeWithCenter(
        const RandIt &center, bool odd, const RandIt &begin, const RandIt &end) {
    RandIt i = center; // begin of the palindrome
    RandIt j = center; // points to last element of the palindrome
    if (!odd) {
        ++j;
        if (j >= end || *i != *j) {
            return std::make_tuple(0, center, center);
        }
    }
    do {
        --i;
        ++j;
    } while (i >= begin && j < end && *i == *j);
    ++i;
    return std::make_tuple(j - i, i, j);
}

std::string Solution::longestPalindrome(std::string s) {
//    palindromes.reserve(s.length());
    if (s.empty()) {
        return s;
    }
    bool odd = true;
    Result result;
    for (auto center = s.cbegin(); center != s.cend(); odd = !odd) {
        auto palindrome = longestPalindromeWithCenter(center, odd, s.cbegin(), s.cend());
        if (std::get<0>(palindrome) > std::get<0>(result)) {
            result = palindrome;
        }
        if (!odd) {
            ++center;
        }
    }
    auto i = std::get<1>(result);
    auto j = std::get<2>(result);
    return s.substr(static_cast<size_t>(i - s.cbegin()), static_cast<size_t>(j - i));
}

}
}

