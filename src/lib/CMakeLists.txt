add_library(leetcode STATIC
        include/leetcode/709.hpp
        src/709.cpp
        )
target_include_directories(leetcode
        PUBLIC include
        PRIVATE src
        )
