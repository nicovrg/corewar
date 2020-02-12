# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    include.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:55:10 by nivergne          #+#    #+#              #
#    Updated: 2020/02/12 20:04:20 by nicolasv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = include/
INC_PATH = -Iinclude/ -Ilibft/include


INC_FILES =			op.h\
					vm.h\
					asm.h\
					tokens.h\

INC_FILES := $(addprefix $(INC), $(INC_FILES))
