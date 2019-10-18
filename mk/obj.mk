# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    obj.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:56:38 by nivergne          #+#    #+#              #
#    Updated: 2019/09/22 23:57:07 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH := obj/

OBJ_GENERAL	:= $(addprefix general/, $(addsuffix .o, $(basename $(notdir $(SRC_GENERAL)))))
OBJ_PARSE	:= $(addprefix parse/, $(addsuffix .o, $(basename $(notdir $(SRC_PARSE)))))
OBJ_ALGO	:= $(addprefix algo/, $(addsuffix .o, $(basename $(notdir $(SRC_ALGO)))))

OBJ			:= $(addprefix $(OBJ_PATH), $(OBJ_GENERAL))
OBJ			+= $(addprefix $(OBJ_PATH), $(OBJ_PARSE))
OBJ			+= $(addprefix $(OBJ_PATH), $(OBJ_ALGO))