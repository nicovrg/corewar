# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    colors.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 21:59:53 by nicolasv          #+#    #+#              #
#    Updated: 2019/09/21 02:13:58 by nicolasv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#special capacities
UP_LINE					=					\x1b[A
ERASE_LINE				=				 	\x1b[2K
END						=					\x1b[0m
BOLD					=					\x1b[1m
UNDER					=					\x1b[4m
REV						=					\x1b[7m

#colors
RED						=					\x1b[31m
GREEN					=					\x1b[32m
BLUE					=					\x1b[34m
YELLOW					=					\x1b[33m
CYAN					=					\x1b[36m
GREY					=					\x1b[40m
WHITE					=					\x1b[37m
PINK					=					\x1b[38;2;152;0;255m
PURPLE					=					\x1b[38;2;114;0;255m
DARK_PURPLE				=					\x1b[38;2;65;0;255m
DARK_PINK				=					\x1b[38;2;86;0;255m

#background colors
BACK_RED				=					\x1b[41m
BACK_GREEN				=					\x1b[42m
BACK_BLUE				=					\x1b[44m
BACK_YELLOW				=					\x1b[43m
BACK_CYAN				=					\x1b[46m
BACK_PURPLE				=					\x1b[45m
BACK_GREY				=					\x1b[40m
BACK_WHITE				=					\x1b[47m
