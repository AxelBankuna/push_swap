/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:25:11 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/01 18:21:04 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		checked(struct s_stack_a **top_a, struct s_sorted **top)
{
	struct s_stack_a	*temp_a;
	struct s_sorted		*temp_sorted;

	temp_a = *top_a;
	temp_sorted = *top;
	if (count_a(*top_a) < 1)
		return (0);
	while (temp_a->val != largest_val(&temp_a) &&
			temp_sorted->val != largest_val(&temp_a))
	{
		if (temp_a->val != temp_sorted->val)
			return (0);
		temp_a = temp_a->next;
		temp_sorted = temp_sorted->next;
	}
	if (temp_a->val != temp_sorted->val)
		return (0);
	return (1);
}

int		largest_val(struct s_stack_a **top)
{
	struct s_stack_a	*temp;
	int					val_temp;
	int					pos;
	int					variables;

	temp = *top;
	variables = 0;
	pos = 0;
	val_temp = temp->val;
	while (temp != NULL)
	{
		if (val_temp < temp->val)
		{
			val_temp = temp->val;
			pos = variables;
		}
		variables++;
		temp = temp->next;
	}
	return (val_temp);
}

int		*ready_b_(struct s_stack_b **top_b, int total, int holder, int *ret)
{
	struct s_stack_b	*temp_b;
	int					pos;

	pos = 0;
	temp_b = *top_b;
	while (temp_b->next != NULL)
	{
		temp_b = temp_b->next;
		total++;
	}
	temp_b = *top_b;
	while (holder != temp_b->val)
	{
		temp_b = temp_b->next;
		pos++;
	}
	if (pos <= total / 2)
		ret[0] = pos;
	else
	{
		pos = total - pos;
		ret[0] = pos;
		ret[1] = 1;
	}
	return (ret);
}
