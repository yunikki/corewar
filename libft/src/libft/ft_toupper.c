/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:43:35 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 14:59:52 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_toupper(int c)
{
	return (c >= 'a' && c <= 'z' ? c - 32 : c);
}
