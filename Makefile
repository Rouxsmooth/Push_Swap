NAME = push_swap
LIBNAME = $(NAME).a
CFLAGS = -Wall -Werror -Wextra
INCLUDE_LIBFT = -L INCLUDES/libft -l:libft.a
CFILES = UTILS/PARSER/parser.c UTILS/push_swap.c UTILS/SORT/stack_utils.c UTILS/SORT/stack_utils2.c UTILS/SORT/sort_utils.c UTILS/RULES/pushs_and_swaps.c UTILS/RULES/rotates.c UTILS/SORT/sort.c

OFILES = $(CFILES:.c=.o)

$(LIBNAME) : $(OFILES)
	@make -C INCLUDES/libft
	@rm -f $(LIBNAME)
	@cp INCLUDES/libft/libft.a $(LIBNAME)
	@ar -rc $(LIBNAME) $(OFILES)
	@cc UTILS/push_swap.c -L . -l:$(LIBNAME) $(INCLUDE_LIBFT) -o $(NAME)

%.o : %.c compiled
	@cc $(CFLAGS) -I INCLUDES -c $< -o $@  -g

compiled :
	@echo "All $(LIBNAME) files compiled."

all: $(LIBNAME)

clean :
	@rm -f $(OFILES) $(NAME) && echo "$(LIBNAME) object files cleaned.\n"

fclean:
	@rm -f $(OFILES) $(LIBNAME) $(NAME) && echo "$(LIBNAME) cleaned.\n"

re: fclean all

norm:
	@norminette | grep -E --color=always "Error" || echo "\e[32mnorminette is fine!\e[0m"

allc: $(LIBNAME) clean

rec: fclean allc

test100:
	@bash -c 'ARG="$$(seq -10000 10000 | shuf | head -n 100 | tr "\n" " ")"; ./push_swap $$ARG'

checker100:
	@bash -c 'ARG="$$(seq -10000 10000 | shuf | head -n 100 | tr "\n" " ")"; ./push_swap $$ARG | ./checker_linux $$ARG'

test500:
	@bash -c 'ARG="$$(seq -10000 10000 | shuf | head -n 500 | tr "\n" " ")"; ./push_swap $$ARG'

checker500:
	@bash -c 'ARG="$$(seq -10000 10000 | shuf | head -n 500 | tr "\n" " ")"; ./push_swap $$ARG | ./checker_linux $$ARG'

.PHONY: test100 checker100 checker500 test500