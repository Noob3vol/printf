
#Name
NAME = libftprintf.a

LIB = libft.a

SRC = ft_printf.c\
	ftpf_get_format.c\
	ftpf_process_type.c\
	ftpf_ruler.c\
	ftpf_putf.c\
	ftpf_nbr.c\
	ftpf_prefix.c

# Dir

D_LIB = lib
D_LIBINC = include
D_SRC = src
D_HDR = include

# Auto-variable
LIBHDR = $(addsuffix .h, $(basename $(LIBNAME)))
OBJ = $(addsuffix .o, $(basename $(SRC)))
SRCS = $(addprefix $(D_SRC)/, $(SRC))
INC = $(D_HDR)
L_INC = $(D_LIB)/$(D_HDR)

# Compiler

CC = clang
D_FLAG = -g3 -fsanitize=address
W_FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	ar rc $(NAME) $(OBJ) $(D_LIB)/$(LIB)
	ranlib $(NAME)

$(OBJ) : $(SRCS)
	$(CC) -I$(INC) -I$(L_INC) -c $(SRCS) 

$(LIB) :
	make -C $(D_LIB)

clean :
	rm -f ${OBJ}
	make clean -C ${D_LIB}

fclean : clean
	rm -f ${NAME}
	make fclean -C ${D_LIB}

re : fclean all

.PHONY: all clean fclean re 
