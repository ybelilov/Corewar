/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:52:09 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/05 13:52:09 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		correct_end_s(char *s)
{
	while(*s && *s != '.')
		s++;
	if(*s && !ft_strcmp(s, ".s") && !*(s + 2))
		return 1;
	return 0;
}

void	write_char_hex(char *line, t_char *lst, int i)
{
	if (i == 1)
	{
		while(*line && *line != '"')
		{
			lst->name = ten_hex(*line, lst->name, 2);
			line++;
		}
	}
	if (i == 2)
	{
		while(*line && *line != '"')
		{
			lst->comment = ten_hex(*line, lst->comment, 2);
			line++;
		}
	}
}



int		ok_lets_go(int fd, t_char *lst)
{
	char 	*line;

	line = NULL;
	line = read_while_empty(line, fd);
	printf("|%s\n|", line + 5);
	if (line && !ft_strncmp(line,  NAME_CMD_STRING, 5) && have_something_after_space(line + 5) \
		&& correct_char_name(line + 5, 128))
	{
		write_char_hex(line + 7, lst, 1);
		free(line);
		line = read_while_empty(line, fd);
		if (line && !ft_strncmp(line, COMMENT_CMD_STRING, 8) && have_something_after_space(line + 8) \
			&& correct_char_name(line + 8, 2048))
		{
			write_char_hex(line + 10, lst, 2);
			free(line);
			get_op(lst);
			if(!byte_go(fd, lst))
			{
				printf("Error\n");
				return 0;
			}
		}
		else
		{
			printf("Error: bad comment\n");
			return 0;
		}
	}
	else
	{
		printf("Error: bad name\n");
		return 0;
	}
	return 1;
}

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	t_char	*lst;
	char 	*tmp;
	char 	*name;

	fd = -1;
	if (argc > 2)
		printf("Error: Too many arguments\n");
	else if(argc == 1 || (argc == 2 && !correct_end_s(argv[1]))){
		printf("./asm filename.s\n");
	}
	else
	{
			fd = open(argv[1], O_RDONLY);
			tmp = ft_strndup(argv[1], ft_strlen(argv[1])-2);
			name = ft_strjoin(tmp, ".cor");
			free(tmp);
			fd2 = open(name, O_TRUNC);
			if(fd2 == -1)
				fd2 = open(name , O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
			else
			{
				close(fd2);
				fd2 = open(name , S_IRUSR | S_IWUSR | O_RDWR);
			}
			if(fd2 == -1)
			{
				close(fd);
				printf("Error: couldn't create file, maybe you need chmod\n");
				return (1);
			}
		if(fd < 0)
		{
			close(fd2);
			printf("Error: Bad file\n");
		}
		else
		{
			lst = (t_char *)malloc(sizeof(t_char));
			lst->name = NULL;
			lst->fd = fd;
			lst->comment = NULL;
			if(ok_lets_go(fd, lst))
				write_in_file(fd2, lst);
			close(fd2);
			close(fd);
		}
	}
	return 0;
}