# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2019/11/12 01:25:24 by nicolasv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH		:=	src/
SRC_ASM_PATH	:=	asm/
SRC_VM_PATH		:=	vm/

SRC_ASM =			main.c\
					error.c

SRC_VM =			lala.c\
					#vm_checks.c\
					#vm_main.c\
					# vm_error.c\
					# add_champions.c


SRC_ASM := $(addprefix $(SRC_ASM_PATH), $(SRC_ASM))
SRC_ASM := $(addprefix $(SRC_PATH), $(SRC_ASM))

SRC_VM := $(addprefix $(SRC_VM_PATH), $(SRC_VM))
SRC_VM := $(addprefix $(SRC_PATH), $(SRC_VM))