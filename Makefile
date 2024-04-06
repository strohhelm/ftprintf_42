

NAME := libftprintf.a
CC := cc
CFLAGS ?= -Wall -Wextra -Werror

CFILES := 	src/ft_print_adress_in_hex.c \
			src/ft_print_base.c \
			src/ft_printf.c \
			src/ft_printint.c \
			src/ft_printstring.c \
			src/ft_write.c

OBJFILES := $(patsubst src/%.c, obj/%.o,$(CFILES))

$(NAME): $(OBJFILES)
	ar -rcs $@ $^


obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $^ -o $@ 

all: $(NAME)
	
t:
	$(CC) $(CFLAGS) $(CFILES) -g 

clean:
	rm -rf obj

fclean:
	rm -rf $(NAME) obj


re: fclean all

.PHONY: all clean fclean re t 
