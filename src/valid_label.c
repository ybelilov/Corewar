/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:31:25 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/10 18:31:25 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		find_label_in_label(char *str, t_label *lbl)
{
	t_label		*l;

	l = lbl->next;
	while(l)
	{
		if(!ft_strcmp(str, l->name))
			return 1;
		l = l->next;
	}
	return 0;
}

int		valid_label(t_label *l)
{
	t_command	*c;
	t_label		*tmp;

	tmp = l;
	while(tmp)
	{
		c = tmp->command;
		while(c)
		{
			if(c->b1 == 20 || c->b1 == 40)
				if (!find_label_in_label(c->a1, l))
					return 0;
			if(c->b2 == 20 || c->b2 == 40)
				if (!find_label_in_label(c->a2, l))
					return 0;
			if(c->b3 == 20 || c->b3 == 40)
				if (!find_label_in_label(c->a3, l))
					return 0;
			c = c->next;
		}
		tmp = tmp->next;
	}
	return 1;
}
