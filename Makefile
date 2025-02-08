NAME = push_swap
LIBNAME = $(NAME).a
CFLAGS = -Wall -Werror -Wextra
INCLUDE_LIBFT = -L ../libft -l:libft.a
CFILES = UTILS/PARSER/parser.c UTILS/push_swap.c UTILS/SORT/stack_utils.c UTILS/SORT/stack_utils2.c UTILS/SORT/sort_utils.c UTILS/RULES/pushs_and_swaps.c UTILS/RULES/rotates.c UTILS/SORT/sort.c

OFILES = $(CFILES:.c=.o)

$(LIBNAME) : $(OFILES)
	@make -C ../libft
	@rm -f $(LIBNAME)
	@cp ../libft/libft.a $(LIBNAME)
	@ar -rc $(LIBNAME) $(OFILES)

%.o : %.c compiled
	@cc $(CFLAGS) -I INCLUDES -c $< -o $@ $(INCLUDE_LIBFT) -g

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

rerun: rec
	@cc UTILS/push_swap.c -L . -l:$(LIBNAME) $(INCLUDE_LIBFT) -o $(NAME) -g
