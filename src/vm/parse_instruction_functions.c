/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:01:07 by amamy             #+#    #+#             */
/*   Updated: 2020/02/11 01:02:55 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"
#include "libft.h"
#include "ft_printf.h"

int		inst_state_error(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}

int		inst_state_parsing_opcode(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}

int		inst_state_loading_opcode(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}

int		inst_state_parsing_encoded_byte(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}

int		inst_state_matching_encoded_byte(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}

int		inst_state_checking_parameters(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}

int		inst_state_executing_instrcution(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}

int		inst_state_finished(t_instruction **instruction)
{
	(void)instruction;
	return (1);
}
