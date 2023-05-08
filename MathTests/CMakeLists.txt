set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB_RECURSE Source ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*)
add_executable(MathTests ${Source})
target_include_directories(MathTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(MathTests PRIVATE Math)
target_link_libraries(MathTests PRIVATE -lgtest)