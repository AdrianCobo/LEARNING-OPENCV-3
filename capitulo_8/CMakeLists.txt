CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_8 )
set (CMAKE_CXX_STANDARD 17)
FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABLE( excercise_1 excercise_1.cpp )
TARGET_LINK_LIBRARIES( excercise_1 ${OpenCV_LIBS} )

ADD_EXECUTABLE( excercise_2 excercise_2.cpp )
TARGET_LINK_LIBRARIES( excercise_2 ${OpenCV_LIBS} )

ADD_EXECUTABLE( excercise_3 excercise_3.cpp )
TARGET_LINK_LIBRARIES( excercise_3 ${OpenCV_LIBS} )

ADD_EXECUTABLE( identify_video_codec identify_video_codec.cpp )
TARGET_LINK_LIBRARIES( identify_video_codec ${OpenCV_LIBS} )

ADD_EXECUTABLE( create_yaml_file create_yaml_file.cpp )
TARGET_LINK_LIBRARIES( create_yaml_file ${OpenCV_LIBS} )

ADD_EXECUTABLE( read_yaml_file read_yaml_file.cpp )
TARGET_LINK_LIBRARIES( read_yaml_file ${OpenCV_LIBS} )