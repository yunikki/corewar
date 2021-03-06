/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:59:41 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:02:55 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_op		g_op_tab[17] = {
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

t_op	*op_from_instr(char *instr)
{
	uint	op_line;
	t_op	*ops;

	ops = g_op_tab;
	op_line = 0;
	while (ops[op_line].instr != NULL)
	{
		if (ft_strcmp(ops[op_line].instr, instr) == 0)
			return (ops + op_line);
		op_line++;
	}
	return (NULL);
}

t_bool	line_begins_by_an_opcode(char *line)
{
	static t_op		*instrs;
	static t_bool	init = FALSE;
	uint			i;
	uint			len;

	if (init == FALSE && TRUE + 0 * (init = TRUE))
		instrs = g_op_tab;
	i = 0;
	while (instrs[i].instr != NULL)
	{
		len = ft_strlen(instrs[i].instr);
		if (ft_strncmp(line, instrs[i].instr, len) == 0 && line[len] == ' ')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
