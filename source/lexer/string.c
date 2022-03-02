/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:38:50 by soumanso          #+#    #+#             */
/*   Updated: 2022/03/02 15:51:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_token	*ft_lexer_skip_char(t_lexer *lexer, char c)
{
	t_token	*result;

	if (lexer->curr >= lexer->end)
		return (NULL);
	if (*(lexer->curr) != c)
		return (NULL);
	result = ft_lexer_push_token (lexer);
	if (!result)
		return (NULL);
	result->kind = TK_CHAR;
	result->c = c;
	result->str = lexer->curr;
	result->len = 1;
	lexer->curr += 1;
	return (result);
}

t_token	*ft_lexer_skip_quoted_str(t_lexer *lexer)
{
	t_token	*result;

	if (lexer->curr >= lexer->end)
		return (NULL);
	if (*(lexer->curr) != '\'' && *(lexer->curr) != '"')
		return (NULL);
	result = ft_lexer_push_token (lexer);
	if (!result)
		return (NULL);
	result->kind = TK_QUOTED_STR;
	result->quote = *(lexer->curr);
	lexer->curr += 1;
	result->str = lexer->curr;
	while (lexer->curr < lexer->end && *(lexer->curr) != result->quote)
		lexer->curr += 1;
	result->len = lexer->curr - result->str;
	if (*(lexer->curr) == result->quote)
		lexer->curr += 1;
	return (result);
}

t_token	*ft_lexer_skip_identifier(t_lexer *lexer)
{
	t_token	*result;

	if (lexer->curr >= lexer->end)
		return (NULL);
	if (*(lexer->curr) != '_' && !ft_is_alpha (*(lexer->curr)))
		return (NULL);
	result = ft_lexer_push_token (lexer);
	if (!result)
		return (NULL);
	result->kind = TK_IDENTIFIER;
	result->str = lexer->curr;
	while (lexer->curr < lexer->end && ft_is_alnum (*(lexer->curr)))
		lexer->curr += 1;
	result->len = lexer->curr - result->str;
	return (result);
}
