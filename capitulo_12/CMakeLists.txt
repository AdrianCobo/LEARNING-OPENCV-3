CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_11 )
set (CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE( covolutions covolutions.cpp )
TARGET_LINK_LIBRARIES( covolutions ${OpenCV_LIBS} )

ADD_EXECUTABLE( find_circles find_circles.cpp )
TARGET_LINK_LIBRARIES( find_circles ${OpenCV_LIBS} )

ADD_EXECUTABLE( background_removal background_removal.cpp )
TARGET_LINK_LIBRARIES( background_removal ${OpenCV_LIBS} )

ADD_EXECUTABLE( image_segmentation image_segmentation.cpp )
TARGET_LINK_LIBRARIES( image_segmentation ${OpenCV_LIBS} )