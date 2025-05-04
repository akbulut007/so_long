/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:01:35 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 18:01:36 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (s1_copy[i] && s2_copy[i] && i < n)
	{
		if (s1_copy[i] < s2_copy[i])
			return (s1_copy[i] - s2_copy[i]);
		else if (s1_copy[i] > s2_copy[i])
			return (s1_copy[i] - s2_copy[i]);
		i++;
	}
	if (i < n)
		return (s1_copy[i] - s2_copy[i]);
	return (0);
}
