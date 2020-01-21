# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    obj.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:56:38 by nivergne          #+#    #+#              #
#    Updated: 2020/01/21 02:55:46 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH		:=	obj/
OBJ_ASM_PATH	:=	asm/
OBJ_VM_PATH		:=	vm/

#Problem just below
OBJ_ASM	:= $(addprefix $(OBJ_ASM_PATH), $(addsuffix .o, $(basename $(notdir $(SRC_ASM)))))
OBJ_VM	:= $(addprefix $(OBJ_VM_PATH), $(addsuffix .o, $(basename $(notdir $(SRC_VM)))))

OBJ_ASM	:= $(addprefix $(OBJ_PATH), $(OBJ_ASM))
OBJ_VM	:= $(addprefix $(OBJ_PATH), $(OBJ_VM))