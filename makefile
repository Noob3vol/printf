
#output
NAME= printflibft.a

#file
SRC=ft_printf.c \
    ft_utils.c \
    ft_c_processor.c \
    ft_tokens_processor.c \
	ft_ruler.c \
	ft_printnbr.c \
	ft_pformat.c \
	ft_pformat_nbr.c \
	ft_pformat_double.c \
    ft_output.c

MAIN= main_test.c
D_MAIN= ../../test_printf/

HDR= ft_printf.h
LIB= libft.a
OBJ= $(addsuffix .o, $(basename $(SRC)))

#dir
D_SRC=src
D_HDR=include
D_LIB=lib

#target
T_SRC= $(addprefix $(D_SRC)/, $(SRC))
T_HDR=

#compilation
CC=clang
DFLAG= -g3 -fsanitize=address
WFLAG= -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(D_HDR)/$(HDR) $(LIB)
#	$(CC) $(WFLAG) $(DFLAG) -o $(NAME) -I$(D_HDR) $(OBJ)  -I$(D_LIB)/include $(D_LIB)/$(LIB) $(D_MAIN)/$(MAIN)
	ar rc $(NAME)  $(OBJ) $(D_LIB)/libft.a
	ranlib $(NAME)

$(OBJ) : $(T_SRC)
	$(CC) -I$(D_HDR) -c $(T_SRC)  -I$(D_LIB)/include 

$(LIB):
	make -C lib/

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re : fclean all 

.PHONY: all clean fclean re
