file(GLOB SRC_FILES *.cpp)
file(GLOB HEADER_FILES *.h)
target_sources(main PRIVATE ${SRC_FILES} ${HEADER_FILES})