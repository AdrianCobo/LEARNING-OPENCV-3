CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_9 )
set (CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
find_package( OpenGL )

include_directories( ${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} )

ADD_EXECUTABLE( open_image open_image.cpp )
TARGET_LINK_LIBRARIES( open_image ${OpenCV_LIBS} )

ADD_EXECUTABLE( draw_rectangle_using_mouse draw_rectangle_using_mouse.cpp )
TARGET_LINK_LIBRARIES( draw_rectangle_using_mouse ${OpenCV_LIBS} )

ADD_EXECUTABLE( switch_with_trackbar switch_with_trackbar.cpp )
TARGET_LINK_LIBRARIES( switch_with_trackbar ${OpenCV_LIBS} )

ADD_EXECUTABLE( video_cube_draw video_cube_draw.cpp )
TARGET_LINK_LIBRARIES( video_cube_draw ${OpenCV_LIBS} ${OPENGL_LIBRARIES})

ADD_EXECUTABLE( excercises excercises.cpp )
TARGET_LINK_LIBRARIES( excercises ${OpenCV_LIBS})

ADD_EXECUTABLE( excercise_4 excercise_4.cpp )
TARGET_LINK_LIBRARIES( excercise_4 ${OpenCV_LIBS})

ADD_EXECUTABLE( excercise_5 excercise_5.cpp )
TARGET_LINK_LIBRARIES( excercise_5 ${OpenCV_LIBS})

