CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_14 )
set (CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE( contours_using_trackbar contours_using_trackbar.cpp )
TARGET_LINK_LIBRARIES( contours_using_trackbar ${OpenCV_LIBS} )

ADD_EXECUTABLE( drawing_contours drawing_contours.cpp )
TARGET_LINK_LIBRARIES( drawing_contours ${OpenCV_LIBS} )

ADD_EXECUTABLE( lebeled_conected_components lebeled_conected_components.cpp )
TARGET_LINK_LIBRARIES( lebeled_conected_components ${OpenCV_LIBS} )

ADD_EXECUTABLE( shape_contect_distance_extractor shape_contect_distance_extractor.cpp )
TARGET_LINK_LIBRARIES( shape_contect_distance_extractor ${OpenCV_LIBS} )


