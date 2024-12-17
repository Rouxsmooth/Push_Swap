NAME = push_swap
LIBNAME = $(NAME).a
CFLAGS = -Wall -Werror -Wextra
CFILES = 

OFILES = $(CFILES:.c=.o)

$(LIBNAME) : $(OFILES)
	@rm -f $(LIBNAME)
	@ar -rc $(LIBNAME) $(OFILES)

%.o : %.c compiled
	@cc $(CFLAGS) -I INCLUDES -c $< -o $@

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
	@cc main.c -L . -l:$(LIBNAME) -o $(NAME) && ./$(NAME) 

rerunwithflags: rec
	@cc $(CFLAGS) main.c -L . -l:$(LIBNAME) -o $(NAME) && ./$(NAME) 

rerunvalgrind: rec
	@cc main.c -L . -l:$(LIBNAME) -o $(NAME) && valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 

rerunvalgrindwithflags: rec
	@cc $(CFLAGS) main.c -L . -l:$(LIBNAME) -o $(NAME) && valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 

re : fclean $(LIBNAME)