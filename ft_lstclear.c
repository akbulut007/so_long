/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:52:58 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:53:02 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *lst_content)
{
	if (lst_content)
		lst_content = NULL;
	free(lst_content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	while (*lst)
	{
		curr = (*lst)->next;
		del(curr->content);
		free(*lst);
		*lst = curr;
	}
}
