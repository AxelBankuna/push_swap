/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:44:15 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/12 17:03:33 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char	*ft_join(char const *s1, char const *s2)
{
	char		*fresh;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (fresh == NULL)
		return (NULL);
	while (s1 && s1[i])
		fresh[j++] = s1[i++];
	i = 0;
	while (s2[i])
		fresh[j++] = s2[i++];
	fresh[j] = '\0';
	return (fresh);
}

char	*onestring(char **av)
{
	int		i;
	char	*retstr;

	retstr = NULL;
	i = 1;
	while (av[i])
	{
		if (retstr)
		{
			free(retstr);
			retstr = ft_join(retstr, " ");
		}
		if (retstr)
			free(retstr);
		retstr = ft_join(retstr, av[i]);
		i++;
	}
	return (retstr);
}

void	insert(struct s_stack_a **head_a, struct s_sorted **head_s, char **av)
{
	char	*avstr;

	avstr = NULL;
	avstr = onestring(av);
	*head_s = r_and_l_s(*head_s, avstr);
	*head_a = receive_and_load(*head_a, avstr);
	free(avstr);
}

int		insert_(struct s_stack_a **head_a, struct s_sorted **head_s, char **av)
{
	char	*avstr;

	avstr = NULL;
	avstr = onestring(av);
	*head_s = r_and_l_s(*head_s, avstr);
	if ((*head_a = receive_and_load(*head_a, avstr)) == NULL)
		return (0);
	free(avstr);
	return (1);
}
