/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:47:17 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/12 12:47:18 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int     prog_size(t_label *l)
{
    t_command   *t;
    char        **par;
    char        *tmp;
    int         i;
    int         ret;

    ret = 0;
    while(l)
    {
        t = l->command;
        while(t)
        {
            i = 0;
            par = t->param;
            while(i < t->num_param)
            {
                tmp = par[i];
                while(*tmp)
                {
                    tmp++;
                    ret++;
                }
                i++;
            }
            t = t->next;
        }
        l = l->next;
    }
    return ret;
}