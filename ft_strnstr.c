/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:01:41 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 18:01:43 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*sub_str;
	size_t	i;
	size_t	j;

	str = (char *)haystack;
	sub_str = (char *)needle;
	if (sub_str[0] == '\0')
		return (str);
	if (len == 0)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == sub_str[j] && (i + j) < len)
		{
			if (sub_str[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
