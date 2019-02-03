/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:27:18 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/01 17:02:38 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

struct s_stack_a	*remove_a(struct s_stack_a *head_a)
{
	struct s_stack_a	*temp;

	temp = head_a->next;
	if (count_a(head_a) > 1)
	{
		temp = head_a->next;
		temp->prev = NULL;
	}
	free(head_a);
	head_a = temp;
	return (head_a);
}

struct s_stack_b	*remove_b(struct s_stack_b *head_b)
{
	struct s_stack_b	*temp;

	temp = head_b->next;
	free(head_b);
	head_b = temp;
	return (head_b);
}

struct s_stack_b	*pb(struct s_stack_a **head_a, struct s_stack_b *head_b)
{
	if (count_a(*head_a) > 0)
	{
		head_b = load_b(head_b, (*head_a)->val);
		*head_a = remove_a(*head_a);
		if (allinfo.print == 1)
			write(1, "pb\n", 3);
	}
	return (head_b);
}

struct s_stack_a	*pa(struct s_stack_a *head_a, struct s_stack_b **head_b)
{
	if (count_b(*head_b) > 0)
	{
		head_a = a_load(head_a, (*head_b)->val);
		*head_b = remove_b(*head_b);
		if (allinfo.print == 1)
			write(1, "pa\n", 3);
	}
	return (head_a);
}

struct s_stack_a	*a_load(struct s_stack_a *head_a, int x)
{
	struct s_stack_a	*temp;
	struct s_stack_a	*newnode;

	newnode = createnode_a(x);
	temp = head_a;
	if (head_a == NULL)
	{
		head_a = newnode;
		return (head_a);
	}
	head_a->prev = newnode;
	newnode->next = head_a;
	head_a = newnode;
	return (head_a);
}
