/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:46:55 by ybelilov          #+#    #+#             */
/*   Updated: 2017/07/10 14:46:56 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		parameter_validation(t_char *main, t_command *command, char *com)
{
	char	**arg;
	int		i;
	int		res;

	i = -1;
	arg = ft_array_trim(ft_strsplit(com, ','));
	if (!arg || OP[command->opcode - 1].arguments != array_len(arg))
		return (0);
	while (arg[++i])
	{
		res = is_t_dir(arg[i]) + is_t_ind(arg[i]) + is_t_reg(arg[i]);
		if ((OP[command->opcode - 1].r_d_i[i] == 7 && res != 0 )
			|| OP[command->opcode - 1].r_d_i[i] == res
			|| OP[command->opcode - 1].r_d_i[i] - res == T_DIR
			|| OP[command->opcode - 1].r_d_i[i] - res == T_IND
			|| OP[command->opcode - 1].r_d_i[i] - res == T_REG)
			;
		else
			return (0);
	}
	return (1);
}

char		**ft_array_trim(char **array)
{
	char	**res;
	int		i;

	i = -1;
	res = (char**)malloc(sizeof(char**) * array_len(array) + 1);
	while (array[++i])
		res[i] = ft_strtrim(array[i]);
	res[i] = NULL;
	ft_freearray(array);
	return(res);
}

long int	array_len(char **arr)
{
	long int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}