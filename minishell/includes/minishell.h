/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:21:18 by drosales          #+#    #+#             */
/*   Updated: 2024/12/09 11:58:43 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # ========== LIBRARIES ========== # 

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdint.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <dirent.h>
# include "libft.h"
# include "ft_printf.h"
# include "external_commands.h"

//# ========== DEFINES ========== #

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define OK 0
# define ERROR 1
# define BUFFER_SIZE 420
# define CMD_NOT_FOUND 127
# define IS_DIR 126
# define PERM_DENIED 126
# define LLONGMIN "-9223372036854775808"
# define LLONGMAX "9223372036854775807"
# define MAX_NEG 20
# define MAX_DIGITS 19

// # ========== DATA STRUCT ========== #

typedef enum s_err_msg
{
	ERR_MSG_COMMAND_NOT_FOUND,
	ERR_MSG_NO_SUCH_FILE,
	ERR_MSG_PERM_DENIED,
	ERR_MSG_TOO_MANY_ARGS,
	ERR_MSG_NUMBER_REQUIRED,
	ERR_MSG_SYNTAX_ERROR,
	ERR_MSG_INVALID_OPTION,
	ERR_MSG_NOT_A_DIRECTORY,
	ERR_MSG_FILE_EXISTS,
	ERR_MSG_ENV_VAR_NOT_FOUND,
	ERR_MSG_EXIT_TOO_MANY_ARGS,
	ERR_MSG_EXIT_NUMBER_REQUIRED
}	t_err_msg;

typedef struct s_signal
{
	pid_t	pid;
	int		sigint;
	int		sigquit;
	int		exit;
}	t_signal;

extern t_signal	g_signals;

typedef enum s_token_type
{
	TOKEN_EMPTY,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_APPEND,
	TOKEN_REDIRECT_HEREDOC,
	TOKEN_COMMAND,
	TOKEN_ARGUMENT,
	TOKEN_PIPE,
}	t_token_type;

typedef struct s_t_token
{
	t_token_type		token_type;
	char				*token_value;
	struct s_t_token	*next;
	struct s_t_token	*prev;
	int					double_quote;
	int					single_quote;
}	t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_mini
{
	char	**env;
	t_env	*list_env;
	t_env	*export_list;
	int		ministdin;
	int		ministdout;
	char	*line;
	t_token	*tokens;
	int		exit;
	int		final_status;
	int		redir_flag;
	int		redir_in_flag;
	int		heredoc_flag;
}	t_mini;

typedef struct s_ast
{
	t_token_type	type;
	char			*value;
	struct s_ast	*right;
	struct s_ast	*left;
	int				single_quote;
	int				double_quote;
}	t_ast;

typedef struct s_quote_info
{
	char	*line;
	char	quote_char;
	int		size;
	int		index;
	int		i;
}	t_quote_info;

//# ========== INIT, TOKENS, PARSING, AST ========== #//

//INIT MINSHELL

t_mini		*init_mini(char **env);

//INIT ENVIROPMENT

t_env		*init_env_list(char **envp);

//SIGNALS

void		sig_init(void);
void		init_signals(t_signal *signals);
void		sig_chld_handler(int signum);

//PARSING AST

t_ast		*ft_parsing_args(t_token *tokens);
t_ast		*ft_parsing_cmd(t_token *tokens, t_mini *mini);
t_ast		*ft_parsing_pipe(t_token *tokens, t_ast *left_cmd);
t_ast		*ft_parsing_redirect(t_token *tokens, t_ast *left_cmd);
t_ast		*ft_making_ast(t_token *tokens, t_mini *mini);
t_ast		*ft_ast_new_node(t_token_type type, char *value);
int			ft_is_command(char *value);
t_token		*ft_token_size(void);
char		*ft_size_token_value(char *line, int *index, t_token *token);
char		*ft_token_value(char *line, int *index, t_token *token);
char		*ft_find_cmd_in_current_directory(t_ast *cmd);
char		*ft_find_cmd_in_path(t_ast *cmd, char **dir);
char		*ft_get_path_from_env(t_env *env);
int			ft_read_and_validate_line(t_mini *minishell);
t_ast		*ft_process_tokens(t_mini *minishell);
void		ft_process_argument(char *value, t_mini *minishell);

//UTILS PARSING

int			ft_checker_sintaxys(t_token *tokens, t_mini *mini);
int			ft_is_operator(const char *token);

//PARSE BEFORE TOKEN

int			ft_check_operators(char *line, int index);
int			ft_checker_quotes_unclosed(t_mini *minishell);
int			ft_checker_quotes(char *line, int index);
void		ft_pass_spaces(char *line, int *i);
void		ft_update_type_tokens(t_token *token);
void		ft_empty_tok_out(t_token *tokens);
int			token_size(char *line, int *index);
t_token		*read_tokens(char *line, int *index);
t_token		*get_tokens(char *line);
t_ast		*ft_parse(t_mini *minishell);
int			ft_strcmp(const char *s1, const char *s2);

//EXE COMMANDS (AST)

void		ft_is_builtin(t_ast *cmd, t_mini *minishell);
int			ft_isspace(int c);

// # ========== BUILT IN ========= #

//CD

int			ft_cd(t_ast *cmd);
const char	*ft_get_cd_path(t_ast *cmd);
int			ft_chdirectory(const char *path);
int			ft_printf_current_cwd(const char *previous_cwd);
void		ft_update_env_vars(const char *oldpwd, char *cwd);

//PWD

int			ft_pwd(t_ast *cmd);

//CLEAR

int			ft_clear(t_ast *cmd);

//EXIT

int			ft_exit(t_ast *cmd, t_mini *minishell);
int			ft_checking_limits_long(char *input);
int			ft_exit_no_argument(t_mini *minishell);
int			ft_is_invalid_argument(t_ast *cmd, t_mini *minishell);
int			ft_check_too_many_args(t_ast *cmd, t_mini *minishell);
int			ft_checker_num(char *str);
int			ft_checking_limits_long(char *input);
int			ft_check_too_many_args(t_ast *cmd, t_mini *minishell);
int			ft_exit_no_argument(t_mini *minishell);
int			ft_is_invalid_argument(t_ast *cmd, t_mini *minishell);

//ENV

int			ft_env_cmd(t_ast *cmd, t_mini *minishell);
t_env		*new_node_env(char *key, char *path);
void		split_env_var(const char *env, char **key, char **path);
int			ft_count_env_nodes(t_env *env_list);
int			ft_str_env_len(char **env_array);
void		ft_print_env_array_sorted(char **env_array);
void		ft_sort_env_array(char **tab, int env_len);
char		**ft_env_to_array(t_env *env_list);
void		ft_update_env(t_mini *mini, t_ast *cmd);
//ECHO

int			ft_echo_cmd(t_ast *cmd, t_mini *minishell);
char		*ft_strndup(char *s, size_t n);
void		ft_process_argument(char *value, t_mini *minishell);
void		ft_handle_single_quotes(char *value, int *i);
void		ft_handle_double_quotes(char *value, int *i, t_mini *minishell);
void		ft_handle_variable_expansion(char *value,
				int *i, t_mini *minishell);
char		*ft_find_env_var(t_env *list_env, t_env *export_list, char *key);
void		ft_handle_normal_characters(char *value, int *i);

//UNSET && EXPORT

int			ft_unset_cmd(t_ast *cmd, t_mini *minishell);
int			ft_find_var(t_env *env, char *key);
int			ft_is_valid_env(char *str);
char		*ft_get_env_key(char *dest, char *src);
int			ft_update_env_key(t_env *env, char *key, char *value);
void		ft_env_add(t_env **env, char *key, char *value);
int			ft_export(t_ast *cmd, t_mini *minishell);

// # ========== EXTERNAL CMD ========== #

char		*ft_find_cmd_path(t_ast *cmd, t_mini *minishell);
char		**ft_ast_to_args(t_ast *cmd);
void		ft_redirect_out(t_ast *cmd, t_mini *mini);
void		ft_redirect_in(t_ast *cmd, t_mini *mini);
void		ft_redirect_append(t_ast *ast, t_mini *minishell);
void		ft_heredoc(t_ast *cmd, t_mini *mini);
void		ft_pipe(t_ast *cmd, t_mini *mini);
int			ft_check_redir(t_ast *cmd);
t_ast		*ft_type_of_redir(t_ast *cmd, t_mini *mini);
void		ft_execute_in(t_mini *mini, t_ast *cmd, int fd);
void		ft_execute_out(t_mini *mini, t_ast *cmd, int fd);
int			ft_check_path_errors(char *path_cmd,
				t_mini *mini, char **list_env, t_ast *cmd);
void		ft_reset_flags(t_mini *mini);

// # ========== ERROR HANDLER ========== #

char		*ft_get_error_message(t_err_msg error);
void		ft_close_fds(t_mini *mini);
void		ft_reset_std(t_mini *mini);
void		ft_close(int fd);
void		ft_reset_fds(t_mini *mini);
void		ft_free_2d_array(char **array);
void		ft_handle_exec_error(char *cmd_value);
int			ft_execute_fork(t_ast *cmd, t_mini *minishell, char **list_env);
void		ft_exec_ast(t_mini *minishell, t_ast *ast);
int			ft_verify_built_in(t_ast *cmd);

// # ========== FREE HANDLER ========== #

void		free_ast(t_ast *ast);
void		free_env(t_env *env);
void		free_mini(t_mini *mini);
void		free_tokens(t_token *tokens);
void		ft_free_env_node(t_env *head, char *key, char *value);
void		free_split(char **split);
void		free_env(t_env *env_list);
void		ft_free_three(char **args, char **list_env);
void		ft_init_external_commands_part8(void);
int			ft_is_commands(char *value);
void		init_external_commands(void);
void		ft_process_argument(char *value, t_mini *minishell);
int			*ft_status(t_mini *mini, int *i);
void		ft_handle_single_quotes(char *value, int *i);
void		ft_process_argument(char *value, t_mini *minishell);
int			ft_check_command_access(char *value);
void		ft_init_external_commands_part8(void);
int			ft_is_commands(char *value);
void		init_external_commands(void);
int			ft_is_invalid_export_format(char *input);

void		ft_execute_special_case(char *command, t_mini *minishell);
void		ft_free_node_env(t_env *node);
int			ft_str_longcheck(char *str);

int			ft_compare_to_limits(char *str);
void		ft_exit_no_arguments(t_mini *minishell);
void		ft_exit_invalid_argument(char *arg, t_mini *minishell);
int			ft_exit_too_many_arguments(t_mini *minishell);
void		ft_exit_check_limits(char *arg, t_mini *minishell);
#endif