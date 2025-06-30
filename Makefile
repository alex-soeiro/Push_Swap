# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 13:49:06 by avieira-	       #+#    #+#              #
#    Updated: 2025/06/30 01:21:03 by a-soeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = srcs/push_swap.c srcs/parse.c srcs/error_message.c srcs/createstack_a.c srcs/rotate.c srcs/calc_cost.c srcs/organize_b.c srcs/transfer_b.c srcs/sort.c
SRCS += srcs/reverse_rotate.c srcs/swap.c srcs/push.c
OBJS += $(SRCS:.c=.o)

all: $(NAME)

compile: libft $(NAME) $(OBJS)
	cc $(CFLAGS) $(SRCS) include/libft/libft.a -g -o $(NAME)
	rm -rf include/libft/srcs/*.o

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	rm -rf $(OBJS)

fclean: clean fclean_libft
	rm -f $(NAME)

libft:
	make -C include/libft/

clean_libft:
	make clean -C include/libft/

fclean_libft: delete_visualizer
	make fclean -C include/libft/

re: fclean all

recompile: fclean compile clean

visualize:
	push_swap_visualizer/build/bin/visualizer

delete_visualizer:
	rm -rf push_swap_visualizer

install_visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git && \
		cd push_swap_visualizer && \
		mkdir build && \
		cd build && \
		cmake .. && \
		make && \
		./bin/visualizer
