/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:03:18 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:22:02 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_search_oper(char *str, t_list **stack, t_list **stack_2)
{
	int	(*f)(const char *, const char *, size_t);
	int	len;

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (ft_checker_error());
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 2 && (!f(str, "sa", 2) || !f(str, "ra", 2)))
		|| (len == 3 && !f(str, "rra", 3)))
		ft_f_check(stack, 0, str, -1);
	else if ((len == 2 && (!f(str, "sb", 2) || !f(str, "rb", 2)))
		|| (len == 3 && !f(str, "rrb", 3)))
		ft_f_check(stack_2, 0, str, -1);
	else if ((len == 2 && (!f(str, "ss", 2) || !f(str, "rr", 2)
				|| !f(str, "pb", 2))) || (len == 3 && !f(str, "rrr", 3)))
		ft_f_check(stack, stack_2, str, -1);
	else if (!f(str, "pa", 2))
		ft_f_check(stack_2, stack, str, -1);
	else
		return (ft_checker_error());
	return (0);
}

void	ft_sort_checker(t_list **stack)
{
	t_list		*stack_2;
	char		*oper;
	static char	*str;

	stack_2 = 0;
	while (1)
	{
		oper = get_next_line(&str);
		if (!ft_strlen(oper) || !oper)
		{
			free(oper);
			break ;
		}
		if (ft_search_oper(oper, stack, &stack_2))
		{
			free(str);
			free(oper);
			return ;
		}
		free(oper);
	}
	if (ft_sort_check(*stack) && !ft_lstsize(stack_2))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
