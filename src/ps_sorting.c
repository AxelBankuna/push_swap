/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:31:18 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/05 11:39:57 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void				rank_a(struct s_stack_a **head_a)
{
	struct s_stack_a	*temp;
	int					rank;

	temp = *head_a;
	rank = 0;
	while (temp)
	{
		temp->rank_a = rank;
		if (temp->rank_a > count_a(*head_a) / 2)
		{
			temp->rank_a = count_a(*head_a) - rank;
			temp->direction_a = 1;
		}
		temp = temp->next;
		rank++;
	}
}

void				rank_b(struct s_stack_a *temp_a, struct s_stack_b **head_b)
{
	struct s_stack_b	*temp_b;

	temp_b = *head_b;
	smallest_b(head_b);
	allinfo.pos_b = -1;
	if (temp_a->val < allinfo.smallest_b)
		rev1(head_b);
	else if (temp_a->val > largest_b(&temp_b))
		rev2(head_b);
	else if (allinfo.pos_b == -1)
		rev3(temp_a, head_b);
	if (allinfo.pos_b < (allinfo.count_b / 2) + 1)
		allinfo.direction = 0;
	else
	{
		allinfo.pos_b = allinfo.count_b - allinfo.pos_b;
		allinfo.direction = 1;
	}
	temp_a->direction_b = allinfo.direction;
	temp_a->rank_b = allinfo.pos_b;
}

void				rank(struct s_stack_a **head_a, struct s_stack_b **head_b)
{
	struct s_stack_a	*temp;

	rank_a(head_a);
	temp = *head_a;
	while (temp)
	{
		rank_b(temp, head_b);
		temp = temp->next;
	}
	temp = *head_a;
	while (temp)
	{
		temp->rank = temp->rank_a + temp->rank_b;
		temp = temp->next;
	}
}

struct s_stack_a	*select_a(struct s_stack_a **head)
{
	struct s_stack_a	*temp;
	struct s_stack_a	*hold;
	int					temp_rank;
	int					j;

	temp = *head;
	hold = temp;
	temp_rank = temp->rank;
	while (temp)
	{
		if (temp->rank < temp_rank)
		{
			j = temp_rank;
			hold = temp;
			temp_rank = temp->rank;
		}
		temp = temp->next;
	}
	return (hold);
}

struct s_stack_a	*move_a(struct s_stack_a **head_a,
		struct s_stack_b **head_b)
{
	struct s_stack_a	*temp_a;

	rank(head_a, head_b);
	temp_a = select_a(head_a);
	while (temp_a->rank_a > 0)
	{
		if (temp_a->direction_a == 0)
		{
			if (temp_a->direction_b == 0 && temp_a->rank_b > 0)
			{
				rr(head_a, head_b);
				temp_a->rank_b--;
			}
			else
				ra(head_a);
		}
		else
		{
			move_a_ext(temp_a, head_a, head_b);
		}
		temp_a->rank_a--;
	}
	return (*head_a);
}
