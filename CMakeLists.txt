cmake_minimum_required(VERSION 3.26)
project(osc_exam C)

set(CMAKE_C_STANDARD 11)

add_executable(c_exam main.c)

file (GLOB_RECURSE nomains ${CMAKE_SOURCE_DIR}/*.c)
list(FILTER nomains EXCLUDE REGEX ".*(m_|CMake|main).*")
foreach (nomain ${nomains})
    message(${nomain})
endforeach ()

file (GLOB_RECURSE files *.c)
list(FILTER files INCLUDE REGEX ".*(m_).*")
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} ${nomains})
    #    set_target_properties(${exe} PROPERTIES OUTPUT_NAME "${exe}.exe")
    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})