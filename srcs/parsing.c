/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:35:38 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/16 11:44:37 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	parsing(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**arg;

	arg = NULL;
	if (ac == 2)
		arg = arg_to_tab2(av);
	if (ac > 2)
		arg = arg_to_tab(ac, av);
	if (check_arg(arg) == 1)
		ft_arg_error(arg);
	init_stack(arg, stack_a, stack_b);
}

char	**arg_to_tab2(char **av)
{
	char	**tab;
	size_t	i;

	if (!av[1] || !av[1][0])
		return (NULL);
	i = 0;
	while (av[1] && av[1][i] == ' ')
		i++;
	if (i == ft_strlen(av[1]))
		ft_arg_error(NULL);
	tab = ft_split(av[1], ' ');
	if (!tab)
		return (NULL);
	return (tab);
}

char	**arg_to_tab(int ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * ac);
	if (!tab)
		return (NULL);
	while (ac - 1 > i)
	{
		tab[i] = ft_strdup(av[i + 1]);
		if (!tab[i])
			return (ft_free_return(tab, i));
		if (!tab[i][0])
			empty_arg_error(tab, i + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	check_arg(char **arg)
{
	int	i;
	int	j;

	i = 0;
	if (!arg)
		return (1);
	while (arg[i])
	{
		j = 0;
		if (arg[i][0] == '-' || arg[i][0] == '+')
			j++;
		while (arg[i][j])
		{	
			if (!ft_isdigit(arg[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_stack(char **tab, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;
	int		i;
	int		nb;

	i = 0;
	*stack_a = NULL;
	while (tab[i])
	{
		nb = ft_ps_atoi(tab[i], stack_a, stack_b);
		new = ft_new_stack(nb);
		if (!new)
			ft_clear_stack(stack_a);
		ft_add_back(stack_a, new);
		i++;
	}
	ft_free_tab(tab);
}
