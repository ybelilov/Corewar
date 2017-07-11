/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:56:33 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/05 13:56:33 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdio.h>//del
# include "../libft/libft.h"
# include "op.h"


# define HEX "0123456789abcdef"
# define OP main->op
typedef struct			s_op
{
	char				name[20];
	int					arguments;
	int					r_d_i[10];
	int					number;
	int					cycles;
	char				desriptions[200];
	int					carry;
	int					octage;
	int					label_size;
}						t_op;

typedef struct			s_command
{
	int					opcode;
	int 				b1;
	int 				b2;
	int					b3;
	char				*a1;
	char				*a2;
	char				*a3;
	struct s_command	*next;
}						t_command;

typedef struct			s_label
{
	char 				*name;
	t_command			*command;
	struct s_label		*next;
}						t_label;

typedef struct			s_char
{
	char 				*name;
	char 				*comment;
	int					fd;
	t_op				*op;
	t_label				*label;
}						t_char;

int						correct_char_name(char *str, int size);
char 					*read_while_empty(char *line, int fd);
char					*ten_hex(int i, char *str, int size);
int						byte_go(int fd, t_char *lst);
int						correct_label_char(char *str, int size);
void					get_op(t_char *lst);
int						have_something_after_space(char *str);
int						label_this(char *line);
int 					correct_name_command(char *line,  t_char *lst, t_command *s);
int						valid_label(t_label *l);
/*
	Parameter validation
*/
int		parameter_validation(t_char *main, t_command *command, char *com);
int		is_t_dir(char *arg);
int		is_t_ind(char *arg);
int		is_t_reg(char *arg);
/*
	Helpful functions
*/
long int	array_len(char **arr);
char		**ft_array_trim(char **array);



#endif
// printf("[%d]   lst->op[i].name = [%s]\n", i, lst->op[15].name);