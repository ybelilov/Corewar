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

<<<<<<< HEAD
=======
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

>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
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

<<<<<<< HEAD
int  cal1(t_label *start, t_command *c, t_char *lst, char *str)
=======
int  cal1(t_label *start, t_command *c, t_char *lst)
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
{
	t_label     *s;
	t_command   *k;
	int         res;

	res = 0;
	s = start;
	while(s)
	{
<<<<<<< HEAD
		if(s->name && !ft_strcmp(s->name, str))
			break ;
		s = s->next;
	}
	while(s)
	{
	   k = s->command;
		while(k)
=======
	   k = s->command;
		while(k && k != c)
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
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

<<<<<<< HEAD
int  cal3(t_label *now, t_command *c, t_char *lst, char *str)
=======
int  cal3(t_label *start, t_command *c, t_char *lst, char *str)
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
{
	t_label     *s;
	t_command   *k;
	int         res;

	res = 0;
<<<<<<< HEAD
	s = now;
	k = c;
	while(k && k != c)
		k = k->next;
	// k = k->next;
	while(s)
	{
		if(!ft_strcmp(s->name, str))
			return res;
=======
	s = start;
	k = s->command;
	while(k && k != c)
		k = k->next;
	while(s)
	{
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
		while(k)
		{
			res = res + weight_command(k, lst);
			k = k->next;
		}
<<<<<<< HEAD
		// printf("bee_gen|%s|   |%s|\n", s->name, str);
=======
		if(!ft_strcmp(s->name, str))
			return res;
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
		s = s->next;
		if(s)
			k = s->command;
	}
	return res;
}

<<<<<<< HEAD
int		function_ret_one(char *str, t_char *lst, t_label *now)
{
	int		i;
	t_label *s;

=======
int   calculation(char *str, t_char *lst, t_command *c, t_label *now)
{
	int     i;
	t_label *s;
	
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
	s = lst->label;
	i = -2;
	while(s)
	{
<<<<<<< HEAD
		if(s == now)// && !ft_strcmp(s->name, str))
		{
			if(s->name && !ft_strcmp(s->name, str))
				return 0;
			if(i == -2)
				i = 0;
			if(i == -1)
				return -1;
			
		}
		if(s->name && !ft_strcmp(s->name, str) && i < 2)
			i++;
		s = s->next;
	}
	return i;
}

char   *calculation(char *str, t_char *lst, t_command *c, t_label *now, int size)
{
	int     i;
	long long int x;
	// t_command	*tmp;
	char	*tmp;
	if(size == 4)
		x = 65535;
	if(size == 8)
		x = 4294967295;
	// s = lst->label;
	// printf("|%s\n", str);
	i = function_ret_one(str, lst, now);
	// printf("\n!!!i = %d!!!\n", i);
	if(i == -1)
	{
		i = cal1(lst->label, c, lst, str) / 2;
		i = x - i + 1;
		// printf("sdvig na byte = %d", i);

		tmp = ten_hex(i, NULL, size);
		// printf("  |%s|\n", tmp);
		return (tmp);
	}
	else if(i == 0)
	{
		i = cal2(now, c, lst) / 2;
		tmp = ten_hex(i == 0 ? 0 : x - i + 1, NULL, size);
		// printf("sdvig na byte = %d   |%s|\n", i, tmp);
		return (tmp);
	}
	else if(i == 1)
	{
		i = cal3(now, c, lst, str) / 2;
		// printf("%d\n", i);
		tmp = ten_hex(i, NULL, size);
		// printf("sdvig na byte = %d   [%s]\n", i, tmp);
		return(tmp);
	}
	return (NULL);
=======
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
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
}

int    instead_label_way(t_label *l, t_char *lst)
{
	t_label     *tmp;
	t_command   *c;
	int         i;
<<<<<<< HEAD
	char		*str;
	int		x;
=======

>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
	tmp = l;
	while(tmp)
	{
		c = tmp->command;
		while(c)
		{
			i = 0;
			while(i < c->num_param)
			{
<<<<<<< HEAD
				if(c->opcode > 0 && (c->param_type[i] == 20 || c->param_type[i] == 40))
				{
					x = lst->op[c->opcode - 1].label_size;
					if(!x)
						x = 2;
					// printf("x = %d  opcode = %s  ",x, lst->op[c->opcode - 1].name);
					str = calculation(c->param[i], lst, c, tmp, x * 2);
					if(!str)
					{
						// printf("Error label");
						return 0;
					}
					free(c->param[i]);
					c->param[i] = str;
=======
				if(c->param_type[i] == 20 || c->param_type[i] == 40)
				{
					calculation(c->param[i], lst, c, tmp);
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
				}
				i++;
			}
			c = c->next;
		}
<<<<<<< HEAD
		tmp = tmp->next;
=======
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
	}
	return (0);
}