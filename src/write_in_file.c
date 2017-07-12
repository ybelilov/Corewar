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
}

void    write_str(t_file *f, int size)
{
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
}

void    write_in_file(int fd, t_char *lst)
{
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
}
