/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:47:15 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/07 12:47:21 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int ch)
{
	if (ch > 64 && ch < 91)
		return (1);
	if (ch > 96 && ch < 123)
		return (1);
	if (ch > 47 && ch < 58)
		return (1);
	return (0);
}
