/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:49:34 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/19 15:15:55 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_create_node(int val)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n ->value = val;
	n ->index = -42;
	n ->next = NULL;
	n ->prev = NULL;
	return (n);
}

void	ft_addback(t_node **head, t_node *new)
{
	t_node	*cur;

	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur ->next)
		cur = cur ->next;
	cur ->next = new;
	new ->prev = cur;
}

void	ft_addfront(t_node **head, t_node *new)
{
	if (!head || !new)
		return ;
	new ->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}

int	ft_list_size(t_node *head)
{
	int		i;

	i = 0;
	while (head)
	{
		head = head ->next;
		i++;
	}
	return (i);
}
