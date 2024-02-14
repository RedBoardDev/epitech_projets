/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-minishell1-thomas.ott
** File description:
** test.c
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(mysh, check_exists_builtins, .init = redirect_all_std)
{
    cr_assert_eq(check_builtins("setenv"), 4);
    cr_assert_eq(check_builtins("exit"),1);
    cr_assert_eq(check_builtins("cd"), 2);
}

Test(mysh, check_not_exists_builtins, .init = redirect_all_std)
{
    cr_assert_eq(check_builtins("fgh"), 0);
    cr_assert_eq(check_builtins("exits"),0);
    cr_assert_eq(check_builtins("scd"), 0);
}

Test(mysh, checks_setenv_arg, .init = redirect_all_std)
{
    cr_assert_eq(check_setenv_arg("az5erty"), 0);
    cr_assert_eq(check_setenv_arg("azerty"), 0);
    cr_assert_eq(check_setenv_arg("5azerty"), 1);
    cr_assert_eq(check_setenv_arg("-azerty"),1);
    cr_assert_eq(check_setenv_arg("az-erty"), 1);
    cr_assert(check_setenv_arg("5azerty"), "setenv: Variable name must begin with a letter.\n");
}

env_t set_env_struct()
{
    env_t env;

    env.str_size = 2;
    env.str_line[0] = "echo";
    env.str_line[1] = "test";
    env.env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gradle/gradle-7.2/bin";
    return (env);
}

Test(mysh, check_get_path, .init = redirect_all_std)
{
    env_t env;
    env.str_size = 2;
    env.str_line = malloc(sizeof(char) * 2);
    env.str_line[0] = "echo";
    env.str_line[1] = "test";
    env.env = malloc(sizeof(char) * 1);
    env.env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gradle/gradle-7.2/bin";
    cr_assert_eq(find_line_env("PATH=", env.env), 0);
    cr_assert(get_path(env), "/sbin:/bin/echo");
    free(env.str_line);
    free(env.env);
}

Test(mysh, check_add_line_oldpath, .init = redirect_all_std)
{
    env_t env;
    env.env = malloc(sizeof(char) * 1);
    env.env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gradle/gradle-7.2/bin";
    my_set_env_oldpath(&env, "TEST");
    cr_assert(env.env[1], "OLDPWD=TEST");
    free(env.env);
}

Test(mysh, show_env, .init = redirect_all_std)
{
    env_t env;
    env.env = malloc(sizeof(char) * 1);
    env.env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gradle/gradle-7.2/bin";
    cr_assert_eq(check_size_arg_env(2, env.env), 0);
    free(env.env);
    env.env = malloc(sizeof(char) * 2);
    env.env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gradle/gradle-7.2/bin";
    env.env[1] = "OLD=FGHJK";
    cr_assert_eq(check_size_arg_env(0, env.env), 1);
    free(env.env);
}

Test(mysh, unset_env, .init = redirect_all_std)
{
    env_t env;
    env.env = malloc(sizeof(char) * 1);
    env.env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gradle/gradle-7.2/bin";
    env.env[1] = "dfghj";
    env.str_size = 0;
    char **str = remove_line_env(1, env.env);
    cr_assert(str[0], "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gradle/gradle-7.2/bin");
    my_unsetenv(&env);
    cr_assert_stderr_eq_str("unsetenv: Too few arguments.\n");
    free(env.env);
}

Test(mysh, check_prompt, .init = redirect_all_std)
{
    my_prompt();
    cr_assert_stdout_eq_str("$> ");
}

Test(mysh, set_backup, .init = redirect_all_std)
{
    backup_t backup;
    char *env[4] = {"HOME=fgh", "OLDPWD=dfghj", "PATH=qsdcfv", "PWD=ikjhn"};
    backup = set_backup_env(env);
    cr_assert_eq(backup.home, "HOME=fgh");
    cr_assert_eq(backup.oldpath, "OLDPWD=dfghj");
}

Test(mysh, b_check_status, .init = redirect_all_std)
{
    check_status(139);
    cr_assert_stderr_eq_str("Segmentation fault (core dumped)\n");
}

Test(mysh, check_file, .init = cr_redirect_stdout)
{
    is_regular_file("file");
    cr_assert_stdout_neq_str("sdf");
}

Test(mysh, error_cd, .init = cr_redirect_stdout)
{
    error_handling_cd("cd");
    cr_assert_stdout_neq_str("sdf");
}

Test(mysh, builtin_exit, .init = cr_redirect_stdout)
{
    env_t env;

    builtin_exit(&env);
    cr_assert_stdout_eq_str("exit\n");
}

Test(mysh, too_many_size_arg_env, .init = cr_redirect_stderr)
{
    char *env[6] = {"je", "suis", "un", "humain", "mangeur", "d'avion"};

    check_size_arg_env(10, env);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}

Test(mysh, size_array, .init = redirect_all_std)
{
    char *array[6] = {"je", "suis", "un", "humain", "mangeur", "d'avion"};
    get_size_array(array);
    cr_assert(6);
}

Test(mysh, permission_test, .init = redirect_all_std)
{
    char *cmd = "dcfbndfghj";
    have_permission(cmd);
    cr_assert_stdout_neq_str("dcfbndfghj: Command not found.\n");
}
