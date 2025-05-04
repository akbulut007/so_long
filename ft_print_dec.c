/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:47:51 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:47:54 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int n)
{
	char	*nb;
	int		str_size;

	str_size = 0;
	nb = ft_itoa(n);
	ft_print_str(nb);
	str_size = ft_strlen_pf(nb);
	free(nb);
	return (str_size);
}
