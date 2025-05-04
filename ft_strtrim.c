/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:01:55 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 18:01:57 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_substr_cpy(char const *s1, int start_idx, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s1[start_idx + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start_idx;
	int	end_idx;
	int	size;

	if (!s1 || !set)
		return (NULL);
	start_idx = 0;
	while (s1[start_idx] && find_set(s1[start_idx], set))
		start_idx++;
	end_idx = ft_strlen(s1);
	while (end_idx > start_idx && find_set(s1[end_idx - 1], set))
		end_idx--;
	size = end_idx - start_idx;
	return (ft_substr_cpy(s1, start_idx, size));
}
