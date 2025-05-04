/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:48:42 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:48:44 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	i;
	int	str_size;

	str_size = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		str_size = ft_strlen_pf("(null)");
		return (str_size);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	str_size = i;
	return (str_size);
}
