NAME = exsys

SRC_PATH = 	srcs/
SRC_NAME =	main.c           process_file.c         \
			read_file.c      rpn_parsing.c          \
			stack.c          graph.c		        \
			fact.c 			 operand.c		        \
			implication.c	 compute_graph_state.c	\
			rule_parsing.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

INC_PATH = 	includes/

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -O0 -ggdb
RM = rm -f


all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRC) -I $(INC_PATH) -o $(NAME)

clean:
	@$(RM) /includes/exsys.h.gch

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re