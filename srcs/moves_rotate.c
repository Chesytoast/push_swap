/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:46:39 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/15 15:15:14 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a, int i)
{
	t_stack	*last;
	t_stack	*tmp;

	last = ft_last_stack(stack_a);
	last->next = *stack_a;
	tmp = (*stack_a)->next;
	(*stack_a)->next = 0;
	*stack_a = tmp;
	if (i)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int i)
{
	t_stack	*last;
	t_stack	*tmp;

	last = ft_last_stack(stack_b);
	last->next = *stack_b;
	tmp = (*stack_b)->next;
	(*stack_b)->next = 0;
	*stack_b = tmp;
	if (i)
		write(1, "ba\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
