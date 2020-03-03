/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:22:16 by amamy             #+#    #+#             */
/*   Updated: 2020/02/11 00:45:47 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"
#include "libft.h"
#include "ft_printf.h"

int (*g_instructions_func_array[INST_NB])(t_instruction **, t_corewar *) = {
	[INST_ERROR] = inst_error,
	[INST_LIVE] = inst_live,
	[INST_LD] = inst_ld,
	[INST_ST] = inst_st,
	[INST_ADD] = inst_add,
	[INST_SUB] = inst_sub,
	[INST_AND] = inst_and,
	[INST_OR] = inst_or,
	[INST_XOR] = inst_xor,
	[INST_ZJMP] = inst_zjmp,
	[INST_LDI] = inst_ldi,
	[INST_STI] = inst_sti,
	[INST_FORK] = inst_fork,
	[INST_LLD] = inst_lld,
	[INST_LLDI] = inst_lldi,
	[INST_LFORK] = inst_lfork,
	[INST_AFF] = inst_aff,
};
