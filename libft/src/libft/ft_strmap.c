/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:58:07 by apieropa          #+#    #+#             */
/*   Updated: 2015/02/27 06:19:05 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*s2;

	s2 = ft_strdup(s);
	i = 0;
	while (s2[i] != '\0')
	{
		s2[i] = (*f)(s[i]);
		i++;
	}
	return (s2);
}
