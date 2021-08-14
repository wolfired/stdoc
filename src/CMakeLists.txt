set(
    STDOC_INC
    stdoc_io.h
)
set(
    STDOC_SRC
    stdoc_io.c
)

add_library(stdoc_static STATIC ${STDOC_SRC})
target_include_directories(stdoc_static PUBLIC .)
set_target_properties(stdoc_static PROPERTIES OUTPUT_NAME "stdoc")

add_library(stdoc_shared SHARED ${STDOC_SRC})
target_include_directories(stdoc_shared PUBLIC .)
set_target_properties(stdoc_shared PROPERTIES OUTPUT_NAME "stdoc")
set_target_properties(stdoc_shared PROPERTIES VERSION ${CMAKE_PROJECT_VERSION} SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR})

install(TARGETS stdoc_static stdoc_shared LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${STDOC_INC} DESTINATION include)
