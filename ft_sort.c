/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:08:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/17 19:28:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define A_ uint64_t last, int (*compar)(const void *, const void *), size_t

inline static void		ft_swap(void *a, void *b, size_t type_size)
{
	register size_t		i;
	register uint8_t	tmp_short;
	register uint64_t	tmp;

	i = 0;
	while (i < (type_size & 7) && i < type_size)
	{
		tmp_short = ((uint8_t*)a)[i];
		((uint8_t*)a)[i] = ((uint8_t*)b)[i];
		((uint8_t*)b)[i] = tmp_short;
		i++;
	}
	while (i < type_size)
	{
		tmp = ((uint64_t*)a)[i];
		((uint64_t*)a)[i] = ((uint64_t*)b)[i];
		((uint64_t*)b)[i] = tmp;
		i += 8;
	}
}

inline static uint64_t	ft_partitioning(void *tab, uint64_t start
										, uint64_t pivot, A_ type_size)
{
	uint64_t	i;
	uint64_t	u;

	ft_swap(tab + last * type_size, tab + pivot * type_size, type_size);
	i = start;
	u = start;
	while (i < last)
	{
		if (compar(tab + i * type_size, tab + last * type_size) < 0)
			ft_swap(tab + i * type_size, tab + (u++ * type_size), type_size);
		i++;
	}
	ft_swap(tab + last * type_size, tab + u * type_size, type_size);
	return (u);
}

inline static void		ft_quicksort(void *tab, uint64_t start
							, A_ type_size)
{
	uint64_t	pivot;

	if (start < last)
	{
		pivot = (ft_random() % (last - start + 1)) + start;
		pivot = ft_partitioning(tab, start, pivot, last, compar, type_size);
		if (pivot > 0)
			ft_quicksort(tab, start, pivot - 1, compar, type_size);
		ft_quicksort(tab, pivot + 1, last, compar, type_size);
	}
}

void					ft_sort(void *tab, size_t elem_nbr
						, size_t type_size
						, int (*compar)(const void *, const void *))
{
	if (!elem_nbr)
		return ;
	ft_quicksort(tab, 0, elem_nbr - 1, compar, type_size);
	return ;
}

#undef A_
