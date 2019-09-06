NAME = exsys

SRC_PATH = 	srcs/
SRC_NAME =	main.c           process_file.c \
			read_file.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

INC_PATH = 	includes/

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -std=c99
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