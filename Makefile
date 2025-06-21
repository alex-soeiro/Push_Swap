# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 13:49:06 by avieira-	       #+#    #+#              #
#    Updated: 2025/06/21 18:34:01 by avieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

compile: libft
	cc push_swap.c error_message.c createstack_a.c rotate.c swap.c include/libft/libft.a -g

libft:
	make -C include/libft/

clean_libft:
	make clean -C include/libft/
fclean_libft:
	make fclean -C include/libft/


