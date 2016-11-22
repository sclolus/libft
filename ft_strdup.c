/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:03:01 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/04 14:40:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	char	*buf;
	int		i;

	i = 0;
	buf = (char*)s1;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(buf) + 1)))
		return (0);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = s1[i];
	return (tmp);
}
