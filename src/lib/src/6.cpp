#include <leetcode/6.hpp>

#include <vector>
#include <algorithm>
#include <iterator>

namespace leetcode {
namespace p6 {

template<typename T>
class Coordinated {
public:
    Coordinated(T value, int x, int y) : value_(std::move(value)), x(x), y(y) {}

    bool operator<(const Coordinated &rhs) const {
        if (y != rhs.y) {
            return y < rhs.y;
        } else {
            return x < rhs.x;
        }
    }

    const T &value() const {
        return value_;
    }
private:
    int x;
    int y;
    T value_;
};

enum class Direction {
    DOWN, UP
};

std::string Solution::convert(std::string s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    std::vector<Coordinated<char>> chars;
    chars.reserve(s.size());

    int x = 0;
    int y = 0;
    Direction direction = Direction::DOWN;
    for (char ch : s) {
        // act
        chars.emplace_back(ch, x, y);

        // move
        if (direction == Direction::DOWN) {
            if (y < numRows - 1) {
                ++y;
            } else {
                --y;
                ++x;
                direction = Direction::UP;
            }
        } else {
            if (y > 0) {
                --y;
                ++x;
            } else {
                ++y;
                direction = Direction::DOWN;
            }
        }
    }

    std::sort(std::begin(chars), std::end(chars));

    std::string result;
    result.reserve(chars.size());
    for (const Coordinated<char> &coordinatedChar : chars) {
        result += coordinatedChar.value();
    }
    return result;
}

}
}
