/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:10:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/12 17:05:31 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

struct s_stack_a	*createnode_a(int x)
{
	struct s_stack_a	*newnode;

	newnode = (struct s_stack_a*)malloc(sizeof(struct s_stack_a));
	newnode->val = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

struct s_stack_a	*load_a(struct s_stack_a *head, int x)
{
	struct s_stack_a	*t;
	struct s_stack_a	*newnode;

	newnode = (struct s_stack_a*)malloc(sizeof(struct s_stack_a));
	newnode->val = x;
	newnode->next = NULL;
	t = head;
	if (head == NULL)
	{
		newnode->prev = NULL;
		head = newnode;
		return (newnode);
	}
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = newnode;
		newnode->prev = t;
	}
	return (head);
}

struct s_stack_a	*receive_and_load(struct s_stack_a *head_a, char *av)
{
	int					index;
	int					int_len;
	char				*num_str;
	struct s_stack_a	*temp;

	index = 0;
	int_len = 0;
	while (av[index] != '\0')
	{
		if (index)
			index++;
		while (ft_isdigit(av[index]) || av[index] == '-')
		{
			int_len++;
			index++;
		}
		num_str = ft_strsub(av, index - int_len, int_len);
		if (check_max(num_str))
			head_a = load_a(head_a, ft_atoi(num_str));
		else
			return (NULL);
		movefree(&temp, head_a, num_str);
		int_len = 0;
	}
	return (head_a);
}

struct s_stack_b	*createnode_b(int x)
{
	struct s_stack_b	*newnode;

	newnode = (struct s_stack_b*)malloc(sizeof(struct s_stack_b));
	newnode->val = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

struct s_stack_b	*load_b(struct s_stack_b *head_b, int x)
{
	struct s_stack_b	*temp;
	struct s_stack_b	*newnode;

	newnode = createnode_b(x);
	temp = head_b;
	if (head_b == NULL)
	{
		head_b = newnode;
		return (head_b);
	}
	head_b->prev = newnode;
	newnode->next = head_b;
	head_b = newnode;
	return (head_b);
}
