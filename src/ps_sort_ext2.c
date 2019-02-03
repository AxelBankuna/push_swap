/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_ext2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:20:54 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/05 11:39:11 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

struct s_stack_b	*revolver(struct s_stack_a **head_a,
		struct s_stack_b **head_b)
{
	struct s_stack_a	*temp_a;
	struct s_stack_b	*temp_b;

	temp_a = *head_a;
	temp_b = *head_b;
	smallest_b(head_b);
	allinfo.pos_b = -1;
	if (temp_a->val < allinfo.smallest_b)
		rev1(head_b);
	else if (temp_a->val > largest_b(&temp_b))
		rev2(head_b);
	else if (allinfo.pos_b == -1)
		rev3(*head_a, head_b);
	if (allinfo.pos_b < (allinfo.count_b / 2) + 1)
		allinfo.direction = 0;
	else
	{
		allinfo.pos_b = allinfo.count_b - allinfo.pos_b;
		allinfo.direction = 1;
	}
	return (*head_b);
}

void				lots(struct s_stack_a **head_a, struct s_stack_b **head_b)
{
	*head_b = pb(head_a, *head_b);
	*head_b = pb(head_a, *head_b);
	while (*head_a != NULL)
	{
		rank(head_a, head_b);
		*head_a = move_a(head_a, head_b);
		*head_b = revolver(head_a, head_b);
		while (allinfo.pos_b > 0)
		{
			if (allinfo.direction == 0)
				rb(head_b);
			else
			{
				rrb(head_b);
			}
			allinfo.pos_b--;
		}
		*head_b = pb(head_a, *head_b);
	}
	ready_b(head_b);
	while (*head_b != NULL)
		*head_a = pa(*head_a, head_b);
}

void				ready_b(struct s_stack_b **head_b)
{
	largest_b(head_b);
	if (allinfo.largest_b_pos <= allinfo.count_b / 2)
		allinfo.ready_dir = 0;
	else
	{
		allinfo.ready_dir = 1;
		allinfo.largest_b_pos = allinfo.count_b - allinfo.largest_b_pos;
	}
	while (allinfo.largest_b_pos)
	{
		if (allinfo.ready_dir == 0)
			rb(head_b);
		else
			rrb(head_b);
		allinfo.largest_b_pos--;
	}
}
