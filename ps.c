/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:17:29 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/11 11:59:21 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ps.h"

int		main(int ac, char **av)
{
	head_a = NULL;
	head_b = NULL;
	head_s = NULL;
	if (ac > 1)
	{
		if (cleanmain(av) == 0)
			return (0);
		insert(&head_a, &head_s, av);
		if ((head_a == NULL && ft_strlen(av[1]) > 0) || checkdup(head_s))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		allinfo.print = 1;
		sort(&head_a, &head_b, allinfo);
	}
	else
		write(1, "Error\n", 6);
	freenode_s(&head_s);
	freenode_a(&head_a);
	return (0);
}
