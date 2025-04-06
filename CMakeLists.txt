cmake_minimum_required(VERSION 3.11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project(AetherRAT)

add_executable(${PROJECT_NAME} src/main.c src/app/app.c)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/controller)


find_package(OpenSSL REQUIRED) 

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENSSL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}
    controller
    OpenSSL::SSL
    OpenSSL::Crypto
)

