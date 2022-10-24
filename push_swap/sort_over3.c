/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:30:56 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:21:54 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_finish(t_list **stack)
{
	int	i;

	i = ft_idx_start_end(*stack, ft_stack_min(*stack));
	if (i < 0)
		ft_f_check(stack, 0, "rra", -i);
	else
		ft_f_check(stack, 0, "ra", i);
}

void	ft_sort_over3(t_list **stack)
{
	t_list	*stack_2;
	int		a;
	int		b;

	stack_2 = 0;
	while (ft_lstsize(*stack) > 3)
		ft_f_check(stack, &stack_2, "pb", 1);
	if (!ft_sort_check(*stack))
		ft_sort_c3(stack);
	while (ft_lstsize(stack_2))
	{
		a = 0;
		b = 0;
		ft_search_min(*stack, stack_2, &a, &b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			ft_count_same(stack, &stack_2, a, b);
		else
			ft_count_diff(stack, &stack_2, a, b);
		ft_f_check(&stack_2, stack, "pa", 1);
	}
}
