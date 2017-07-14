/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:01:56 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/11 18:01:56 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int     write_one_octet(t_file *f, int size)
{
<<<<<<< HEAD
	while(f->x < 4 && f->j < size)
	{
		if(f->str && *(f->str))
		{
			write(f->fd, (f->str), 1);
			(f->str)++;
		}
		else if(size == 256 || size == 4104 )
			write(f->fd, "0", 1);
		else
			return 1;
		f->j++;
		f->x++;
	}
	return (0);
=======
    while(f->x < 4 && f->j < size)
    {
        if(f->str && *(f->str))
        {
            write(f->fd, (f->str), 1);
            (f->str)++;
        }
        else if(size == 256 || size == 4104 )
            write(f->fd, "0", 1);
        else
            return 1;
        f->j++;
        f->x++;
    }
    return (0);
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
}

void    write_str(t_file *f, int size)
{
<<<<<<< HEAD
	// printf("%s\n", f->str);
	 while(f->o < 8 && f->j < size)
	 {
		if(write_one_octet(f, size))
				return ;
		if(f->x == 4)
		{
			if(f->o != 7)
				write(f->fd, " ", 1);
			f->x = 0;
			f->o++;
		}
		if(f->o == 8)
		{
			f->o = 0;
			write(f->fd, "\n", 1);        
		}
	 }
}

void    write_byte_code_in_file(t_label *l, t_file *f, t_char *lst)
{
	char   *tmp;
	t_command *com;
	int i;
	while(l)
	{
		com = l->command;
		while(com)
		{
			f->j = 0;
			tmp = ten_hex(com->opcode, NULL, 2);//+1 || -1 || ni4ego
			f->str = tmp;
			// printf("[%s]   ", lst->op[com->opcode - 1].name);
			// printf("%s", f->str);
			write_str(f, 99);
			free(tmp);
			f->str = NULL;
			
			if(lst->op[com->opcode - 1].octage)
			{
				tmp = codage_octal(com, lst);
				// printf("|%s|", lst->op[com->opcode - 1].name);
				f->str = tmp;
				// printf("|%s|", f->str);
				write_str(f, 99);
				free(tmp);
				f->str = NULL;
			}
			i = 0;
			while(i < com->num_param)
			{
				f->str = com->param[i];
				// printf(" [%s] ", f->str);
				write_str(f, 99);
			 i++;
			}
			// printf("\n");
			com = com->next;
		}
		l = l->next;
	}
=======
      while(f->o < 8 && f->j < size)
      {
         if(write_one_octet(f, size))
               return ;
         if(f->x == 4)
         {
             if(f->o != 7)
                 write(f->fd, " ", 1);
             f->x = 0;
             f->o++;
         }
         if(f->o == 8)
         {
            f->o = 0;
            write(f->fd, "\n", 1);        
         }
      }
}

void    write_byte_code_in_file(t_label *l, t_file *f)
{
    char   *tmp;
    int i;
    while(l)
    {
        while(l->command)
        {
           tmp = ten_hex(l->command->opcode, NULL, 2);//+1 || -1 || ni4ego
           write_str(f, 2);
           free(tmp);
          i = 0;
           while(i < l->command->num_param)
           {
                f->str = l->command->param[i];
                write_str(f, 99);
              i++;
           }
        }
    }
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
}

void    write_in_file(int fd, t_char *lst)
{
<<<<<<< HEAD
	t_file  *f;
	// char    *tmp;

	f = (t_file *)malloc(sizeof(t_file));
	// write(fd, "00ea 83f3 ", 10);
	f->size =  lst->size / 2;
	f->fd = fd;
	f->x = 0;
	f->j = 0;
	// f->o = 2;
	f->o = 0;
	// f->str = lst->name;
	// printf("asfasf\n");
	// write_str(f, 256);
	// printf("asfasf\n");
	// free(lst->name);
	f->j = 0;
	// tmp = ten_hex(f->size, NULL, 8);
	// printf("|%s| %d\n", tmp, lst->size);
	// f->str = tmp;
	// write_str(f, 16);
	// free(tmp);
	f->j = 0;
	f->str = NULL;
	// f->str = lst->comment;
	// write_str(f, 4104);
	// f->str = NULL;
	f->j = 0;
	write_byte_code_in_file(lst->label, f, lst);//proverit nado
=======
    t_file  *f;
    char    *tmp;

    f = (t_file *)malloc(sizeof(t_file));
    write(fd, "00ea 83f3 ", 10);
    f->size =  11;//ispravit
    f->fd = fd;
    f->x = 0;
    f->j = 0;
    f->o = 2;
    write_str(f, 256);
    free(lst->name);
    f->j = 0;
    tmp = ten_hex(f->size, NULL, 16);
    write_str(f, 16);
    free(tmp);
    f->j = 0;;
    f->str = lst->comment;
    // write_str(f, 4104);
    // write_byte_code_in_file(l, f);proverit nado
>>>>>>> 9de9fc07f468cf26fc32bc129b6de77a284f77b1
}
