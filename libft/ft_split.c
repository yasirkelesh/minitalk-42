/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:56:21 by mukeles           #+#    #+#             */
/*   Updated: 2022/02/15 10:56:25 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cwords(const char *s, char c)
{
	int	rtn;

	rtn = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		rtn += *s != 0;
		s = ft_strchr(s, c);
	}
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**rtn;
	int		i;
	size_t	len;

	if (!s)
		return (NULL);
	words = cwords(s, c);
	rtn = malloc((words + 1) * sizeof(char *));
	if (!rtn)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = ft_strchr(s, c) - s;
		rtn[i] = ft_substr(s, 0, len);
		s += len;
		if (!rtn[i++])
			return (0);
	}
	rtn[i] = 0;
	return (rtn);
}

/*#include <stdio.h>
int main(){
	char str[100] = "elma,armut,karpuz";
	char **p = ft_split(str, ',');
	printf("%s\n%s\n%s\n", p[0],p[1],p[2]);
}*/
