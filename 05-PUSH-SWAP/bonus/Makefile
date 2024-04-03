CC = cc
FLAGS = -Wall -Wextra -Werror
BONUS_SRCS = ./srcs/push_bonus.c \
./srcs/swap_bonus.c \
./srcs/free_bonus.c \
./srcs/utils_bonus.c \
./srcs/rotate_bonus.c \
./srcs/get_next_line_bonus.c \
./srcs/get_next_line_utils_bonus.c \
./srcs/parsing_utilities_bonus.c \
./srcs/push_bonus.c \
./srcs/reverse_rotate_bonus.c \
./srcs/swap_bonus.c \
./srcs/rotate_bonus.c	\
./srcs/free_bonus.c	\
./srcs/bonus_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBFT_MAKEFILE = ./libft/Makefile
INCLUDE = ./includes
LIBFT_AR = ./libft/libft.a
LIBFT_INCLUDE = ./libft
BONUS_INCLUDE = ./includes/checker_bonus.h
BONUS_AR = checker.a
BONUS_ENTRY = checker_bonus.c
BONUS_EXEC = checker
FSANITIZE= -g -fsanitize=address

all: $(BONUS_EXEC)

$(BONUS_AR): $(BONUS_OBJS)
	@ar rcs $(BONUS_AR) $(BONUS_OBJS)

$(LIBFT_AR): $(LIBFT_INCLUDE)
	@make -C libft

$(BONUS_EXEC): $(LIBFT_INCLUDE) $(BONUS_INCLUDE) $(BONUS_OBJS) $(LIBFT_AR) $(BONUS_AR)
	@$(CC) $(FLAGS) $(FSANITIZE) $(BONUS_ENTRY)  $(BONUS_AR) $(LIBFT_AR) -o $(BONUS_EXEC)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(BONUS_OBJS)
fclean: clean
	@make fclean -C libft
	@rm -rf $(BONUS_AR) $(BONUS_EXEC)
re: fclean all

.PHONY: libft