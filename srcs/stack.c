/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:27:11 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/15 16:22:56 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_new_stack(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->order = -1;
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
		*stack = new;
	else if (*stack && new)
	{
		tmp = *stack;
		new->next = tmp;
		*stack = new;
	}
}

void	ft_clear_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
	if (stack)
		free (stack);
}

t_stack	*ft_last_stack(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	if (!last)
		return (0);
	while (last->next)
		last = (last)->next;
	return (last);
}
