/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:48:08 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:48:11 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "../libft.h"

int		ft_printf(const char *fixed_arg, ...);
int		ft_print_dec(int n);
int		ft_print_hex_lower(unsigned int val);
int		ft_print_hex_upper(unsigned int val);
int		ft_print_pointer(void *val);
int		ft_print_str(char *s);
int		ft_print_undec(unsigned int num);
int		ft_strlen_pf(char *s);

#endif
