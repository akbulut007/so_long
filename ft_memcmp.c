/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:55:45 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:55:48 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s_1 != *s_2)
		{
			if (*s_1 > *s_2)
				return (*s_1 - *s_2);
			else if (*s_1 < *s_2)
				return (*s_1 - *s_2);
		}
		n--;
		s_1++;
		s_2++;
	}
	return (0);
}
