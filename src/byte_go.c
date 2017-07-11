/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:23:06 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/06 14:23:06 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	function_delete_vuvod_l(t_label *l, t_char *lst)//delete
{
	t_command *tmp;

	while(l)
	{
		printf("L->name = %s\n", l->name);
		tmp = l->command;
		printf("  command:\n");
		{
			while(tmp && tmp->opcode != -1)
			{
				printf(" %d  [%s]\n",tmp->opcode, lst->op[tmp->opcode - 1].name );
				tmp = tmp->next;
			}
		}
		printf("\n");
		l = l->next;
	}
}

void	function_for_first_time(t_label *l)
{
	t_command	*s;

	l->command = (t_command *)malloc(sizeof(t_command));
	s = l->command;
	s->opcode = -1;
	// s->b1 = 0;
	// s->b2 = 0;
	// s->b3 = 0;
	s->next = NULL;
	l->name = NULL;
	l->command = s;
	l->next = NULL;

}

t_command *return_new_command(t_label *l)
{
	t_command	*s;

	while(l->next)
		l = l->next;
	s = l->command;
	while(s->next)
		s = s->next;
	if(s->opcode == -1)
		return (s);
	else
	{
		s->next = (t_command *)malloc(sizeof(t_command));
		s = s->next;
		s->next = NULL;
		s->opcode = -1;
		// s->b1 = 0;
		// s->b2 = 0;
		// s->b3 = 0;
	}
	return s;
}

t_label		*write_label_name(t_label *l, char *line)
{
	char 	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while(l->next)
		l = l->next;
	l->next = (t_label *)malloc(sizeof(t_label));
	l = l->next;
	function_for_first_time(l);
	tmp = line;
	while(tmp && *tmp && (*tmp == ' ' || *tmp == '\t'))
	{
		j++;
		tmp++;
	}
	while(tmp && *tmp && *tmp != ':' && *tmp != ' ')
	{
		i++;
		tmp++;
	}
	l->name = ft_strndup(line + j, i);
	return (l);
}

int		write_command_before_label(char **line, t_char *lst, t_label* l, int i)
{
	t_command	*tmp;

	while(!i)//write command  while(!label)
	{
		tmp = return_new_command(l);
		if(!correct_name_command(*line, lst, tmp))// || !valid_parametrs())
				return -1;
			free(*line);
			*line = read_while_empty(*line, lst->fd);
			i = label_this(*line);
	}
	return i;
}

int 	write_command_after_label(char **line, t_char *lst, t_label *tp, char **str)
{
	int			i;
	t_command	*tmp;
	
	i = 0;
	while(*line && !i)
	{
		tmp = return_new_command(tp);
		if(!correct_name_command(*str, lst, tmp))// || !valid_parametrs())
			return -1;
		free(*line);
		*line = read_while_empty(*line, lst->fd);
		*str = *line;
		// printf("*l = |%s|\n", *line);
		i = label_this(*line);
	}
	if(!*line)
		return 0;
	return i;
}

int		byte_go(int fd, t_char *lst)
{
	char 		*line;
	char 		*str;
	int 		i;
	t_label		*l;
	t_label		*tp;

	l = (t_label *)malloc(sizeof(t_label));
	lst->label = l;
	function_for_first_time(l);
	i = 0;
	line = NULL;
	line = read_while_empty(line, fd);
	if(!line)
		return 0;
	i = write_command_before_label(&line, lst, l, label_this(line));
	while(i == 1)
	{
		tp = write_label_name(l, line);
		str = line;
		while(*str != ':')
			str++;
		str++;
		if(!have_something_after_space(str))
		{
			free(line);
			line = read_while_empty(line, fd);
			str = line;
		}
		i = 0;
		i = write_command_after_label(&line, lst, tp, &str);
		// printf("i = %d\n", i);
	}
	//l->next->command->b1 = 20;
	//l->next->command->a1 = ft_strdup("adasf");
	// printf("-?%d ", valid_label(l));
	if(i == -1 || !valid_label(l))
		return 0;
	function_delete_vuvod_l(l, lst);//delete
	return 1;
}