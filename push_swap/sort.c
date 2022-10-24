/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:19:41 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:21:38 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_c3(t_list **stack)
{
	int	n;
	int	n_2;
	int	n_3;

	n = ft_atoi((*stack)->content);
	n_2 = ft_atoi((*stack)->next->content);
	n_3 = ft_atoi((*stack)->next->next->content);
	if (n == ft_stack_min(*stack) && n_2 == ft_stack_max(*stack))
	{
		ft_f_check(stack, 0, "sa", 1);
		ft_f_check(stack, 0, "ra", 1);
	}
	else if (n_2 == ft_stack_min(*stack) && n_3 == ft_stack_max(*stack))
		ft_f_check(stack, 0, "sa", 1);
	else if (n_2 == ft_stack_min(*stack) && n == ft_stack_max(*stack))
		ft_f_check(stack, 0, "ra", 1);
	else if (n_3 == ft_stack_min(*stack) && n_2 == ft_stack_max(*stack))
		ft_f_check(stack, 0, "rra", 1);
	else
	{
		ft_f_check(stack, 0, "sa", 1);
		ft_f_check(stack, 0, "rra", 1);
	}
}

void	ft_sort_arr(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		ft_f_check(stack, 0, "sa", 1);
	else if (ft_lstsize(*stack) == 3)
		ft_sort_c3(stack);
	else
		ft_sort_over3(stack);
	ft_sort_finish(stack);
}

void	ft_f_check(t_list **stack, t_list **stack_2, char *oper, int x)
{
	int		len;
	int		n;
	void	(*f)(t_list **, t_list **);

	len = ft_strlen(oper);
	n = ft_abs(x);
	if (!ft_strncmp(oper, "sa", len) || !ft_strncmp(oper, "sb", len)
		|| !ft_strncmp(oper, "ss", len))
		f = &ft_sf;
	else if (!ft_strncmp(oper, "pa", len) || !ft_strncmp(oper, "pb", len))
		f = &ft_pf;
	else if (!ft_strncmp(oper, "ra", len) || !ft_strncmp(oper, "rb", len)
		|| !ft_strncmp(oper, "rr", len))
		f = &ft_rf;
	else
		f = &ft_rrf;
	while (n--)
	{
		f(stack, stack_2);
		if (f != ft_pf && stack_2)
			f(stack_2, 0);
		if (x > 0)
			ft_putendl_fd(oper, 1);
	}
}
