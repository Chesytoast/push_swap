/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:43:51 by mcourtin          #+#    #+#             */
/*   Updated: 2023/02/16 10:52:23 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nb;
	int				order;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack	**stack_a;
	t_stack	**stack_b;
}	t_data;

//parsing :
void	parsing(int ac, char **av, t_stack **stack_a, t_stack **stack_b);
char	**arg_to_tab(int ac, char **av);
char	**arg_to_tab2(char **av);
int		check_arg(char **arg);
void	init_stack(char **tab, t_stack **stack_a, t_stack **stack_b);
int		check_if_double(t_stack **stack);

//stack :
t_stack	*ft_new_stack(int nb);
void	ft_add_back(t_stack **stack, t_stack *new);
void	ft_add_front(t_stack **stack, t_stack *new);
void	ft_clear_stack(t_stack **stack);
t_stack	*ft_last_stack(t_stack **stack);

//moves :
void	sa(t_stack **stack_a, int i);
void	sb(t_stack **stack_b, int i);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int i);
void	rb(t_stack **stack_b, int i);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int i);
void	rrb(t_stack **stack_b, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//error :
void	ft_arg_error(char **tab);
void	double_error(t_stack **stack, t_stack **stack_b);
void	max_value_error(t_stack **stack_a, t_stack **stack_b);
void	empty_arg_error(char **tab, int i);

//utils :
int		stack_size(t_stack *stack);
int		ft_ps_atoi(const char *str, t_stack **stack, t_stack **stack_b);
int		ft_is_sorted(t_stack **stack);

//free :
void	ft_free_all(t_stack **stack_a, t_stack **stack_b);
void	ft_free_tab(char **tab);

//order :
void	init_order(t_stack **stack);

//algo :
void	algo(t_stack **stack_a, t_stack **stack_b);

#endif