# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2020/02/06 01:29:29 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH		:=	src/
SRC_ASM_PATH	:=	asm/
SRC_VM_PATH		:=	vm/

SRC_ASM =			main.c\
					lexer.c\
					helper_lib.c\
					helper_free.c\
					helper_debug.c\
					helper_error.c\
					get_header_info_one.c\
					get_header_info_two.c\
					determine_token_type_and_length.c\
					token_type_determination_function_one.c\
					token_type_determination_function_two.c\
					get_tokens_from_current_line.c\

SRC_VM =			vm_main.c\
					vm_error.c\
					vm_checks.c\
					vm_add_champions.c


SRC_ASM := $(addprefix $(SRC_ASM_PATH), $(SRC_ASM))
SRC_ASM := $(addprefix $(SRC_PATH), $(SRC_ASM))

SRC_VM := $(addprefix $(SRC_VM_PATH), $(SRC_VM))
SRC_VM := $(addprefix $(SRC_PATH), $(SRC_VM))