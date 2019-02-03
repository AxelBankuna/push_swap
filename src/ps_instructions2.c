/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:22:11 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/05 11:33:04 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		ra(struct s_stack_a **head)
{
	struct s_stack_a	*temp;
	int					tempnum;

	if (count_a(*head) > 1)
	{
		temp = *head;
		tempnum = temp->val;
		while (temp->next != NULL)
		{
			temp->val = temp->next->val;
			temp = temp->next;
		}
		temp->val = tempnum;
		if (allinfo.print == 1)
			write(1, "ra\n", 3);
	}
}

void		rb(struct s_stack_b **head)
{
	struct s_stack_b	*temp;
	int					tempnum;

	if (count_b(*head) > 1)
	{
		temp = *head;
		tempnum = temp->val;
		while (temp->next != NULL)
		{
			temp->val = temp->next->val;
			temp = temp->next;
		}
		temp->val = tempnum;
		if (allinfo.print == 1)
			write(1, "rb\n", 3);
	}
}

void		rr(struct s_stack_a **head_a, struct s_stack_b **head_b)
{
	if (count_a(*head_a) > 1 && count_b(*head_b) > 1)
	{
		rr_a(head_a);
		rr_b(head_b);
		if (allinfo.print == 1)
			write(1, "rr\n", 3);
	}
}

void		rr_a(struct s_stack_a **head_a)
{
	struct s_stack_a	*tempa;
	int					tempnum;

	tempa = *head_a;
	tempnum = tempa->val;
	while (tempa->next != NULL)
	{
		tempa->val = tempa->next->val;
		tempa = tempa->next;
	}
	tempa->val = tempnum;
}

void		rr_b(struct s_stack_b **head_b)
{
	struct s_stack_b	*tempb;
	int					tempnum;

	tempb = *head_b;
	tempnum = tempb->val;
	while (tempb->next != NULL)
	{
		tempb->val = tempb->next->val;
		tempb = tempb->next;
	}
	tempb->val = tempnum;
}
