/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:15:55 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/14 15:37:25 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a, int i)
{
	t_stack	*tmp;
	t_stack	*last;

	last = ft_last_stack(stack_a);
	tmp = *stack_a;
	last->next = *stack_a;
	*stack_a = last;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = 0;
	if (i)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int i)
{
	t_stack	*tmp;
	t_stack	*last;

	last = ft_last_stack(stack_b);
	tmp = *stack_b;
	last->next = *stack_b;
	*stack_b = last;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = 0;
	if (i)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
