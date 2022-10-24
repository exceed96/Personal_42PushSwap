/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:40:47 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:22:29 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_idx_start_end(t_list *stack, int n)
{
	int	i;
	int	s;
	int	size;

	i = 0;
	size = ft_lstsize(stack);
	s = ft_stack_max(stack);
	if (n <= ft_stack_min(stack))
		s = ft_stack_min(stack);
	else
		i++;
	while (stack)
	{
		if (ft_atoi(stack->content) == s)
			break ;
		i++;
		stack = stack->next;
	}
	if (i >= (size + 1) / 2)
		i = (size - i) * -1;
	return (i);
}

int	ft_idx_middle(t_list *stack, int n)
{
	int	i;
	int	n_1;
	int	n_2;
	int	size;

	size = ft_lstsize(stack);
	i = 1;
	while (stack->next)
	{
		n_1 = ft_atoi(stack->content);
		n_2 = ft_atoi(stack->next->content);
		if (n > n_1 && n < n_2)
			break ;
		i++;
		stack = stack->next;
	}
	if (i == size)
		i = 0;
	else if (i >= (size + 1) / 2)
		i = (size - i) * -1;
	return (i);
}

void	ft_count_same(t_list **stack, t_list **stack_2, int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		ft_f_check(stack, stack_2, "rr", ft_min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) >= ft_abs(b))
			ft_f_check(stack, 0, "ra", ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_f_check(stack_2, 0, "rb", ft_abs(ft_abs(b) - ft_abs(a)));
	}
	else
	{
		ft_f_check(stack, stack_2, "rrr", ft_min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) >= ft_abs(b))
			ft_f_check(stack, 0, "rra", ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_f_check(stack_2, 0, "rrb", ft_abs(ft_abs(b) - ft_abs(a)));
	}
}

void	ft_count_diff(t_list **stack, t_list **stack_2, int a, int b)
{
	if (a >= 0 && b < 0)
	{
		ft_f_check(stack, 0, "ra", a);
		ft_f_check(stack_2, 0, "rrb", ft_abs(ft_min(a, b)));
	}
	else
	{
		ft_f_check(stack_2, 0, "rb", b);
		ft_f_check(stack, 0, "rra", ft_abs(ft_min(a, b)));
	}
}

void	ft_search_min(t_list *stack, t_list *stack_2, int *a, int *b)
{
	int	n;
	int	x;
	int	y;
	int	stack_2_count;
	int	size;

	stack_2_count = -1;
	size = ft_lstsize(stack_2);
	while (++stack_2_count >= 0 && stack_2)
	{
		n = ft_atoi(stack_2->content);
		if (n < ft_stack_min(stack) || n > ft_stack_max(stack))
			x = ft_idx_start_end(stack, n);
		else
			x = ft_idx_middle(stack, n);
		y = stack_2_count;
		if (stack_2_count >= (size + 1) / 2)
			y = (size - stack_2_count) * -1;
		if (!stack_2_count || ft_abs(*a) + ft_abs(*b) > ft_abs(x) + ft_abs(y))
		{
			*a = x;
			*b = y;
		}
		stack_2 = stack_2->next;
	}
}
