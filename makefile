

#output
NAME= test

#file
SRC=ft_printf.c \
    ft_utils.c \
    ft_c_processor.c \
    ft_tokens_processor.c

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

all : $(NAME)

$(NAME) : $(OBJ) $(D_HDR)/$(HDR)
	$(CC) -o $(NAME) -I$(D_HDR) $(OBJ) -I$(D_LIB)/include $(LIB)

$(OBJ) : $(T_SRC)
	$(CC) -I$(D_HDR) -c $(T_SRC) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean re

.PHONY: all clean fclean re
