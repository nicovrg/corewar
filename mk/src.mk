# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2019/10/18 19:29:59 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH := src/

SRC_ASM =			main.c

SRC_ASM := $(addprefix general/, $(SRC_GENERAL))

SRC_VM = 			main.c

SRC_VM := $(addprefix algo/, $(SRC_ALGO))

SRC := $(addprefix $(SRC_PATH), $(SRC_ASM))
SRC += $(addprefix $(SRC_PATH), $(SRC_VM))
