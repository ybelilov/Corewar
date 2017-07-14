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

//max prog size, проверка
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

<<<<<<< HEAD
typedef struct            s_file
=======
typedef struct			s_file
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
{
	char				size;
	int					fd;
	char				*str;
	int					x;
	int					j;
	int					o;
<<<<<<< HEAD
}                        t_file;
=======
}						t_file;
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1

typedef struct			s_command
{
	int					opcode;
	int					num_param;
	int 				param_type[3];
	char				**param;
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
	int					size;
	t_op				*op;
	t_label				*label;
}						t_char;

int						correct_char_name(char *str, int size);
char 					*read_while_empty(char *line, int fd);
char					*ten_hex(long long int i, char *str, int size);
int						byte_go(int fd, t_char *lst);
int						correct_label_char(char *str, int size);
void					get_op(t_char *lst);
int						have_something_after_space(char *str);
int						label_this(char *line);
int 					correct_name_command(char *line,  t_char *lst, t_command *s);
int						valid_label(t_label *l);
void   					write_in_file(int fd, t_char *lst);
<<<<<<< HEAD
int						prog_size(t_char *lst);//prover
int    					instead_label_way(t_label *l, t_char *lst);
char					*codage_octal(t_command *c, t_char *lst);
int						weight_command(t_command *c, t_char *lst);
=======
int    					prog_size(t_label *l);//prover
int    					instead_label_way(t_label *l, t_char *lst);
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
/*
	Parameter validation
*/
int		parameter_validation(t_char *main, t_command *command, char *com);
int		is_t_dir(char *arg, int *param_type, char **param, int size);
int		is_t_ind(char *arg, int *param_type, char **param);
int		is_t_reg(char *arg, int *param_type, char **param);
/*
	Helpful functions
*/
long int	array_len(char **arr);
char		**ft_array_trim(char **array);



#endif
// printf("[%d]   lst->op[i].name = [%s]\n", i, lst->op[15].name);