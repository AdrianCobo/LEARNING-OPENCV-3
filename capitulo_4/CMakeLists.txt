CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT( course_opencv_cap_4 )
set (CMAKE_CXX_STANDARD 17)
FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABLE( excercises excercises.cpp )
TARGET_LINK_LIBRARIES( excercises ${OpenCV_LIBS} )

ADD_EXECUTABLE( sum_matrix_by_planes sum_matrix_by_planes.cpp )
TARGET_LINK_LIBRARIES( sum_matrix_by_planes ${OpenCV_LIBS} )

ADD_EXECUTABLE( sum_2matriz_using_narrayop sum_2matriz_using_narrayop.cpp )
TARGET_LINK_LIBRARIES( sum_2matriz_using_narrayop ${OpenCV_LIBS} )

ADD_EXECUTABLE( print_nonzer_sparsearray print_nonzer_sparsearray.cpp )
TARGET_LINK_LIBRARIES( print_nonzer_sparsearray ${OpenCV_LIBS} )

ADD_EXECUTABLE( better_sparse_matrix_print better_sparse_matrix_print.cpp )
TARGET_LINK_LIBRARIES( better_sparse_matrix_print ${OpenCV_LIBS} )