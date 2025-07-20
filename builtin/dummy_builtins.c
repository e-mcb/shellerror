#include "../includes/minishell.h"

void	dummy_exit(t_exec *tmp, t_shell *shell)
{
	if (!tmp->arr[1])
	{
		shell->exit_status = 0;
		return ;
	}
	else if (tmp->arr[1] && tmp->arr[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		shell->exit_status = 1;
		return ;
	}
	else if (!ft_is_number(tmp->arr[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(tmp->arr[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		shell->exit_status = 2;
		return ;
	}
	else if (ft_is_number(tmp->arr[1]))
	{
		shell->exit_status = ft_atoll(tmp->arr[1]) % 256;
		if (shell->exit_status < 0)
			shell->exit_status += 256;
		return ;
	}
}

