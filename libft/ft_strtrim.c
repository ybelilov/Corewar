/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:56:03 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/02 15:10:22 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	char	*result;
	size_t	t;

	if (s)
	{
		result = NULL;
		res = (char *)s;
		t = ft_strlen(s);
		while (*s && (*s == ' ' || *s == '\n' || *s == '\t') && t--)
			s++;
		res = (char *)s;
		s = ft_strtoend(s);
		while ((*s == ' ' || *s == '\n' || *s == '\t') && t-- && *s)
			s--;
		result = (char *)malloc(t + 1);
		if (result)
		{
			result = ft_strncpy(result, res, t);
			*(result + t) = '\0';
			return (result);
		}
	}
	return (NULL);
}
