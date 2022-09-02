CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_10 )
set (CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
find_package( OpenGL )

include_directories( ${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} )

ADD_EXECUTABLE( threshold threshold.cpp )
TARGET_LINK_LIBRARIES( threshold ${OpenCV_LIBS} )

ADD_EXECUTABLE( threshold_v2 threshold_v2.cpp )
TARGET_LINK_LIBRARIES( threshold_v2 ${OpenCV_LIBS} )

ADD_EXECUTABLE( threshold_vs_adapthreshold threshold_vs_adapthreshold.cpp )
TARGET_LINK_LIBRARIES( threshold_vs_adapthreshold ${OpenCV_LIBS} )

ADD_EXECUTABLE( filters filters.cpp )
TARGET_LINK_LIBRARIES( filters ${OpenCV_LIBS} )
