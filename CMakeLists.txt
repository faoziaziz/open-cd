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
set(INCLUDE_DIRS ${INClUDE_DIRS} $ENV{HOME}/.local/include/tesseract)
set(INCLUDE_DIRS ${INClUDE_DIRS} $ENV{HOME}/.local/include/leptonica)
set(INCLUDE_DIRS ${INClUDE_DIRS} $ENV{HOME}/.local/include)

# Assign Include directory
include_directories(${INCLUDE_DIRS})
include(FindPkgConfig)

pkg_check_modules(LIBTESSERACT REQUIRED tesseract)
pkg_check_modules(LIBLEPTONICA REQUIRED lept)
pkg_check_modules(OpenCV REQUIRED opencv)
#pkg_check_modules(OpenCV REQUIRED opencv_imgcodecs)

foreach(FLAG ${LIBTESSERACT_CXXFLAGS_OTHER})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG}")
endforeach()

foreach(FLAG ${LIBLEPTONICA_CXXFLAGS_OTHER})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG}")
endforeach()

foreach(FLAG ${OpenCV_CXXFLAGS_OTHER})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG}")
endforeach()


link_directories(${LIBTESSERACT_LIBRARY_DIRS})
link_directories(${LIBLEPTONICA_LIBRARY_DIRS})

#to include cpp runtime
# link_directories(/usr/lib) # in the case of linked directory should be done
link_directories(${CMAKE_SOURCE_DIR}/lib64)
link_directories($ENV{HOME}/.local/lib64)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


# linked to the library
target_include_directories(${PROJECT_NAME} PRIVATE ${LIBTESSERACT_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${LIBLEPTONICA_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV})
# linked to the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBTESSERACT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBLEPTONICA_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE opencv_imgcodecs opencv_core)
