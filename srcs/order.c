/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:01:24 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/14 12:50:44 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_order(t_stack **stack)
{
	t_stack		*tmp;
	t_stack		*point;
	long int	min;
	int			i;

	i = 1;
	while (i <= stack_size(*stack))
	{
		tmp = *stack;
		point = tmp;
		min = 2147483648;
		while (tmp)
		{
			if (tmp->nb < min && tmp->order == -1)
			{
				min = tmp->nb;
				point = tmp;
			}
			tmp = tmp->next;
		}
		point->order = i;
		i++;
	}
}
