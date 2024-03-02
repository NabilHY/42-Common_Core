CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/parsing_utilities.c
OBJS = $(SRCS:.c=.o)
LIBFT_MAKEFILE = ./libft/Makefile
INCLUDE = ./includes/push_swap.h
LIBFT_AR = ./libft/libft.a
LIBFT_INCLUDE = ./libft/libft.h
PUSH_SWAP_AR = push_swap.a
ENTRY = push_swap.c
EXEC = push_swap

all: $(EXEC)

$(PUSH_SWAP_AR): $(OBJS)
	ar rcs $(PUSH_SWAP_AR) $(OBJS)

$(LIBFT_AR): $(LIBFT_INCLUDE)
	make -C libft

$(EXEC): $(LIBFT_INCLUDE) $(INCLUDE) $(OBJS) $(LIBFT_AR) $(PUSH_SWAP_AR)
	$(CC) $(FLAGS) $(LIBFT_AR) $(PUSH_SWAP_AR) $(ENTRY) -o $(EXEC)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@
	
clean:
	rm -rf $(OBJS)
	make clean -C libft
fclean: clean
	rm -rf $(PUSH_SWAP_AR) $(EXEC)
	make fclean -C libft
re: fclean all

.PHONY: libft