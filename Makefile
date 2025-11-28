NAME = libasm

RM = @rm -rf

CC := @cc
AR := @ar
CFLAGS := -Wall -Wextra -Werror -g3


OBJFILES = $(SRCFILES:.c=.o)

SRCFILES = src/main.c \
		src/ft_strlen.s \
		src/ft_strcpy.s \
		src/ft_strcmp.s \
		src/ft_write.s \
		src/ft_read.s \
		src/ft_strdup.s

all : $(NAME)


$(NAME) : $(OBJFILES)

clean :
	$(RM) $(OBJFILES)
	@echo clean done ! ✅

fclean : clean
	$(RM) $(NAME)

re : fclean all