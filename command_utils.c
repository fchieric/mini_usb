/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:08:06 by fabi              #+#    #+#             */
/*   Updated: 2025/02/24 16:01:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_commands(t_command *cmd)
{
    t_command *next;

    while (cmd)
    {
        next = cmd->next;
        if (cmd->name)
            free(cmd->name);
        if (cmd->args)
            free_matrix(cmd->args);
        if (cmd->flags)
            free_matrix(cmd->flags);
        if (cmd->infile)
            free(cmd->infile);
        if (cmd->outfile)
            free(cmd->outfile);
        if (cmd->heredoc)
            free(cmd->heredoc);
        if (cmd->append)
            free(cmd->append);
        free(cmd);
        cmd = next;
    }
}