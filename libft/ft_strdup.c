/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:49:18 by ngulya            #+#    #+#             */
/*   Updated: 2016/11/25 19:39:28 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *a;

	a = (char *)malloc(ft_strlen(s1) + 1);
	if (a != NULL)
		ft_strcpy(a, s1);
	return (a);
}
