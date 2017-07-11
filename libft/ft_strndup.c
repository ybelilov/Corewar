/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 13:38:47 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/08 13:39:05 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int size)
{
	char *a;

	a = (char *)malloc(size + 1);
	if (a != NULL)
	{
		*(a+size) = '\0';
		strncpy(a, s1, size);
	}
	return (a);
}
