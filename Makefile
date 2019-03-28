# COLORS

CYAN = \033[1;96m
YEL = \033[0;33m
GRN = \033[0;32m
RESET = \033[0m

# MAIN CONFIG

PUSH_SWAP_BIN = push_swap
CHECKER_BIN = checker

# GCC COMPILATOR PART CONF

CC = gcc
FLAGS = 
LIBRARIES = -lft -L$(PRINTF_DIR)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(PRINTF_HEADERS)ft_printf.h

# LIB SRC AND DST PART CONF

PRINTF = $(PRINTF_DIR)libftprintf.a
PRINTF_DIR = ./lib/printf/
PRINTF_HEADERS = $(PRINTF_DIR)

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./src/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#	Функция addprefix добавляет свой первый аргумент ко всем целям, 
#	которые задает второй аргумент.

SRC_DIR = ./src/
SRC_LST = 	algorithm.c\
	algorithm2.c\
	aux.c\
	aux2.c\
	checker_parser.c\
	logic.c\
	ps_commands.c\
	ps_commands2.c\
	ps_commands3.c\
	ps_commands4.c\
	ring_functions.c\
	split_a_top.c\
	split_b_bot.c\
	splits_check.c\
	splt_b_top.c\
	utilities.c\
	validate.c

SRC_PUSH_SWAP_BIN = main.c
SRC_CHECKER_BIN = checker.c

SOURCES = $(addprefix $(SRC_DIR), $(SRC_LST))
SOURCES_PS = $(addprefix $(SRC_DIR), $(SRC_PUSH_SWAP_BIN))
SOURCES_CH = $(addprefix $(SRC_DIR), $(SRC_CHECKER_BIN))

# 	Функция patsubsb уберет префикс ../../ у имен файлов (она заменяет шаблон, 
#	заданный первым аргументом на шаблон во втором аргументе, а % обозначает любое количество символов)

OBJ_DIR = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC_LST))
OBJECTS_LIST_PS = $(patsubst %.c, %.o, $(SRC_PUSH_SWAP_BIN))
OBJECTS_LIST_CH = $(patsubst %.c, %.o, $(SRC_CHECKER_BIN))
OBJECTS	= $(addprefix $(OBJ_DIR), $(OBJECTS_LIST))
OBJECTS_PS = $(addprefix $(OBJ_DIR), $(OBJECTS_LIST_PS))
OBJECTS_CH = $(addprefix $(OBJ_DIR), $(OBJECTS_LIST_CH))

.PHONY: all clean fclean re

#	RULES and stuff

all: $(PUSH_SWAP_BIN) $(CHECKER_BIN)

$(PUSH_SWAP_BIN): $(PRINTF) $(OBJ_DIR) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(PRINTF) $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) -o $(PUSH_SWAP_BIN)
	@echo "\n$(PUSH_SWAP_BIN): $(CYAN)$(PUSH_SWAP_BIN) object files were created$(RESET)"
	@echo "$(PUSH_SWAP_BIN): $(GRN)$(PUSH_SWAP_BIN) was created$(RESET)"

$(CHECKER_BIN): $(PRINTF) $(OBJ_DIR) $(OBJECTS) $(OBJECTS_CH)
	@$(CC) $(FLAGS) $(PRINTF) $(INCLUDES) $(OBJECTS) $(OBJECTS_CH) -o $(CHECKER_BIN)
	@echo "\n$(PUSH_SWAP_BIN): $(CYAN)$(CHECKER_BIN) object files were created$(RESET)"
	@echo "$(PUSH_SWAP_BIN): $(GRN)$(CHECKER_BIN) was created$(RESET)"


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(PUSH_SWAP_BIN): $(CYAN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(CYAN).$(RESET)\c"

$(PRINTF):
	@echo "$(PUSH_SWAP_BIN): $(CYAN)creating $(PRINTF)...$(RESET)"
	@$(MAKE) -sC $(PRINTF_DIR)

clean:
	@$(MAKE) -sC $(PRINTF_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(PUSH_SWAP_BIN): $(YEL)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(PUSH_SWAP_BIN): $(YEL)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(PRINTF)
	@echo "$(PUSH_SWAP_BIN): $(YEL)$(PRINTF) was deleted$(RESET)"
	@rm -f $(PUSH_SWAP_BIN)
	@echo "$(PUSH_SWAP_BIN): $(YEL)$(PUSH_SWAP_BIN) was deleted$(RESET)"
	@rm -f $(CHECKER_BIN)
	@echo "$(PUSH_SWAP_BIN): $(YEL)$(CHECKER_BIN) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all