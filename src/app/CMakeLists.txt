ADD_EXECUTABLE(Hello hello.c)

ADD_EXECUTABLE(test_vec3 test_vec3.c)
TARGET_LINK_LIBRARIES(test_vec3 fw)

ADD_EXECUTABLE(test_vec3_array test_vec3_array.c)
TARGET_LINK_LIBRARIES(test_vec3_array fw)

ADD_EXECUTABLE(test_sdl test_sdl.c)
TARGET_LINK_LIBRARIES(test_sdl fw SDL SDLmain)

ADD_EXECUTABLE(test_mesh test_mesh.c)
TARGET_LINK_LIBRARIES(test_mesh fw ${GLUT_AND_DEPENDENCIES})

ADD_EXECUTABLE(test_hash test_hash.c)
TARGET_LINK_LIBRARIES(test_hash fw)

ADD_EXECUTABLE(test_opencl test_opencl.c)
TARGET_LINK_LIBRARIES(test_opencl fw "-framework OpenCL")


SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR} )
add_library(dlcode SHARED dlcode.c)
ADD_EXECUTABLE(test_dl test_dl.c)
TARGET_LINK_LIBRARIES(test_dl fw)