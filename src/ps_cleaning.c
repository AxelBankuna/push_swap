/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cleaning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:28:41 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/07 18:18:27 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		cleanmain(char **av)
{
	int		number;
	int		index;

	number = 0;
	index = 0;
	while (av[1][index] != '\0')
	{
		if ((!(ft_isdigit(av[1][index]) || av[1][index] == '-') &&
					av[1][index] != ' ') || (av[1][index] == '-' &&
						!ft_isdigit(av[1][index + 1])))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (av[1][index] == ' ')
			number++;
		index++;
	}
	return (1);
}

int		ordered(struct s_stack_a *head_a)
{
	struct s_stack_a	*temp;

	temp = head_a;
	while (temp)
	{
		if (temp->next)
		{
			if (temp->val > temp->next->val)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

void	five(struct s_stack_a **head_a, struct s_stack_b **head_b,
		struct s_sorted *head_s)
{
	int		i;

	if (!(checked(head_a, &head_s)))
	{
		i = 2;
		five_(head_a, head_b, i);
		if (!ordered(*head_a))
			three(head_a, allinfo);
		pa(*head_a, head_b);
		pa(*head_a, head_b);
	}
}

void	five_(struct s_stack_a **head_a, struct s_stack_b **head_b, int i)
{
	int		dir;

	while (i--)
	{
		allinfo = smallest_a(*head_a, allinfo);
		if (allinfo.smallest_a_pos > count_a(*head_a) / 2)
		{
			allinfo.smallest_a_pos = count_a(*head_a) - allinfo.smallest_a_pos;
			dir = 1;
		}
		while ((allinfo.smallest_a_pos))
		{
			if (dir == 1)
				rra(head_a);
			else
				ra(head_a);
			allinfo.smallest_a_pos--;
		}
		*head_b = pb(head_a, *head_b);
	}
}
