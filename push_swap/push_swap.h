/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:02:43 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/05/31 20:16:01 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*prv;
	struct s_stack	*nxt;
}				t_stack;

int print_error();
int atoi_and_nullck(const char *str);
int get_len(char **av);

void	append_new_node(t_stack **stack, t_stack *node);
t_stack*	create_node(int num);

int is_decend(t_stack *a, int len);
int is_accend(t_stack *a, int len);

void reverse_stack(t_stack **a, t_stack **b, int len);
void sort_by_len(t_stack **a, t_stack **b, int len);

#endif