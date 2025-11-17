.SILENT:

# Ouput name
NAME = libft.a
OBJ_DIR = Objects

#SOURCES

STR = \
		ft_strlen.c \
		ft_itoa_base.c \
		ft_printf.c

MEM = \
		ft_bzero.c \
		ft_calloc.c

FD = \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c

SRCS = \
		$(CHAR) \
		$(MEM) \
		$(STR) \
		$(FD)

#compilator
CC = cc
CFLAGS = -Wall -Wextra -Werror

#object name
OBJECTS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJECTS = $(LST:%.c=$(OBJ_DIR)/%.o)
#Rules

all : $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#bonus rules
bonus: $(BONUS_OBJECTS)
	ar -rcs $(NAME) $(BONUS_OBJECTS)