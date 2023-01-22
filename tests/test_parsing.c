/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:15:06 by tmilcent          #+#    #+#             */
/*   Updated: 2023/01/22 18:33:39 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parsing.h"
#include <string.h>

void	test_count_unescaped_singlequote(char *line, int expected_result)
{
	if (count_unescaped_singlequote(line) == expected_result)
	{
		green();
		printf("OK : %s : result : %d\n", line, expected_result);
	}
	else
	{
		red();
		printf("KO : %s\nexpected : %d received : %d\n",
			line, expected_result, count_unescaped_singlequote(line));
	}
	reset_color();
}

void	test_count_unescaped_doublequote(char *line, int expected_result)
{
	if (count_unescaped_doublequote(line) == expected_result)
	{
		green();
		printf("OK : %s : result : %d\n", line, expected_result);
	}
	else
	{
		red();
		printf("KO : %s\nexpected : %d received : %d\n",
			line, expected_result, count_unescaped_doublequote(line));
	}
	reset_color();
}

void	test_sanitize_line(char *line, char *expected_result)
{
	char	*result;

	result = sanitize_line(line);
	if (strcmp(result, expected_result) == 0)
	{
		green();
		printf("OK : %s : result : %s\n", line, expected_result);
	}
	else
	{
		red();
		printf("KO : %s\nexpected : %s received : %s\n",
			line, expected_result, result);
	}
	reset_color();
	free(result);
}

int	main(void)
{
	printf("Tests count_unescaped_singlequote : \n");
	test_count_unescaped_singlequote("echo bonjour", 0);
	test_count_unescaped_singlequote("echo \"bonjour\"", 0);
	test_count_unescaped_singlequote("ec'ho' bonjour", 2);
	test_count_unescaped_singlequote("echo 'bonjour'", 2);
	test_count_unescaped_singlequote("echo 'bon'j'our'", 4);
	test_count_unescaped_singlequote("echo 'bon'jour'", 3);
	test_count_unescaped_singlequote("echo 'bon\\'jour'", 3);
	test_count_unescaped_singlequote("echo 'bon\"'j\"our'", 2);
	test_count_unescaped_singlequote("echo 'bon\"\\'j\"our'", 2);
	test_count_unescaped_singlequote("e'cho' '\"bon'j'our\"'", 6);

	printf("\n");
	printf("Tests count_unescaped_doublequote : \n");
	test_count_unescaped_doublequote("echo bonjour", 0);
	test_count_unescaped_doublequote("echo 'bonjour'", 0);
	test_count_unescaped_doublequote("ec\"ho\" bonjour", 2);
	test_count_unescaped_doublequote("echo \"bonjour\"", 2);
	test_count_unescaped_doublequote("echo \"bo\"nj\"our\"", 4);
	test_count_unescaped_doublequote("echo \"bon\"jour\"", 3);
	test_count_unescaped_doublequote("echo \"bon\\\"jour\"", 3);
	test_count_unescaped_doublequote("echo \"bon'\"'jour\"", 2);
	test_count_unescaped_doublequote("echo \"bon'\\\"j'our\"", 2);
	test_count_unescaped_doublequote("e'cho' '\"bon'j'our\"'", 0);
	test_count_unescaped_doublequote("e'cho' \"'bon\"j\"our'\"", 4);

	printf("\n");
	printf("Tests sanitize_line : \n");
	test_sanitize_line("echo bonjour", "echo bonjour");
	test_sanitize_line("echo \"bonjour\"", "echo bonjour");
	test_sanitize_line("echo 'bonjour'", "echo bonjour");
	test_sanitize_line("echo \"bon'j'our\"", "echo bon'j'our");
	test_sanitize_line("echo \"bon'j'our\"", "echo bon'j'our");
	test_sanitize_line("echo \"bon\"j\"our\"", "echo bonjour");
	test_sanitize_line("e'cho' \"bon'j'our\"", "echo bon'j'our");
	test_sanitize_line("e'cho' '\"bon'j'our\"'", "echo \"bonjour\"");
	test_sanitize_line("e\"cho\" \"'bon\"j\"our'\"", "echo 'bonjour'");
	test_sanitize_line("cat \"a\"\"b\"", "cat ab");

	printf("\n");
	printf("Tests parse_line : \n");
	t_node **test;
	char *line = "echo bonjour >hey >>hey2 >> hey3";
	printf("%s\n", line);
	test = parse_line(line);
	int i = -1;
	while (test[++i] != 0)
		print_node(*test[i]);
}