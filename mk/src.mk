# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2020/03/07 00:19:11 by amamy            ###   ########.fr        #
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
					parse_instruction.c\
					parse_parameters.c\
					get_header_info_one.c\
					get_header_info_two.c\
					helper_free_token_values.c\
					write_instruction_section.c\
					parse_label_declarations.c\
					check_instruction_validity.c\
					check_for_additional_errors.c\
					determine_token_type_and_length.c\
					token_type_determination_function_one.c\
					token_type_determination_function_two.c\
					token_type_determination_function_three.c\
					get_tokens_from_current_line.c\

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