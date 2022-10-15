/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:35:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/16 00:53:40 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;
	t_cmd	*last;

	tmp = (*cmd);
	last = (*cmd);
	ft_printf("%s\n", tmp->cmd);
	tmp = tmp->prev;
	free(last);
	while (tmp != (*cmd))
	{
		ft_printf("%s\n", tmp->cmd);
		last = tmp;
		tmp = tmp->prev;
		free(last);
	}
}

int	main(int ac, char **av)
{
	int		len;
	char	*line;
	t_stack	*a;
	t_stack	*b;
	t_cmd	*cmd;

	if (ac < 2)
		return (0);
	len = get_len(av) - 1; // 띄어쓰기 무시해서 순수 숫자가 몇개 오는지 확인 "./push_swap 1         2  4 5" 이렇게 오면 4 가 들어감
	line = get_line_num(ac, av); // 띄어쓰기 하나씩으로만 바꾸기 "1         2  4 5" -> "1 2 4 5"
	init_stack(line, &a, &b, &cmd);
	check_same_value(a); // 중복된 숫자 있는지 확인하고 있으면 에러 출력하고 종료
	if (len >= 2 && is_decend(a, len)) // 내림차순으로 되어 있으면 따로 처리 
		reverse_stack(&a, &b, len, &cmd);
	else if (len >= 3 && !is_accend(a, len)) // 숫자가 2개 이하인 경우는 "4 1" 과 같이 되어 있으면 어차피 위에서 걸림 "1 4" 이면 정렬할 필요 없음
		sort_by_len(&a, &b, len, &cmd); // 정렬해줘야 하는 경우
	if (cmd)
		zip_command(&cmd);
	if (cmd)
		print_cmd(&cmd);
	clear_lst(a);
	exit(0);
	return (0);
}
