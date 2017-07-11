ASM = asm

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

HASM = ./asm.h

FILE = 	./src/asm_main.o \
		./src/correct_char_name.o \
		./src/ten_hex.o \
		./src/label_this.o \
		./src/have_something_after_space.o \
		./src/correct_name_command.o \
		./src/op.o\
		./src/valid_label.o \
		./src/byte_go.o \
		./src/read_while_empty.o\
		./src/parameter_validation.o\
		./src/arguments_check.o

OBJ = $(FILE:.o=.c)

all: liba comp

liba:
	@make -C $(LIBFT)

comp:
	@$(CC) $(FLAGS) $(OBJ) ./libft/libft.a -o $(ASM)

clean:
	@make clean -C $(LIBFT)

fclean:
	@-/bin/rm -f $(LEM)
	@make fclean -C $(LIBFT)

re: fclean all