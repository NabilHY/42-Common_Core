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
./srcs/target.c
OBJS = $(SRCS:.c=.o)
LIBFT_MAKEFILE = ./libft/Makefile
INCLUDE = ./includes
LIBFT_AR = ./libft/libft.a
LIBFT_INCLUDE = ./libft
PUSH_SWAP_AR = push_swap.a
ENTRY = push_swap.c
EXEC = push_swap
FSANITIZE= -g -fsanitize=address

all: $(EXEC)

$(PUSH_SWAP_AR): $(OBJS)
	@ar rcs $(PUSH_SWAP_AR) $(OBJS)

$(LIBFT_AR): $(LIBFT_INCLUDE)
	@make -C libft

$(EXEC): $(LIBFT_INCLUDE) $(INCLUDE) $(OBJS) $(LIBFT_AR) $(PUSH_SWAP_AR)
	@$(CC) $(FLAGS) $(FSANITIZE) $(ENTRY)  $(PUSH_SWAP_AR) $(LIBFT_AR) -o $(EXEC)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@make clean -C libft
fclean: clean
	@rm -rf $(PUSH_SWAP_AR) $(EXEC)
	@make fclean -C libft
re: fclean all

.PHONY: libft