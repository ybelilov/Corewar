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

int		is_t_dir(char *arg)
{
	if (!arg || arg[0] != DIRECT_CHAR || !ft_isanbr(&arg[1]) ||
		ft_atoi_unsigned(&arg[1]) > 4294967295 ||
			!ft_atoi_unsigned(&arg[1]))
		return(0);
	return(T_DIR);
}


int		is_t_ind(char *arg)
{
	if (!arg || arg[0] != DIRECT_CHAR || arg[1] != LABEL_CHAR)
		return (0);
	return (T_IND);
}

int		is_t_reg(char *arg)
{
	if (!arg || arg[0] != 'r' || !ft_isanbr(&arg[1]) || arg[0] == '0'
		|| ft_atoi(&arg[1]) > REG_NUMBER || ft_atoi(&arg[1]) < 1)
		return (0);
	return (T_REG);
}
