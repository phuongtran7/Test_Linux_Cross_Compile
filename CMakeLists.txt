cmake_minimum_required(VERSION 3.0.0)
project(Test_Linux_Cross_Compile VERSION 0.1.0)

add_executable(Test_Linux_Cross_Compile main.cpp SocketHelper.h SocketHelper.cpp)
target_link_libraries(Test_Linux_Cross_Compile PRIVATE ws2_32)