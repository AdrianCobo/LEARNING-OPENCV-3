CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_11 )
set (CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE( affine_transformation affine_transformation.cpp )
TARGET_LINK_LIBRARIES( affine_transformation ${OpenCV_LIBS} )

ADD_EXECUTABLE( perspective_transformation perspective_transformation.cpp )
TARGET_LINK_LIBRARIES( perspective_transformation ${OpenCV_LIBS} )

ADD_EXECUTABLE( log_polar_transformation log_polar_transformation.cpp )
TARGET_LINK_LIBRARIES( log_polar_transformation ${OpenCV_LIBS} )

ADD_EXECUTABLE( excercises excercises.cpp )
TARGET_LINK_LIBRARIES( excercises ${OpenCV_LIBS} )