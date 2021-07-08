/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:46:19 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/05 20:25:36 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*itog;
	int		i;
	int		len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	itog = (char *)malloc((len + 1) * sizeof(char));
	if (!itog)
		return (0);
	i = 0;
	while (i < len)
	{
		itog[i] = (*f)(i, s[i]);
		i++;
	}
	itog[len] = '\0';
	return (itog);
}
