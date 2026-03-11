NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	adaptive.c \
	assign_indices.c \
	bench.c \
	bench_count.c \
	bench_print_1.c \
	bench_print_2.c \
	bench_utils.c \
	operation.c \
	operation_p.c \
	operation_r.c \
	operation_rr.c \
	parse_flags.c \
	phases.c \
	push_pop.c \
	radix.c \
	range.c \
	run_mode.c \
	size_rotate_search.c \
	sort_3__sort_5__simple.c \
	sort_min_max.c \
	split.c \
	stack_builder.c \
	stack_unitls.c \
	utils.c \
	utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
