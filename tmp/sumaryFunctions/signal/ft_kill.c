/* 
 * kill 
 * Send dignal to a process
 *
 * Header: signal.h
 * Prototype: int	kill(pid_t pid, int sig)
 *
 * pid -> (pid_t == int): Process ID number
 * sig -> Signal like SIGUSR1, SIGINT, SIGHUP...
 *
 * Return: Return 0 in success case or -1 in error and errno will be setted
 */

int	ft_kill(pid_t pid, int sig)
{
	return (kill(pid, sig));
}

