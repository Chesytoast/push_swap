/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:40 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/15 15:27:06 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_ps_atoi(const char *str, t_stack **stack_a, t_stack **stack_b)
{
	size_t		i;
	int			s;
	int			f;
	int			ftmp;

	f = 0;
	s = 1;
	i = 0;
	ftmp = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!ft_strncmp(str, "-2147483648", 11))
		return (-2147483648);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s = -1;
	while (str[i] <= '9' && str [i] >= '0')
	{
		ftmp = f;
		f = f * 10 + (str[i++] - 48);
		if (ftmp > f)
			max_value_error(stack_a, stack_b);
	}
	return ((int)f * s);
}

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *stack;
	while (tmp->next)
	{
		next = tmp->next;
		if (tmp->order > next->order)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_if_double(t_stack **stack)
{
	t_stack	*i;
	t_stack	*j;

	i = *stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->nb == j->nb)
				return (-1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
