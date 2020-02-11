# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2020/02/11 01:04:26 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH		:=	src/
SRC_ASM_PATH	:=	asm/
SRC_VM_PATH		:=	vm/

SRC_ASM =			asm_main.c\

SRC_VM =			main.c\
					init.c\
					error.c\
					champions_list.c\
					parsing_checks.c\
					vm_free.c\
					helper_lib.c\
					nb_players.c\
					instruction_1.c\
					instruction_2.c\
					instruction_3.c\
					instruction_4.c\
					header_check.c\
					vm_execution.c\
					add_champions.c\
					parse_instruction.c\
					process_parse_arguments.c\
					parse_instruction_functions.c\
					parsing_check_instructions_size.c


SRC_ASM := $(addprefix $(SRC_ASM_PATH), $(SRC_ASM))
SRC_ASM := $(addprefix $(SRC_PATH), $(SRC_ASM))

SRC_VM := $(addprefix $(SRC_VM_PATH), $(SRC_VM))
SRC_VM := $(addprefix $(SRC_PATH), $(SRC_VM))