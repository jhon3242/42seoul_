/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:30:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/16 00:49:03 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_minmax(t_stack **a, t_stack **b, int min_val, t_cmd **cmd)
{
	if ((*b)->val == min_val) // b 에 있는애가 가장 작은 숫자면 그냥 a 로 보내기만하고
		do_op("pa", a, b, cmd);
	else // 제일 큰 숫자이면 a 로 보내고 ra 로 맨 아래로 보내버림
	{
		do_op("pa", a, b, cmd);
		do_op("ra", a, b, cmd);
	}
}

static void	sort_3(t_stack **a, t_stack **b, t_cmd **cmd)
{
	if ((*a)->val == get_min_val(*a)) // "1 4 3" 일때 a 가 1 인 경우 즉, 가장 작은 숫자인 경우
	{
		do_op("sa", a, b, cmd); // 4 1 3  (3 이 스택맨 아래임)
		do_op("ra", a, b, cmd); // 1 3 4
	}
	else if ((*a)->val == get_max_val(*a)) // "4 1 3" 일때 a 가 4와 같이 가장 큰 숫자인 경우
		do_op("ra", a, b, cmd); // 1 3 4 (4 가 스택 맨 아래임)
	else // "3 1 4" 와 같이 a 가 중간 값인 경우
	{
		if ((*a)->prev->val == get_min_val(*a)) // "3 1 4" 와 같이 a 다음에 오는 애가 제일 작은 숫자인 경우
			do_op("sa", a, b, cmd); // 1 3 4
		else // "3 4 1" 과 같은 경우
			do_op("rra", a, b, cmd); // 1 3 4
	}
}

static void	sort_4_5(t_stack **a, t_stack **b, t_cmd **cmd)
{
	int	min_val;
	int	max_val;
	int	pb_count;
								// 1 5 3 2 4 일 때
	min_val = get_min_val(*a); // 제일 큰 숫자  5
	max_val = get_max_val(*a); // 제일 작은 숫자   1
	pb_count = 0;
	while (get_stack_len(*a) > 3)
	{
		if ((*a)->val == min_val || (*a)->val == max_val) // a 가 제일 큰 숫자이거나 작은 숫자인 경우 b 스택에 보내버림
		{
			do_op("pb", a, b, cmd);
			pb_count++;
		}
		else // 아니면 그냥 ra 로 맨 위를 아래로 보내버려서 a를 바꿔버림 5 3 2 4 1 
			// 이렇게 바꾸면서 a 가 제일 큰 숫자나 작은 숫자가 올 때까지 반복
			do_op("ra", a, b, cmd);
	}
	// 제일 큰 숫자와 작은 숫자가 b 로 갔으니까 a 에는 3개만 있음
	if (is_decend(*a, 3))  
		reverse_stack(a, b, 3, cmd);
	else if (!is_accend(*a, 3))
		sort_3(a, b, cmd);
	while (pb_count-- > 0)
		sort_minmax(a, b, min_val, cmd); // b 에 있는 2개 숫자를 a 로 보낼때 처리하는 함수
}

void	sort_by_len(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	if (len == 3)
		sort_3(a, b, cmd); // a 에 있는 숫자가 3개인 경우
	else if (len == 4 || len == 5)
		sort_4_5(a, b, cmd);
	else
		a_to_b(a, b, len, cmd); // a 에 있는 애가 5개 보다 너 많이 있는 경우
}
