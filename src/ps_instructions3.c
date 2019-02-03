/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:43:50 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/05 11:34:28 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		rra(struct s_stack_a **head)
{
	struct s_stack_a	*temp;
	int					tempnum;

	if (count_a(*head) > 1)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		tempnum = temp->val;
		while (temp->prev != NULL)
		{
			temp->val = temp->prev->val;
			temp = temp->prev;
		}
		temp->val = tempnum;
		if (allinfo.print == 1)
			write(1, "rra\n", 4);
	}
}

void		rrb(struct s_stack_b **head)
{
	struct s_stack_b	*temp;
	int					tempnum;

	if (count_b(*head) > 1)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		tempnum = temp->val;
		while (temp->prev != NULL)
		{
			temp->val = temp->prev->val;
			temp = temp->prev;
		}
		temp->val = tempnum;
		if (allinfo.print == 1)
			write(1, "rrb\n", 4);
	}
}

void		rrr(struct s_stack_a **head_a, struct s_stack_b **head_b)
{
	if (count_a(*head_a) > 1 && count_b(*head_b) > 1)
	{
		rrr_a(head_a);
		rrr_b(head_b);
	}
	if (allinfo.print == 1)
		write(1, "rrr\n", 4);
}

void		rrr_a(struct s_stack_a **head_a)
{
	struct s_stack_a	*temp_a;
	int					tempnum;

	temp_a = *head_a;
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	tempnum = temp_a->val;
	while (temp_a->prev != NULL)
	{
		temp_a->val = temp_a->prev->val;
		temp_a = temp_a->prev;
	}
	temp_a->val = tempnum;
}

void		rrr_b(struct s_stack_b **head_b)
{
	struct s_stack_b	*temp_b;
	int					tempnum;

	temp_b = *head_b;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	tempnum = temp_b->val;
	while (temp_b->prev != NULL)
	{
		temp_b->val = temp_b->prev->val;
		temp_b = temp_b->prev;
	}
	temp_b->val = tempnum;
}
