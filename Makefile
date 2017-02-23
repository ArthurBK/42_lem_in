NAME 	=	lem-in
CC		=	clang
CFLAGS 	=	-Wall -Werror -Wextra
INC		=	-I includes/ -I libft/
SRCS 	=	helpers.c \
			lem_in.c \
			main.c \
			parsing.c \
			path_helpers.c \
			paths.c \
			struct_helpers.c
OBJ		=	$(SRCS:.c=.o)
HDRS	=	lem_in.h
SDIR	=	$(addprefix srcs/, $(SRCS))
ODIR	=	$(addprefix objs/, $(OBJ))
HDIR	=	$(addprefix includes/, $(HDRS))
LIBPATH =	-C ./libft

all: $(NAME)

$(NAME): $(ODIR)
	@make $(LIBPATH)
	@$(CC) $(CFLAGS) $(ODIR) -L./libft -lft -o $(NAME) $(INC)
	@echo "\033[32;1m$(NAME) created successfully!\033[0m"

objs/%.o: srcs/%.c $(HDIR)
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -rf objs

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31;1m$(NAME) removes!\033[0m"

relib:
	@make clean $(LIBPATH)
	@rm -f libft/libft.a
	@make $(LIBPATH)

re: fclean all

.PHONY: re all clean fclean
