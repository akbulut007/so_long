/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:00:54 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 18:00:55 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strconcat(char const *s1, char const *s2, char *ptr)
{
	int		i;
	int		j;
	char	*p;

	p = ptr;
	i = 0;
	while (s1[i])
	{
		*p = s1[i];
		p++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		*p = s2[j];
		p++;
		j++;
	}
	*p = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = malloc(i + j + 1);
	if (ptr == NULL)
		return (NULL);
	return (ft_strconcat(s1, s2, ptr));
}
