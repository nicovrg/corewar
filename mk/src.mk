# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2020/02/25 15:43:33 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH		:=	src/
SRC_ASM_PATH	:=	asm/
SRC_VM_PATH		:=	vm/

SRC_ASM =			main.c\
					lexer.c\
					parser.c\
					translator.C\
					error_mode.c\
					helper_lib.c\
					helper_free.c\
					helper_debug.c\
					write_header.c\
					helper_error.c\
					label_functions.c\
					create_output_file.c\
					get_header_info_one.c\
					get_header_info_two.c\
					helper_free_token_values.c\
					determine_token_type_and_length.c\
					token_type_determination_function_one.c\
					token_type_determination_function_two.c\
					token_type_determination_function_three.c\
					get_tokens_from_current_line.c\

SRC_VM =			vm_main.c\
					vm_error.c\
					vm_checks.c\
					vm_add_champions.c


SRC_ASM := $(addprefix $(SRC_ASM_PATH), $(SRC_ASM))
SRC_ASM := $(addprefix $(SRC_PATH), $(SRC_ASM))

SRC_VM := $(addprefix $(SRC_VM_PATH), $(SRC_VM))
SRC_VM := $(addprefix $(SRC_PATH), $(SRC_VM))