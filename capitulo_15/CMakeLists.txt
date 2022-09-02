CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_14 )
set (CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE( rgb_values rgb_values.cpp )
TARGET_LINK_LIBRARIES( rgb_values ${OpenCV_LIBS} )

ADD_EXECUTABLE( background_model background_model.cpp )
TARGET_LINK_LIBRARIES( background_model ${OpenCV_LIBS} )

ADD_EXECUTABLE( on_off_diagonal_elements on_off_diagonal_elements.cpp )
TARGET_LINK_LIBRARIES( on_off_diagonal_elements ${OpenCV_LIBS} )

ADD_EXECUTABLE( codebook_algorithm codebook_algorithm.cpp )
TARGET_LINK_LIBRARIES( codebook_algorithm ${OpenCV_LIBS} )

ADD_EXECUTABLE( cleanaup_connected_components cleanaup_connected_components.cpp )
TARGET_LINK_LIBRARIES( cleanaup_connected_components ${OpenCV_LIBS} )

ADD_EXECUTABLE( background_substractor_clase background_substractor_clase.cpp )
TARGET_LINK_LIBRARIES( background_substractor_clase ${OpenCV_LIBS} )
