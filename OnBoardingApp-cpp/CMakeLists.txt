cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME OnBoardingApp-cpp)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Core Network REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Network REQUIRED)

set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
	
set( SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories( ${INCLUDE_DIR} )

file( GLOB HEADERS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp")
file( GLOB SOURCES "${SRC_DIR}/*.c" "${SRC_DIR}/*.cpp" )

set( PROJECT_SOURCES ${SOURCES} ${HEADERS} resources.qrc )

if(${QT_VERSION_MAJOR} GREATER_EQUAL)
    qt_add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Widgets
                                       Qt5::Network
                                       Qt5::Core)
