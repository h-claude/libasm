NAME = libasm.a

OBJDIR = obj

RM = @rm -rf

CC := @cc
NASM := @nasm
NFLAGS := -f elf64 -g -F dwarf
AR := @ar
CFLAGS := -Wall -Wextra -Werror -g3

OBJFILES = $(patsubst src/%.s,$(OBJDIR)/%.o,$(SRCFILES))

SRCFILES = src/ft_strlen.s \
	src/ft_strcpy.s \
	src/ft_strcmp.s \
	src/ft_write.s \
	src/ft_read.s \
	src/ft_strdup.s \

all : $(NAME)

$(OBJDIR)/%.o : src/%.s | $(OBJDIR)
	$(NASM) $(NFLAGS) $< -o $@

$(OBJDIR) :
	mkdir -p $(OBJDIR)

$(NAME) : $(OBJFILES)
	$(AR) rcs $(NAME) $(OBJFILES)

clean :
	$(RM) $(OBJFILES) $(OBJFILES_C)
	$(RM) $(OBJDIR)
	@echo clean done ! ✅

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re