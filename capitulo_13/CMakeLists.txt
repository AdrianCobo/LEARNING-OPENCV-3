CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_13 )
set (CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE( hsv_histogram hsv_histogram.cpp )
TARGET_LINK_LIBRARIES( hsv_histogram ${OpenCV_LIBS} )

ADD_EXECUTABLE( signatures_histograms_EMD signatures_histograms_EMD.cpp )
TARGET_LINK_LIBRARIES( signatures_histograms_EMD ${OpenCV_LIBS} )

ADD_EXECUTABLE( template_matching template_matching.cpp )
TARGET_LINK_LIBRARIES( template_matching ${OpenCV_LIBS} )

ADD_EXECUTABLE( excercise excercise.cpp )
TARGET_LINK_LIBRARIES( excercise ${OpenCV_LIBS} )