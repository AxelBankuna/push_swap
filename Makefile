# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abukasa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:49:10 by abukasa           #+#    #+#              #
#    Updated: 2018/11/13 15:28:36 by abukasa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
ALLFILL =push_swap 

SRC = ps.c src/ps_load.c src/sorted.c src/ps_instructions.c \
	  src/ps_instructions2.c src/ps_instructions3.c src/ps_instructions4.c \
	  src/ps_sort.c src/ps_size.c src/ps_sort_ext.c src/ps_sort_ext2.c \
	  src/ps_sorting.c src/ps_cleaning.c src/ps_rev_ext.c src/free.c \
	  src/ps_checkmax.c src/ps_insert.c

OBJ = ps.o src/print.o src/ps_load.o src/sorted.o src/ps_instructions.o \
	  src/ps_instructions2.o src/ps_instructions3.o src/ps_instructions4.o \
	  src/ps_sort.o src/ps_size.o src/ps_sort_ext.o src/ps_sort_ext2.o \
	  src/ps_sorting.o src/ps_cleaning.o src/ps_rev_ext.o src/free.o \
	  src/ps_checkmax.o src/ps_insert.o

push_swap : $(OBJECTS)
all: $(ALLFILL)
$(ALLFILL):
	@$(MAKE) -C libft
	@$(MAKE) -C checker
	@gcc -Wall -Werror -Wextra $(SRC) -o $@ $(OBJECTS) libft/libft.a

norm:
	norminette -R CheckForbiddenSourceHeader src/*.c
	norminette -R CheckForbiddenSourceHeader src/*.h
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	@rm -rf $(OBJ)
	@$(MAKE) -C checker clean
	@$(MAKE) -C libft clean

fclean : clean
	@rm -rf $(NAME) push_swap
	@$(MAKE) -C libft fclean
	@$(MAKE) -C checker fclean
re: fclean all
	@$(MAKE) -C checker fclean all
	@$(MAKE) -C libft fclean all
