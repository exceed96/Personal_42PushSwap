/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:35:37 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:21:46 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sf(t_list **stack, t_list **stack_2)
{
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack) >= 2)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		ft_lstadd_front(stack, tmp);
	}
}

void	ft_pf(t_list **stack, t_list **stack_2)
{
	t_list	*tmp;

	if (ft_lstsize(*stack))
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstadd_front(stack_2, tmp);
	}
}

void	ft_rf(t_list **stack, t_list **stack_2)
{
	t_list	*tmp;

	(void)stack_2;
	if (ft_lstsize(*stack) >= 2)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = 0;
		ft_lstadd_back(stack, tmp);
	}
}

void	ft_rrf(t_list **stack, t_list **stack_2)
{
	t_list	*tmp;
	t_list	*last;

	(void)stack_2;
	if (ft_lstsize(*stack) >= 2)
	{
		last = *stack;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *stack;
		*stack = last;
	}
}
