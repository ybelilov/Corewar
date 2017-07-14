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

	if(!com)
		return 0;
	i = -1;
	arg = ft_array_trim(ft_strsplit(com, ','));
	if (!arg || OP[command->opcode - 1].arguments != array_len(arg))
		return (0);
	check_for_comment_at_the_end(&arg[array_len(arg) - 1]);
	while (arg[++i])
	{
		res = is_t_dir(arg[i], &command->param_type[i], &command->param[i], OP[command->opcode - 1].label_size)
				+ is_t_ind(arg[i], &command->param_type[i], &command->param[i])
				+ is_t_reg(arg[i], &command->param_type[i], &command->param[i]);
		if ((OP[command->opcode - 1].r_d_i[i] == 7 && res != 0 )
			|| OP[command->opcode - 1].r_d_i[i] == res
			|| OP[command->opcode - 1].r_d_i[i] - res == T_DIR
			|| OP[command->opcode - 1].r_d_i[i] - res == T_IND
			|| OP[command->opcode - 1].r_d_i[i] - res == T_REG)
			;
		else
			return (0);
	}
	command->num_param = OP[command->opcode - 1].arguments;
	return (1);
}

void			check_for_comment_at_the_end(char **str)
{
	char **array;

	array = ft_strsplit(*str, '#');
	if (array_len(array) > 1)
	{
		ft_memdel((void**)str);
		*str = ft_strtrim(array[0]);
	}
	ft_freearray(array);
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