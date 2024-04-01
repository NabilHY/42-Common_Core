CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/parsing_utilities.c \
./srcs/push.c \
./srcs/reverse_rotate.c \
./srcs/swap.c \
./srcs/sorting_utilities.c \
./srcs/algo.c \
./srcs/tiny_sort.c \
./srcs/rotate.c	\
./srcs/utils.c \
./srcs/free.c \
./srcs/target.c \
./srcs/cost.c \
./srcs/sort.c \
./srcs/sort2.c \
./srcs/chunk.c
BONUS_SRCS = ./srcs/parsing_utilities.c \
./srcs/push.c \
./srcs/reverse_rotate.c \
./srcs/swap.c \
./srcs/parsing_utilities.c \
./srcs/free.c \
./srcs/utils.c \
./srcs/rotate.c \
./bonus/checker.c \
./bonus/bonus_utils.c \
./bonus/get_next_line.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBFT_MAKEFILE = ./libft/Makefile
INCLUDE = ./includes
LIBFT_AR = ./libft/libft.a
LIBFT_INCLUDE = ./libft
PUSH_SWAP_AR = push_swap.a
ENTRY = push_swap.c
EXEC = push_swap
BONUS_INCLUDE = ./includes/checker.h
BONUS_AR = checker.a
BONUS_ENTRY = ./bonus/checker.c
BONUS_EXEC = checker
FSANITIZE= -g -fsanitize=address

all: $(EXEC)

bonus: $(BONUS_EXEC)

$(PUSH_SWAP_AR): $(OBJS)
	@ar rcs $(PUSH_SWAP_AR) $(OBJS)

$(BONUS_AR): $(BONUS_OBJS)
	@ar rcs $(BONUS_AR) $(BONUS_OBJS)

$(LIBFT_AR): $(LIBFT_INCLUDE)
	@make -C libft

$(EXEC): $(LIBFT_INCLUDE) $(INCLUDE) $(OBJS) $(LIBFT_AR) $(PUSH_SWAP_AR)
	@$(CC) $(FLAGS) $(FSANITIZE) $(ENTRY)  $(PUSH_SWAP_AR) $(LIBFT_AR) -o $(EXEC)

$(BONUS_EXEC): $(LIBFT_INCLUDE) $(BONUS_INCLUDE) $(BONUS_OBJS) $(LIBFT_AR) $(BONUS_AR)
	@$(CC) $(FLAGS) $(FSANITIZE) $(BONUS_ENTRY)  $(BONUS_AR) $(LIBFT_AR) -o $(BONUS_EXEC)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@make clean -C libft
	@rm -rf $(BONUS_OBJS)
fclean: clean
	@rm -rf $(PUSH_SWAP_AR) $(EXEC)
	@make fclean -C libft
	@rm -rf $(BONUS_AR) $(BONUS_EXEC)
re: fclean all

.PHONY: libft