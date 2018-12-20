add_library(leetcode STATIC
        include/leetcode/4.hpp
        src/4.cpp
        include/leetcode/5.hpp
        src/5.cpp
        include/leetcode/6.hpp
        src/6.cpp
        include/leetcode/709.hpp
        src/709.cpp
        )
target_include_directories(leetcode
        PUBLIC include
        PRIVATE src
        )
