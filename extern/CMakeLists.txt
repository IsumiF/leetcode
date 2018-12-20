include(FetchContent)

FetchContent_Declare(
        catch
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.5.0
)
FetchContent_GetProperties(catch)
if (NOT catch_POPULATED)
    FetchContent_Populate(catch)
    add_subdirectory(${catch_SOURCE_DIR} ${catch_BINARY_DIR})
endif ()

FetchContent_Declare(
        rapidcheck
        GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
        GIT_TAG 3eb9b4ff69f4ff2d9932e8f852c2b2a61d7c20d3
)
FetchContent_GetProperties(rapidcheck)
if (NOT rapidcheck_POPULATED)
    FetchContent_Populate(rapidcheck)
    add_subdirectory(${rapidcheck_SOURCE_DIR} ${rapidcheck_BINARY_DIR})
endif ()
