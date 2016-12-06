/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:39:15 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/06 17:41:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_page(void *addr)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = color - ((unsigned long)4096 - 1 & (unsigned long)color);
	while (i < 4096)
	{
		if (ft_isprint(tmp[i]))
			ft_putchar(tmp[i]);
		else
			ft_putchar('.');
		i++;
		if (!(i % 64))
			ft_putchar('\n');
	}
	ft_putchar('\n');
}