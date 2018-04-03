cmake_minimum_required(VERSION 3.5)

project(pattern-hyper-view LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pattern-hyper-view main.cpp
    AGuestOS.h AHypervisor.h AVirtM.h CHyperV.cpp CHyperV.h CHyperVVirtM.h CLinux.h CTaskEvent.h CWindows.h InonCopyable.h)

include(GNUInstallDirs)
install(TARGETS pattern-hyper-view
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Werror")
message(STATUS "C++ RELEASE FLAGS: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ DEBUG FLAGS: ${CMAKE_CXX_FLAGS_DEBUG}")
