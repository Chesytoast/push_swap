/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:52:35 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/16 11:34:12 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_radix(t_stack **stack_a, t_stack **stack_b, int max)
{
	t_stack	*tmp;
	int		size;
	int		i;
	int		j;

	size = stack_size(*stack_a);
	while (size >> max)
		max++;
	i = 0;
	while (i < max)
	{
		j = 0;
		while (size > j)
		{
			tmp = *stack_a;
			if ((tmp->order >> i) & 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = *stack_a;
	b = a->next;
	c = b ->next;
	if (a->order > c->order && a->order > b->order)
		ra(stack_a, 1);
	if (b->order > c->order && b->order > a->order)
		rra(stack_a, 1);
	if (ft_is_sorted(stack_a))
		sa(stack_a, 1);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*min;

	min = *stack_a;
	while (min->order != i)
		min = min->next;
	while (*stack_a != min)
	{
		ra(stack_a, 1);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = *stack_a;
	while (min->order != 1)
		min = min->next;
	while (*stack_a != min)
	{
		ra(stack_a, 1);
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b, 2);
	pa(stack_a, stack_b);
}

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max;

	max = 0;
	size = stack_size(*stack_a);
	if (!ft_is_sorted(stack_a))
		return ;
	if (size == 2)
		sa(stack_a, 1);
	if (size == 3)
		sort_3(stack_a);
	if (size == 4)
		sort_4(stack_a, stack_b, 1);
	if (size == 5)
		sort_5(stack_a, stack_b);
	if (size > 5)
		ft_radix(stack_a, stack_b, max);
}
