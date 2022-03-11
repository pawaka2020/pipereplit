/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/03/03 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//#include <sys/types.h> 
#include <sys/wait.h> 

//find a string in envp that starts with PATH=
//then return the string but skipping PATH=
char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (0);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

//0 is stdin, 1 is stdout
//close and dup2 are absolutely essential and must be run wihin a child process.
void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	close(pipex.tube[0]);
	dup2(pipex.tube[1], 1);
	dup2(pipex.infile, 0);
	
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		exit(1);
	}
	//this function will then use pipex.infile since it has been swapped with stdin
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char *argv[], char *envp[])
{
	close(pipex.tube[1]);
	dup2(pipex.tube[0], 0);
	//close(pipex.tube[1]);
	dup2(pipex.outfile, 1);
	
	//close(pipex.tube[1]);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}



//splits the program into two child processes
void	startpipex(t_pipex *pipex, char **argv, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		first_child(*pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		second_child(*pipex, argv, envp);
}

//creates fd for infile and outfile
//finds path for commands(f)
int	ft_buildpipe(t_pipex *pipex, char **argv, char **envp)
{
	pipex->infile = open(argv[1], O_RDONLY);
	//0777, 0000644
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	pipex->paths = find_path(envp);
	pipex->cmd_paths = ft_split(pipex->paths, ':');
	return (pipe(pipex->tube));
}

//wait 
void	endpipex(t_pipex *pipex)
{
	close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	parent_free(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	
	if (argc != 5)
		ft_printerror("Error: insufficient parameters\n");
	if (!ft_buildpipe(&pipex, argv, envp))
	{
		startpipex(&pipex, argv, envp);
		endpipex(&pipex);
	}
	return (0);
}
