/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_c3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:42:01 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:22:39 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_stack_min(t_list *stack)
{
	int	n;
	int	min;

	min = ft_atoi(stack->content);
	while (stack)
	{
		n = ft_atoi(stack->content);
		if (min > n)
			min = n;
		stack = stack->next;
	}
	return (min);
}

int	ft_stack_max(t_list *stack)
{
	int	n;
	int	max;

	max = ft_atoi(stack->content);
	while (stack)
	{
		n = ft_atoi(stack->content);
		if (max < n)
			max = n;
		stack = stack->next;
	}
	return (max);
}
