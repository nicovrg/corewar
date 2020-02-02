# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2020/02/02 05:16:40 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH		:=	src/
SRC_ASM_PATH	:=	asm/
SRC_VM_PATH		:=	vm/

SRC_ASM =			asm_main.c\
					asm_header_one.c\
					asm_header_two.c\
					asm_lexer.c\
					asm_tokeniser.c\
					asm_determine_token_type.c\
					asm_tokeniser_states-function_one.c\
					asm_tokeniser_states-function_two.c\
					asm_lib.c\
					asm_debug.c\
					asm_error.c

SRC_VM =			vm_main.c\
					vm_checks.c\
					vm_error.c\
					vm_add_champions.c


SRC_ASM := $(addprefix $(SRC_ASM_PATH), $(SRC_ASM))
SRC_ASM := $(addprefix $(SRC_PATH), $(SRC_ASM))

SRC_VM := $(addprefix $(SRC_VM_PATH), $(SRC_VM))
SRC_VM := $(addprefix $(SRC_PATH), $(SRC_VM))