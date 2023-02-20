/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:43:30 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/16 15:29:36 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac == 1)
		return (0);
	stack_a = malloc(sizeof(t_stack **) * 1);
	if (!stack_a)
		return (-1);
	stack_b = malloc(sizeof(t_stack **) * 1);
	if (!stack_b)
	{
		free (stack_a);
		return (-1);
	}
	*stack_b = NULL;
	parsing(ac, av, stack_a, stack_b);
	if (check_if_double(stack_a) == -1)
		double_error(stack_a, stack_b);
	init_order(stack_a);
	algo(stack_a, stack_b);
	ft_free_all(stack_a, stack_b);
	return (0);
}
