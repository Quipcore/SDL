project(chess)

set(HEADER_FILES
        chess.h
        )

set(SOURCE_FILES
        chess.cpp )

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})