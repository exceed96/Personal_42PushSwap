/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:41:22 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:22:47 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_ag(char ***str, char **ag, char *sep)
{
	int		count;
	char	*str_ag;
	char	*tmp;

	str_ag = 0;
	count = 0;
	while (*ag)
	{
		if (!str_ag)
			str_ag = ft_strdup(*ag++);
		else
		{
			tmp = str_ag;
			str_ag = ft_strjoin(str_ag, sep);
			free(tmp);
			tmp = str_ag;
			str_ag = ft_strjoin(str_ag, *ag++);
			free(tmp);
		}
	}
	*str = ft_split(str_ag, *sep);
	free(str_ag);
	while ((*str)[count])
		count++;
	return (count);
}

int	ft_check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
		return (0);
	return (1);
}

int	ft_overlap(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error(char **str)
{
	int	i;
	int	j;
	int	ret;
	int	*arr;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (!ft_check_sign(str[i++]))
			return (ret);
	}
	arr = malloc(sizeof(int) * i);
	j = i;
	if (!arr)
		return (ret);
	while (i--)
		arr[i] = ft_atoi(str[i]);
	if (!ft_overlap(arr, j))
		ret = 1;
	free(arr);
	return (ret);
}
