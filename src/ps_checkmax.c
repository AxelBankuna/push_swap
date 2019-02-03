/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:55:14 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/13 15:03:39 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int					check_max(char *str)
{
	char	*newstr;
	long	val;

	newstr = NULL;
	if (str[0] == '-' && str[1])
	{
		newstr = ft_strdup(str + 1);
		val = ft_atoi_l(newstr);
		free(newstr);
		if (val > 2147483647)
			return (0);
	}
	else
	{
		val = ft_atoi_l(str);
		free(newstr);
	}
	if (val > 2147483647)
		return (0);
	return (1);
}

void				movefree(struct s_stack_a **temp,
		struct s_stack_a *head_a, char *num_str)
{
	*temp = head_a;
	free(num_str);
}
