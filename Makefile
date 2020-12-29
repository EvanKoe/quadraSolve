#
# Quadratic Solver Makefile
#

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	"solve"

GCC_FLAGS	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(GCC_FLAGS)

clean:
	rm $(NAME) $(OBJ)

re:	clean all