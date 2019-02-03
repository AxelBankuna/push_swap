/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:44:01 by abukasa           #+#    #+#             */
/*   Updated: 2018/11/12 13:44:10 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	*ft_joining(int index, int s2_i, char const *s1, char const *s2)
{
	char	*str;

	str = NULL;
	if ((str = (char*)malloc(sizeof(*str) * (index))) == NULL)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	s2_i = 0;
	while (s2[s2_i])
	{
		str[index] = s2[s2_i];
		index++;
		s2_i++;
	}
	str[index] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		s2_i;

	s2_i = 0;
	index = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[index])
		index++;
	while (s2[s2_i])
	{
		index++;
		s2_i++;
	}
	if (index)
		index--;
	return (ft_joining(index, s2_i, s1, s2));
}
*/
char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*fresh;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (fresh == NULL)
		return (NULL);
	while (s1[i])
		fresh[j++] = s1[i++];
	i = 0;
	while (s2[i])
		fresh[j++] = s2[i++];
	fresh[j] = '\0';
	return (fresh);
}
