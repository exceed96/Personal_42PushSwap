/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:45:18 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:29:44 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_checker_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

void	ft_checker_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_argu_check(char **str, int i)
{
	while (i--)
	{
		if (!ft_strlen(str[i]))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **ag)
{
	int		count;
	t_list	*stack;
	char	**str;

	str = 0;
	stack = 0;
	if (ac > 1)
	{
		if (!ft_argu_check(ag, ac))
			return (1);
		count = ft_count_ag(&str, ag + 1, " ");
		if (!count || !ft_error(str))
		{
			ft_checker_free(str);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		while (count--)
			ft_lstadd_front(&stack, ft_lstnew(str[count]));
		ft_sort_checker(&stack);
		ft_lstclear(&stack, free);
		free(str);
	}
	return (0);
}
