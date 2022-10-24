/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:43:54 by sangyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:21:20 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define BUFFER_SIZE 5

int		main(int ac, char **ag);
void	ft_free(char **str);

int		ft_count_ag(char ***str, char **ag, char *sep);
int		ft_check_sign(char *str);
int		ft_overlap(int *arr, int len);
int		ft_error(char **str);

int		ft_sort_check(t_list *stack);
void	ft_sort_c3(t_list **stack);
void	ft_sort_arr(t_list **stack);
void	ft_f_check(t_list **stack, t_list **stack_2, char *oper, int x);

int		ft_idx_start_end(t_list *stack, int n);
int		ft_idx_middle(t_list *stack, int n);
void	ft_count_same(t_list **stack, t_list **stack_2, int a, int b);
void	ft_count_diff(t_list **stack, t_list **stack_2, int a, int b);
void	ft_search_min(t_list *stack, t_list *stack_2, int *a, int *b);

void	ft_sort_finish(t_list **stack);
void	ft_sort_over3(t_list **stack);

int		ft_abs(int n);
int		ft_min(int a, int b);
int		ft_stack_min(t_list *stack);
int		ft_stack_max(t_list *stack);

void	ft_sf(t_list **stack, t_list **stack_2);
void	ft_pf(t_list **stack, t_list **stack_2);
void	ft_rf(t_list **stack, t_list **stack_2);
void	ft_rrf(t_list **stack, t_list **stack_2);

int		ft_checker_error(void);
void	ft_sort_checker(t_list **stack);
int		ft_search_oper(char *str, t_list **stack, t_list **stack_2);
char	*get_next_line(char **str);
void	ft_checker_free(char **str);
#endif
