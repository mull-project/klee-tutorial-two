include("Mull.extensions.cmake")

set(MULL_CC  "${CMAKE_CURRENT_SOURCE_DIR}/mull-clang")
set(MULL_CXX "${CMAKE_CURRENT_SOURCE_DIR}/mull-clang++")

set(klee_tutorial_two_sources klee-tutorial-two.cpp)
add_executable(klee-tutorial-two ${klee_tutorial_two_sources})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${MULL_SOURCE_DIR}/googletest/include")

target_link_libraries(klee-tutorial-two google-test)

mull_clone_target(klee-tutorial-two klee-tutorial-two-bitcode)
set_target_properties(klee-tutorial-two-bitcode PROPERTIES XCODE_ATTRIBUTE_CC "${MULL_CC}")
set_target_properties(klee-tutorial-two-bitcode PROPERTIES XCODE_ATTRIBUTE_CXX "${MULL_CXX}")

mull_clone_target(mull-driver mull-klee-tutorial-two-driver)

add_dependencies(mull-klee-tutorial-two-driver
  klee-tutorial-two-bitcode
  google-test-bitcode
)
