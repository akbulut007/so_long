/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:01:48 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 18:01:51 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_dup;
	int		size;

	s_dup = (char *)s;
	size = 0;
	while (s_dup[size])
		size++;
	while (size >= 0)
	{
		if (s_dup[size] == (char)c)
			return (&s_dup[size]);
		size--;
	}
	return (NULL);
}
