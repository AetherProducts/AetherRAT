
add_library(controller controller.c components/certificate.c components/rsa.c)

target_include_directories(controller PUBLIC ${CMAKE_SOURCE_DIR}/include)