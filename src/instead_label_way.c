/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instead_label_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:59:38 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/12 14:59:39 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int   weight_command(t_command *c, t_char *lst)
{
	int     i;
	int     res;

	res = 0;
	i = 0;
	while(i < c->num_param)
	{
		if(c->param_type[i] == 1)
			res = res + 2;
		if(c->param_type[i] == 2 || c->param_type[i] == 20)
			res = res + 4;
		if(c->param_type[i] == 4 || c->param_type[i] == 40)
			res = res + (lst->op[c->opcode - 1].label_size) * 2;
		i++;
	}
	return res;
}

int  cal2(t_label *now, t_command *c, t_char *lst)
{
	t_command   *k;
	int         res;

	res = 0;
	k = now->command;
	while(k && k != c)
	{
		if(k == c)
			return res;
		res = res + weight_command(k, lst);
		k = k->next;
	}
	return res;
}

int  cal1(t_label *start, t_command *c, t_char *lst)
{
	t_label     *s;
	t_command   *k;
	int         res;

	res = 0;
	s = start;
	while(s)
	{
	   k = s->command;
		while(k && k != c)
		{
			if(k == c)
				return res;
			res = res + weight_command(k, lst);
			k = k->next;
		}
		s = s->next;
	}
	return res;
}

int  cal3(t_label *start, t_command *c, t_char *lst, char *str)
{
	t_label     *s;
	t_command   *k;
	int         res;

	res = 0;
	s = start;
	k = s->command;
	while(k && k != c)
		k = k->next;
	while(s)
	{
		while(k)
		{
			res = res + weight_command(k, lst);
			k = k->next;
		}
		if(!ft_strcmp(s->name, str))
			return res;
		s = s->next;
		if(s)
			k = s->command;
	}
	return res;
}

int   calculation(char *str, t_char *lst, t_command *c, t_label *now)
{
	int     i;
	t_label *s;
	
	s = lst->label;
	i = -2;
	while(s)
	{
		if(s->name && !ft_strcmp(s->name, str))
		{
			i++;
			break ;
		}
		if(s == now)
			i = 0;
		s = s->next;
	}
	//max зависит от label size ffff || ffff ffff
	if(i == -1)
		printf("cal1 = %d", cal1(lst->label, c, lst));//return (max- cal1 + 1)
	if(i == 0)
		printf("cal2 = %d", cal2(now, c, lst));//return (cal2 != 0 ? max - cal2 + 1 : 0)
	if(i == 1)
		printf("cal3 = %d", cal3(s, c, lst, str));//return (cal3)
	return (1);
}

int    instead_label_way(t_label *l, t_char *lst)
{
	t_label     *tmp;
	t_command   *c;
	int         i;

	tmp = l;
	while(tmp)
	{
		c = tmp->command;
		while(c)
		{
			i = 0;
			while(i < c->num_param)
			{
				if(c->param_type[i] == 20 || c->param_type[i] == 40)
				{
					calculation(c->param[i], lst, c, tmp);
				}
				i++;
			}
			c = c->next;
		}
	}
	return (0);
}