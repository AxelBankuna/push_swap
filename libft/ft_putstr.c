/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:16:20 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/16 18:11:31 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		index;

	index = 0;
	if (!s)
		write(1, "", 0);
	else
	{
		while (s[index])
		{
			write(1, &s[index], 1);
			index++;
		}
	}
}
