# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 13:49:06 by avieira-	       #+#    #+#              #
#    Updated: 2025/07/02 15:26:15 by avieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = srcs/push_swap.c srcs/parse.c srcs/error_message.c srcs/createstack_a.c
SRCS += srcs/rotate.c srcs/calc_cost.c srcs/organize.c srcs/organize_utils.c
SRCS += srcs/get_btarget.c srcs/sort.c srcs/transfer.c
SRCS += srcs/reverse_rotate.c srcs/swap.c srcs/push.c
OBJS += $(SRCS:.c=.o)

all: $(NAME)

compile: fclean fclean_libft libft $(NAME) $(OBJS)
	cc $(CFLAGS) $(SRCS) include/libft/libft.a -g -o $(NAME)
	rm -rf $(OBJS)
	make fclean -C include/libft/

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

visualize:
	./push_swap_visualizer/build/bin/visualizer

delete_visualizer:
	rm -rf push_swap_visualizer

install_visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git && \
		cd push_swap_visualizer && \
		mkdir build && \
		cd build && \
		cmake .. && \
		make
