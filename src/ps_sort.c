/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:05:10 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/05 11:37:37 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		twonumbers(struct s_stack_a **head_a)
{
	struct s_stack_a	*temp;

	temp = *head_a;
	if (temp->val > temp->next->val)
		sa(head_a);
}

void		three(struct s_stack_a **head_a, struct s_info allinfo)
{
	struct s_stack_a	*temp_a;

	allinfo = largest_a(*head_a, allinfo);
	temp_a = *head_a;
	if (allinfo.largest_a_pos == 2)
	{
		if (temp_a->val > temp_a->next->val)
			sa(&temp_a);
	}
	else if (allinfo.largest_a_pos == 1)
	{
		rra(&temp_a);
		if (temp_a->val > temp_a->next->val)
			sa(&temp_a);
	}
	else if (allinfo.largest_a_pos == 0)
	{
		ra(head_a);
		if (temp_a->val > temp_a->next->val)
			sa(&temp_a);
	}
}

void		sort(struct s_stack_a **head_a, struct s_stack_b **head_b,
		struct s_info allinfo)
{
	if (count_a(*head_a) == 2)
		twonumbers(head_a);
	else if (count_a(*head_a) == 3)
		three(head_a, allinfo);
	else if (count_a(*head_a) == 5)
		five(head_a, head_b, head_s);
	else if (!checked(head_a, &head_s))
		lots(head_a, head_b);
}
