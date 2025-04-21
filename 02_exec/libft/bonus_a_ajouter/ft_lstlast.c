/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:28:58 by root              #+#    #+#             */
/*   Updated: 2025/03/10 08:32:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("1");
// 	lst->next = ft_lstnew("yrfdqfsd");
// 	t_list *node = ft_lstlast(lst);
// 	printf("%s\n", (char *)node->content);
// }