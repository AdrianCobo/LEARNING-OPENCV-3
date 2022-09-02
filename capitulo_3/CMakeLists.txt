CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv )
set (CMAKE_CXX_STANDARD 17)
FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABLE( simple_image simple_image.cpp )
TARGET_LINK_LIBRARIES( simple_image ${OpenCV_LIBS} )

ADD_EXECUTABLE( simple_video simple_video.cpp )
TARGET_LINK_LIBRARIES( simple_video ${OpenCV_LIBS} )

ADD_EXECUTABLE( trackbar_video trackbar_video.cpp )
TARGET_LINK_LIBRARIES( trackbar_video ${OpenCV_LIBS} )

ADD_EXECUTABLE( image_filter image_filter.cpp )
TARGET_LINK_LIBRARIES( image_filter ${OpenCV_LIBS} )

ADD_EXECUTABLE( redimension_mitad_image redimension_mitad_image.cpp )
TARGET_LINK_LIBRARIES( redimension_mitad_image ${OpenCV_LIBS} )

ADD_EXECUTABLE( color_filter_image color_filter_image.cpp )
TARGET_LINK_LIBRARIES( color_filter_image ${OpenCV_LIBS} )

ADD_EXECUTABLE( pixel_values pixel_values.cpp )
TARGET_LINK_LIBRARIES( pixel_values ${OpenCV_LIBS} )

ADD_EXECUTABLE( camera_usb camera_usb.cpp )
TARGET_LINK_LIBRARIES( camera_usb ${OpenCV_LIBS} )

ADD_EXECUTABLE( grabar_video grabar_video.cpp )
TARGET_LINK_LIBRARIES( grabar_video ${OpenCV_LIBS} )

ADD_EXECUTABLE( excercises excercises.cpp )
TARGET_LINK_LIBRARIES( excercises ${OpenCV_LIBS} )

ADD_EXECUTABLE( color_filter color_filter.cpp )
TARGET_LINK_LIBRARIES( color_filter ${OpenCV_LIBS} )