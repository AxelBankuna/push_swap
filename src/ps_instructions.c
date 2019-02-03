/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:11:44 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/05 11:31:51 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int				count_a(struct s_stack_a *head)
{
	struct s_stack_a	*temp;
	int					count;

	temp = head;
	count = 0;
	while (temp)
	{
		if (temp != NULL)
			count++;
		temp = temp->next;
	}
	return (count);
}

int				count_b(struct s_stack_b *head)
{
	struct s_stack_b	*temp;
	int					count;

	temp = head;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void			sa(struct s_stack_a **head)
{
	int		tempnum;

	if (count_a(*head) > 1)
	{
		tempnum = (*head)->val;
		(*head)->val = (*head)->next->val;
		(*head)->next->val = tempnum;
		if (allinfo.print == 1)
			write(1, "sa\n", 3);
	}
}

void			sb(struct s_stack_b **head)
{
	int		tempnum;

	if (count_b(*head) > 1)
	{
		tempnum = (*head)->val;
		(*head)->val = (*head)->next->val;
		(*head)->next->val = tempnum;
		if (allinfo.print == 1)
			write(1, "sb\n", 3);
	}
}

void			ss(struct s_stack_a **head_a, struct s_stack_b **head_b)
{
	int		tempnum;

	if (count_a(*head_a) > 1 && count_b(*head_b) > 1)
	{
		tempnum = (*head_a)->val;
		(*head_a)->val = (*head_a)->next->val;
		(*head_a)->next->val = tempnum;
		tempnum = (*head_b)->val;
		(*head_b)->val = (*head_b)->next->val;
		(*head_b)->next->val = tempnum;
	}
	if (allinfo.print == 1)
		write(1, "ss\n", 3);
}
