/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:06:51 by ybelilov          #+#    #+#             */
/*   Updated: 2017/07/07 15:06:52 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_t_dir(char *arg, int *param_type, char **param, int size)
{
	if (arg[1] == LABEL_CHAR && arg[0] == DIRECT_CHAR)
	{
		*param_type = T_DIR * 10;
		*param = ft_strdup(&arg[2]);
	}
	else if (arg[0] == DIRECT_CHAR && arg[1] != '+' && ft_isanbr(&arg[1]))
	{
		*param_type = T_DIR;
		*param = ten_hex(most_long_long(&arg[1]), NULL, size * 2);
	}
	else
		return(0);
	return(T_DIR);
}


int		is_t_ind(char *arg, int *param_type, char **param)
{
	if (arg[0] == LABEL_CHAR)
	{
		*param_type = T_IND * 10;
		*param = ft_strdup(&arg[1]);
	}
	else if (arg[0] != '+' && ft_isanbr(arg))
	{
		*param_type = T_IND;
		*param = ten_hex(most_long_long(arg), NULL, IND_SIZE * 2);
	}
	else 
		return (0);
	return (T_IND);
}

int		is_t_reg(char *arg, int *param_type, char **param)
{
	if (!arg || arg[0] != 'r' || !ft_isanbr(&arg[1]) || arg[0] == '0'
		|| ft_atoi(&arg[1]) > REG_NUMBER || ft_atoi(&arg[1]) < 1)
		return (0);
	*param_type = T_REG;
	*param = ten_hex(ft_atoi(&arg[1]), NULL, 2);
	return (T_REG);
}

