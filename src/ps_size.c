/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:54:45 by abukasa           #+#    #+#             */
/*   Updated: 2018/09/14 17:36:38 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

struct s_info	largest_a(struct s_stack_a *head, struct s_info allinfo)
{
	struct s_stack_a		*temp;
	static struct s_info	temp_info;
	int						val_temp;
	int						pos;
	int						variables;

	temp = head;
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
	allinfo.largest_a_pos = pos;
	allinfo.largest_a = val_temp;
	temp_info = allinfo;
	return (temp_info);
}

void			smallest_b(struct s_stack_b **top_b)
{
	struct s_stack_b	*temp;
	int					val_temp;
	int					pos;
	int					variables;

	temp = *top_b;
	variables = 0;
	pos = 0;
	val_temp = temp->val;
	while (temp != NULL)
	{
		if (val_temp > temp->val)
		{
			val_temp = temp->val;
			pos = variables;
		}
		variables++;
		temp = temp->next;
	}
	allinfo.smallest_b = val_temp;
	allinfo.count_b = variables;
}

int				largest_b(struct s_stack_b **top_b)
{
	struct s_stack_b	*temp;
	int					val_temp;
	int					pos;
	int					variables;

	temp = *top_b;
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
	allinfo.largest_b = val_temp;
	allinfo.largest_b_pos = pos;
	allinfo.count_b = count_b(head_b);
	return (val_temp);
}

struct s_info	smallest_a(struct s_stack_a *head, struct s_info allinfo)
{
	struct s_stack_a		*temp;
	static struct s_info	temp_info;
	int						val_temp;
	int						pos;
	int						variables;

	temp = head;
	variables = 0;
	pos = 0;
	val_temp = temp->val;
	while (temp != NULL)
	{
		if (val_temp > temp->val)
		{
			val_temp = temp->val;
			pos = variables;
		}
		variables++;
		temp = temp->next;
	}
	allinfo.smallest_a_pos = pos;
	allinfo.smallest_a = val_temp;
	temp_info = allinfo;
	return (temp_info);
}
