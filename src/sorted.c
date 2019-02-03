/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:54:01 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/11 16:00:24 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int				asc(int a, int b)
{
	if (b < a)
		return (1);
	return (0);
}

struct s_sorted	*load_s(struct s_sorted *head_s, int nbr)
{
	t1_s = (struct s_sorted*)malloc(sizeof(struct s_sorted));
	t1_s->val = nbr;
	t1_s->next = NULL;
	if (head_s == NULL)
	{
		t1_s->prev = NULL;
		head_s = t1_s;
	}
	else
	{
		t2_s = head_s;
		while (t2_s->next != NULL)
			t2_s = t2_s->next;
		t2_s->next = t1_s;
		t1_s->prev = t2_s;
	}
	return (head_s);
}

struct s_sorted	*r_and_l_s(struct s_sorted *head_s, char *av)
{
	int				index;
	int				int_len;
	char			*num_str;
	struct s_sorted	*temp;

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
		head_s = load_s(head_s, ft_atoi(num_str));
		temp = head_s;
		free(num_str);
		int_len = 0;
	}
	arrange_s(head_s);
	return (head_s);
}

struct s_sorted	*arrange_s(struct s_sorted *head_s)
{
	int		tempnum;

	t1_s = head_s;
	while (t1_s->next != NULL)
	{
		if (asc(t1_s->val, t1_s->next->val))
		{
			tempnum = t1_s->val;
			t1_s->val = t1_s->next->val;
			t1_s->next->val = tempnum;
			t1_s = head_s;
		}
		else
			t1_s = t1_s->next;
	}
	return (head_s);
}

int				checkdup(struct s_sorted *head_s)
{
	t1_s = head_s;
	while (t1_s->next != NULL)
	{
		if (t1_s->val == t1_s->next->val)
			return (1);
		t1_s = t1_s->next;
	}
	return (0);
}
