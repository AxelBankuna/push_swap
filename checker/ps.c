/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:17:29 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/12 17:04:16 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ps.h"

int		main(int ac, char **av)
{
	head_a = NULL;
	head_b = NULL;
	head_s = NULL;
	head = NULL;
	if (ac > 1)
	{
		if (cleanmain(av) == 0)
			return (0);
		if (!insert_(&head_a, &head_s, av))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if ((head_a == NULL && ft_strlen(av[2]) > 0)
				|| checkdup(head_s))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		check(&head, &head_a, &head_b);
		checked(&head_a, &head_s) ? write(1, "OK\n", 3) :
			write(1, "KO\n", 3);
	}
	freecmd(&head);
	return (0);
}
