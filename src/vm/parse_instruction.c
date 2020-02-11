/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:22:16 by amamy             #+#    #+#             */
/*   Updated: 2020/02/11 01:05:48 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"
#include "libft.h"
#include "ft_printf.h"

int (*g_parse_instruction_state_func_array[INST_STATE_NUMBER])(t_instruction **) = {
	[INST_STATE_ERROR] = inst_state_error,
	[INST_STATE_PARSING_OPCODE] = inst_state_parsing_opcode,
	[INST_STATE_LOADING_OPCODE] = inst_state_loading_opcode,
	[INST_STATE_PARSING_ENCODED_BYTE] = inst_state_parsing_encoded_byte,
	[INST_STATE_MATCHING_ENCODED_BYTE] = inst_state_matching_encoded_byte,
	[INST_STATE_CHECKING_PARAMETERS] = inst_state_checking_parameters,
	[INST_STATE_EXECUTING_INSTRCUTION] = inst_state_executing_instrcution,
	[INST_STATE_FINISHED] = inst_state_finished,
};
