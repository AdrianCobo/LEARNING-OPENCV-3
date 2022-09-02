CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_7 )
set (CMAKE_CXX_STANDARD 17)
FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABLE( excercises excercises.cpp )
TARGET_LINK_LIBRARIES( excercises ${OpenCV_LIBS} )

ADD_EXECUTABLE( random_number_generator random_number_generator.cpp )
TARGET_LINK_LIBRARIES( random_number_generator ${OpenCV_LIBS} )
