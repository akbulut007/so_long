/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:53:08 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:53:12 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *lst_content)
{
	if (lst_content)
		lst_content = NULL;
	free(lst_content);
}

void	ft_lstdelon(t_list *lst, void (*del)(void *))
{
	del(lst->content);
}
