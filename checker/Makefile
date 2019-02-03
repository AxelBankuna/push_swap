#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abukasa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:49:10 by abukasa           #+#    #+#              #
#    Updated: 2018/11/13 15:28:52 by abukasa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
ALLFILL =checker 

SRC = ../src/ps_load.c ../src/sorted.c ../src/ps_instructions.c \
	  ps.c ../src/ps_instructions2.c ../src/ps_instructions3.c \
	  ../src/ps_instructions4.c ../src/ps_sort.c ../src/ps_size.c \
	  ../src/ps_sort_ext.c ../src/ps_sort_ext2.c ../src/ps_sorting.c checker.c \
	  ../src/ps_cleaning.c ../src/ps_rev_ext.c ../src/ps_checkmax.c \
	  ../src/ps_insert.c

OBJ = ../src/print.o ../src/ps_load.o ../src/sorted.o ../src/ps_instructions.o \
	  ps.o ../src/ps_instructions2.o ../src/ps_instructions3.o \
	  ../src/ps_instructions4.o ../src/ps_sort.o ../src/ps_size.o \
	  ../src/ps_sort_ext.o ../src/ps_sort_ext2.o ../src/ps_sorting.o checker.o \
	  ../src/ps_cleaning.o ../src/ps_rev_ext.o ../src/ps_checkmax.o \
	  ../src/ps_insert.o

checker : $(OBJECTS)
all: $(ALLFILL)
$(ALLFILL):
	@gcc -Wall -Werror -Wextra $(SRC) -o $@ $(OBJECTS) ../libft/libft.a

norm:
	norminette -R CheckForbiddenSourceHeader ../src/*.c
	norminette -R CheckForbiddenSourceHeader ../src/*.h
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME) checker
re: fclean all
