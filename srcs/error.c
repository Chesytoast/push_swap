/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:26:44 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/16 11:49:25 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_arg_error(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	write(2, "Error\n", 6);
	write(2, "Arguments must be number only\n", 30);
	exit(EXIT_FAILURE);
}

void	double_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_clear_stack(stack_a);
	free(stack_b);
	write(2, "Error\n", 6);
	write(2, "Can not have duplicate\n", 23);
	exit(EXIT_FAILURE);
}

void	max_value_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_clear_stack(stack_a);
	free(stack_b);
	write(2, "Error\n", 6);
	write(2, "Overflow\n", 9);
	exit(EXIT_FAILURE);
}

void	empty_arg_error(char **tab, int i)
{
	ft_free_return(tab, i);
	write(2, "Error\n", 6);
	write(2, "Can not have empty argument\n", 28);
	exit(EXIT_FAILURE);
}
