/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:45:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/16 00:53:43 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(char *line, t_stack **a, t_stack**b, t_cmd **cmd)
{
	int		tmp_num;
	char	**strs;
	t_stack	*new_node;
	int		i;

	*a = 0;
	*b = 0;
	*cmd = 0;
	i = -1;
	strs = ft_split(line, ' '); // strs = ["1", "3", "4", "2"]}
	while (strs[++i])
	{
		tmp_num = atoi_and_nullck(strs[i]); // int로 변환해주고 만약 널이면 에러 출력
		new_node = create_node(tmp_num); // 변환된 int 를 노드(linkedList) 로 만들어줌
		append_new_node(a, new_node); // a 노드 꼬리에 new_node 를 연결해줌  1 <-> 3 <-> 4 <-> 2 <-> 1 (맨 마지막 2가 맨 처음 1과 연결되어 있는 형태)
		free(strs[i]); // str[i] 할당해제
		line++;
	}
	if (strs)
		free(strs); // str 할당해제
}

void	check_same_value(t_stack *a)
{
	t_stack	*tail;
	t_stack	*now;

	tail = a->next;
	now = a->prev;
	while (1) // 노드 하나씩 나머지 전부 노드를 돌면서 중복된 값이 있는지 확인
	{
		if (a == tail)
			break ;
		while (1)
		{
			if (now == tail->prev)
				break ;
			if (a->val == now->val)
				print_error();
			now = now->prev;
		}
		a = a->prev;
		now = a->prev;
	}
}

void	clear_lst(t_stack *stack_a)
{
	t_stack	*tmp;

	if (stack_a == NULL)
		return ;
	stack_a->next->prev = NULL;
	while (stack_a)
	{
		tmp = stack_a->prev;
		free(stack_a);
		stack_a = tmp;
	}
}
