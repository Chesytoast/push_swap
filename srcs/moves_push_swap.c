/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:17:44 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/14 15:36:57 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a, int i)
{
	t_stack	*temp;

	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next ;
	temp->next = *stack_a;
	*stack_a = temp;
	if (i)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int i)
{
	t_stack	*temp;

	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next ;
	temp->next = *stack_b;
	*stack_b = temp;
	if (i)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	if (!*stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	if (!*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
