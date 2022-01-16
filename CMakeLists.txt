cmake_minimum_required(VERSION 3.21)
project(libgt)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)
# -Wall     : Enable most warning messages.
# -Wextra   : Print extra (possibly unwanted) warnings.
# -Werror   : Treat all warnings as errors.
set(SRCDIR ${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${SRCDIR}/*.cpp ${SRCDIR}/*.c)

foreach (item ${SOURCES})
    get_filename_component(s ${item} NAME_WE)
    file(STRINGS ${item} strout)
    string(FIND "${strout}" "main(" result)
    if (NOT result EQUAL -1)
        add_executable(${s} ${item})
    endif ()
endforeach ()

## multiple source executable
#  source file with main function named as executable
#  add additional sources and libraries like below
#  target_sources(<executable-name> PUBLIC <additional-sources>)
#  target_link_libraries(<executable-name> <library-name>)

## remove all files in build directory
add_custom_target(clear rm -rf ${PROJECT_BINARY_DIR}/.* ${PROJECT_BINARY_DIR}/* 2>&-)

target_sources(str_ops_main PUBLIC src/io/str/str_len.c src/io/str/str_concat.c src/io/str/str_cmp.c src/io/str/str_rev.c src/io/str/str_sort.c)
target_sources(extern_main PUBLIC src/storage-classes/extern_func.c)
target_sources(bit_manup_main PUBLIC src/bits/bin_to_dec.c src/bits/dec_to_bin.c)
target_link_libraries(bit_manup_main m)
target_sources(set_read_bits_main PUBLIC src/bits/dec_to_bin.c)
target_sources(line_with_char_main PUBLIC src/io/str/has_ch.c)
target_sources(number_classification_main PUBLIC src/math-ops/is_prime.c src/math-ops/is_odd.c)
target_sources(variadic_main PUBLIC src/math-ops/variadic_avg.c)
target_sources(reverse_string_main PUBLIC src/io/reverse_string_rec.c)

add_library(slib STATIC src/libs/slib.c src/libs/slib.h)
target_link_libraries(slib_driver slib)

# str_functions library STATIC compiled
add_library(str_functions_s STATIC src/libs/str_functions.c src/libs/str_functions.h)
target_link_libraries(lib_string_driver str_functions_s)

add_library(dlib SHARED src/libs/dlib.c src/libs/dlib.h)
target_link_libraries(dlib_driver dlib)

# str_functions library SHARED compiled (used in dynamic loading)
add_library(str_functions_d SHARED src/libs/str_functions.c src/libs/str_functions.h)

target_link_libraries(dynamic_loading dl)
target_link_libraries(assert_main m)

target_link_libraries(thread_example1_main pthread)
target_link_libraries(thread_pass_args_main pthread)
target_link_libraries(thread_pass_mult_args_main pthread)
target_link_libraries(thread_return_val_main pthread)
target_link_libraries(thread_pthread_self_main pthread)
target_link_libraries(thread_detach_main pthread)
target_link_libraries(thread_get_set_stacksize_main pthread)
target_link_libraries(thread_cancel_main pthread)
target_link_libraries(thread_mutex_create_lock_unlock_main pthread)
target_link_libraries(thread_mutex_create_lock_unlock2_main pthread)
target_link_libraries(thread_deadlock_main pthread)
target_link_libraries(thread_cond_variables_main pthread)
target_link_libraries(thread_mix_example_main pthread)

