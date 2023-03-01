cmake_minimum_required(VERSION 3.24)
project(PROGRAM_DIETA_MAKER)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROGRAM_DIETA_MAKER main.cpp function.h opti_func.cpp gets_part_of_body.cpp food_data_base.cpp all_calc_function.cpp all_user_database_function.cpp game.cpp)
