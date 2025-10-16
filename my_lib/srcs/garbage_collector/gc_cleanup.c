/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:13:54 by yaabdall          #+#    #+#             */
/*   Updated: 2025/04/25 16:05:06 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_cleanup(t_gc *gc)
{
	t_gc_node	*current;
	t_gc_node	*next;

	if (!gc)
		return ;
	current = gc->head;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	gc->head = NULL;
}
