/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:14:05 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/13 15:14:05 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ps.h"

void				addcmd(struct s_commands **head, char *c)
{
	struct s_commands	*temp;
	struct s_commands	*newcmd;

	newcmd = (struct s_commands*)malloc(sizeof(struct s_commands));
	newcmd->next = NULL;
	newcmd->cmd = c;
	if (*head == NULL)
		*head = newcmd;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newcmd;
	}
}

void				check_(char *line, struct s_stack_a **head_a,
		struct s_stack_b **head_b)
{
	if (!strcmp(line, "sa"))
		sa(head_a);
	else if (!strcmp(line, "sb"))
		sb(head_b);
	else if (!strcmp(line, "ss"))
		ss(head_a, head_b);
	else if (!strcmp(line, "ra"))
		ra(head_a);
	else if (!strcmp(line, "rb"))
		rb(head_b);
	else if (!strcmp(line, "rr"))
		rr(head_a, head_b);
	else if (!strcmp(line, "rra"))
		rra(head_a);
	else if (!strcmp(line, "rrb"))
		rrb(head_b);
	else if (!strcmp(line, "rrr"))
		rrr(head_a, head_b);
	else if (!strcmp(line, "pa"))
		*head_a = pa(*head_a, head_b);
	else if (!strcmp(line, "pb"))
		*head_b = pb(head_a, *head_b);
	else
		write(1, "Invalid\n", 8);
}

void				check(struct s_commands **head, struct s_stack_a **head_a,
		struct s_stack_b **head_b)
{
	char				*line;

	*head = NULL;
	line = NULL;
	while (get_next_line(0, &line))
	{
		check_(line, head_a, head_b);
	}
}

void				freecmd(struct s_commands **head)
{
	struct s_commands	*temp;
	struct s_commands	*next_link;

	temp = *head;
	while (temp)
	{
		next_link = temp->next;
		temp->next = NULL;
		free(temp);
		temp = next_link;
	}
	*head = NULL;
}
