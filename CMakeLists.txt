cmake_minimum_required(VERSION 3.13)
project(push_swap)
#
set(CMAKE_CXX_STANDARD 14)
##set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
#
include_directories(.)
include_directories(lib/printf)
include_directories(src)
include_directories(lib/printf/libft)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
file(GLOB libft
        "lib/printf/libft/*.h"
        "lib/printf/libft/*.c"
        )
file(GLOB printf
        "lib/printf/*.h"
        "lib/printf/*.c"
        )
#file(GLOB src
#        "src/*.h"
#        "src/*.c"
#        "main.c"
#        )
file(GLOB checker
        "src/algorithm.c"
        "src/algorithm2.c"
        "src/aux.c"
        "src/aux2.c"
        "src/checker-parser.c"
        "src/checker.c"
        "src/logic.c"
        "src/ps_commands.c"
        "src/ps_commands2.c"
        "src/ps_commands3.c"
        "src/ps_commands4.c"
        "src/ring_functions.c"
        "src/split_a_top.c"
        "src/split_b_bot.c"
        "src/splits_check.c"
        "src/splt_b_top.c"
        "src/validate.c"
        "src/utilities.c"
        "src/checker_parser.c"
        "src/ps_commands5.c"
        )
file(GLOB push_swap
        "src/algorithm.c"
        "src/algorithm2.c"
        "src/aux.c"
        "src/aux2.c"
        "src/checker-parser.c"
        "src/logic.c"
        "src/main.c"
        "src/ps_commands.c"
        "src/ps_commands2.c"
        "src/ps_commands3.c"
        "src/ps_commands4.c"
        "src/ring_functions.c"
        "src/split_a_top.c"
        "src/split_b_bot.c"
        "src/splits_check.c"
        "src/splt_b_top.c"
        "src/validate.c"
        "src/utilities.c"
        "src/checker_parser.c"
        "src/ps_commands5.c"
        )
#add_executable(checker ${libft} ${stack} ${push_swap_lib} ${get_next_line}
#        checker.c )
add_executable(push_swap ${libft} ${printf} ${push_swap})
add_executable(checker ${libft} ${printf} ${checker})