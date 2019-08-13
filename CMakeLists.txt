cmake_minimum_required(VERSION 3.5)

# Definition
set(PROJECT_NAME ex-OPenCV)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# In the case of libary configuration of redhat it will be error so I add this code.
#set(ENV{PKG_CONFIG_PATH} ${ENV{PKG_CONFIG_PATH}} "$ENV{HOME}/.local/lib/pkgconfig")
#set(ENV{PKG_CONFIG_PATH} ${ENV{PKG_CONFIG_PATH}} "$ENV{HOME}/.local/lib64/pkgconfig")


# Include path
set(INCLUDE_DIRS ${INClUDE_DIRS} $ENV{HOME}/.local/include)

# link_directories(/usr/lib) # in the case of linked directory should be done
link_directories($ENV{HOME}/.local/lib)
link_directories($ENV{HOME}/.local/lib64)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


# linked to the library
target_include_directories(${PROJECT_NAME} PRIVATE $ENV{HOME}/.local/include)

# linked to the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE opencv_imgcodecs opencv_core opencv_imgproc opencv_highgui opencv_videoio)
