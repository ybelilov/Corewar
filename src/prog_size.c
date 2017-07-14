/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:47:17 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/12 12:47:18 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		prog_size(t_char *lst)
{
	t_label *l;
	long long int res;
	t_command	*c;

	res = 0;
	l = lst->label;
	while(l && res < 100000)
	{
		c = l->command;
		while(c && res < 100000)
		{
			res = res + weight_command(c, lst);
			c = c->next;
		}
		l = l->next;
	}
	if((res / 2) < 682)
	{
		lst->size = res;
		return 1;
	}
	return 0;
}