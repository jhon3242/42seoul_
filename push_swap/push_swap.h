/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:02:43 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/01 23:41:55 by wonjchoi         ###   ########.fr       */
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

typedef struct s_info
{
	int	idx_pvt_less;
	int	idx_pvt_greater;
	int	pvt_less;
	int	pvt_greater;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;
	int	cnt_pb;
}				t_info;

/* push_swap.c
## =====================================================
*/
int			print_error();
int			atoi_and_nullck(const char *str);
int			get_len(char **av);

/* push_swap_node.c
## =====================================================
*/
t_stack*	create_node(int num);
void		append_new_node(t_stack **stack, t_stack *node);

/* push_swap_stack.c
## =====================================================
*/
int 		is_decend(t_stack *a, int len);
int 		is_accend(t_stack *a, int len);
void 		reverse_stack(t_stack **a, t_stack **b, int len);
t_stack		*pop_node(t_stack **a);
int			push_node(t_stack **dst, t_stack *src);

/* push_swap_sort.c
## =====================================================
*/
void sort_by_len(t_stack **a, t_stack **b, int len);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);

/* push_swap_do_op.c
## =====================================================
*/
void do_op(char	*op, t_stack **a, t_stack **b);
void both_rroll(t_stack **a, t_stack **b, int len);

/* push_swap_sort_utile.c
## =====================================================
*/
int get_min_val(t_stack *a);
int get_max_val(t_stack *a);
int	get_stack_len(t_stack *a);


/* push_swap_pivot.c
## =====================================================
*/
void set_pivot(t_stack *a, int len, char target_stack, t_info *info);

/* push_swap_a_to_b.c
## =====================================================
*/
void	a_to_b(t_stack **a, t_stack **b, int len);

/* push_swap_b_to_a.c
## =====================================================
*/
void b_to_a(t_stack **a, t_stack **b, int len);

#endif