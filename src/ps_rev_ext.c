/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 18:12:13 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/05 11:42:43 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void				rev1(struct s_stack_b **head_b)
{
	struct s_stack_b	*temp_b;

	temp_b = *head_b;
	allinfo.pos_b = 1;
	while (temp_b->val != allinfo.smallest_b)
	{
		allinfo.pos_b++;
		temp_b = temp_b->next;
	}
}

void				rev2(struct s_stack_b **head_b)
{
	struct s_stack_b	*temp_b;

	temp_b = *head_b;
	allinfo.pos_b = 0;
	while (temp_b->val != largest_b(&temp_b))
	{
		allinfo.pos_b++;
		temp_b = temp_b->next;
	}
}

void				rev3(struct s_stack_a *head_a, struct s_stack_b **head_b)
{
	struct s_stack_a	*temp_a;
	struct s_stack_b	*temp_b;

	temp_a = head_a;
	temp_b = *head_b;
	allinfo.pos_b = 1;
	temp_b = *head_b;
	while (temp_b->next != NULL)
	{
		if (temp_a->val < temp_b->val && temp_a->val > temp_b->next->val)
			break ;
		temp_b = temp_b->next;
		allinfo.pos_b++;
	}
	if (temp_b->next == NULL)
	{
		if (temp_a->val < temp_b->val && temp_a->val > (*head_b)->val)
			allinfo.pos_b = 0;
	}
}

void				move_a_ext(struct s_stack_a *temp_a,
		struct s_stack_a **head_a, struct s_stack_b **head_b)
{
	if (temp_a->direction_b == 1 && temp_a->rank_b > 0)
	{
		rrr(head_a, head_b);
		temp_a->rank_b--;
	}
	else
		rra(head_a);
}
