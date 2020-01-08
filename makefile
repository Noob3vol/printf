
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

#compilation
CC=clang
DFLAG= -g3 -fsanitize=address
WFLAG= -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(D_HDR)/$(HDR)
	$(CC) $(WFLAG) -o $(NAME) -I$(D_HDR) $(OBJ) -I$(D_LIB)/include $(D_LIB)/$(LIB)

$(OBJ) : $(T_SRC)
	$(CC) -I$(D_HDR) -c $(T_SRC) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY: all clean fclean re
