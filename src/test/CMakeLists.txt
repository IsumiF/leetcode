add_executable(leetcode-test
        src/main.cpp
        src/leetcode/5.cpp
        src/leetcode/6.cpp
        src/leetcode/709.cpp
        )

target_link_libraries(leetcode-test
        leetcode
        Catch2::Catch2
        )

add_test(leetcode-test leetcode-test)