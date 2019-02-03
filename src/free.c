/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:36:36 by abukasa           #+#    #+#             */
/*   Updated: 2018/10/31 18:25:00 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	freenode_a(struct s_stack_a **head)
{
	struct s_stack_a	*temp;
	struct s_stack_a	*next_link;

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

void	freenode_s(struct s_sorted **head)
{
	struct s_sorted		*temp;
	struct s_sorted		*next_link;

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
