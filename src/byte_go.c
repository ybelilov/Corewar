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
		if(tmp)
		{
			printf("  command:\n");
		while(tmp)
			{
				// printf("op=%d", tmp->opcode);
				printf("  [%s]",lst->op[tmp->opcode - 1].name);
				printf(" num = %d   ", tmp->num_param);
				printf("[%d %s]    [%d %s]    [%d %s]\n", tmp->param_type[0],tmp->param[0], tmp->param_type[1], tmp->param[1], tmp->param_type[2], tmp->param[2]);
				tmp = tmp->next;
			}
		}
		else
			printf("\nErrorororoororo\n");
		printf("\n\n");
		l = l->next;
	}
}

void	function_for_first_time(t_label *l)
{
	t_command	*s;
	char		**tmp;

	l->command = (t_command *)malloc(sizeof(t_command));
	s = l->command;
	s->opcode = -1;
	s->num_param = 0;
	s->param_type[0] = 0;
	s->param_type[1] = 0;
	s->param_type[2] = 0;
	s->param = (char **)malloc(sizeof(char *) * 3);
	tmp = s->param;
	tmp[0] = NULL;
	tmp[1] = NULL;
	tmp[2] = NULL;
	s->next = NULL;
	l->name = NULL;
	l->command = s;
	l->next = NULL;

}

t_command *return_new_command(t_label *l)
{
	t_command	*s;
	char		**tmp;

	while(l->next)
		l = l->next;
	s = l->command;
	while(s && s->next)
		s = s->next;
	if(s->opcode == -1)
		return (s);
	else
	{
		s->next = (t_command *)malloc(sizeof(t_command));
		s = s->next;
		s->next = NULL;
		s->opcode = -1;
		s->num_param = 0;
		s->param_type[0] = 0;
		s->param_type[1] = 0;
		s->param_type[2] = 0;
		s->param = (char **)malloc(sizeof(char *) * 3);
		tmp = s->param;
		tmp[0] = NULL;
		tmp[1] = NULL;
		tmp[2] = NULL;
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
		if(!correct_name_command(*line, lst, tmp))
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
		if(!correct_name_command(*str, lst, tmp))
			return -1;
		free(*line);
		*line = read_while_empty(*line, lst->fd);
		*str = *line;
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
	if(!(line = read_while_empty(line, lst->fd)))
		return 0;
	i = write_command_before_label(&line, lst, l, label_this(line));
	while(i == 1)
	{
		// printf("wqr=\n");
		tp = write_label_name(l, line);
		// printf("|%s|\n", line);
		// if(!ft_strcmp("wall:", line))
		// {
			// printf("1\n");
		// }
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
	}
	// printf("line =%s i=%d\n", line, i);
	if(i == -1 || !valid_label(l))//!size_ok(l)
		return 0;
	// printf("i =%d\n", i);
	if(l->command->opcode == -1)
	{
		free(l->command);
		l->command = NULL;
	}
	instead_label_way(l, lst);
	if(!prog_size(lst))
		return 0;
	// function_delete_vuvod_l(l, lst);
	// i  = codage_octal(l->command,lst);
	// printf("==%d\n", i);
	// printf("%s\n", return_hex_octal(i));
	// function_delete_vuvod_l(l, lst);
	return 1;
}