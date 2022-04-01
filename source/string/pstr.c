/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:34:13 by soumanso          #+#    #+#             */
/*   Updated: 2022/04/01 17:40:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pstr	pstr(t_str data, t_s64 len)
{
	t_pstr	res;

	res.data = data;
	res.len = len;
	return (res);
}

t_pcstr	pcstr(t_cstr data, t_s64 len)
{
	t_pcstr	res;

	res.data = data;
	res.len = len;
	return (res);
}
