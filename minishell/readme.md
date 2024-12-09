# Minishell

![Minishell](https://img.shields.io/badge/Minishell-42-blue.svg?style=flat-square)

## Descripción

**Minishell** es un proyecto desarrollado como parte del common core de la escuela 42, cuyo objetivo es construir una réplica simplificada de un shell de Unix. Este proyecto permite comprender mejor cómo funciona un intérprete de comandos, incluyendo la interacción con el sistema operativo y la ejecución de procesos.

El objetivo principal de **Minishell** es aprender sobre procesos, señales, tuberías, y otras características esenciales de los sistemas Unix.

## Características

- Interpretación de comandos básicos.
- Soporte para redirecciones (`>`, `<`, `>>`).
- Pipes (`|`) para combinar comandos.
- Variables de entorno (`env`, `$VAR`, etc.).
- Gestión de señales como `Ctrl+C`, `Ctrl+D`, y `Ctrl+\`.
- Implementación de built-ins:

  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`

## Requisitos

- Sistema operativo: Unix/Linux.
- Lenguaje: C.
- Cumple con la norma **Norminette** de la escuela 42.
- Uso limitado de funciones de biblioteca estándar (ver [man 3](https://man7.org/linux/man-pages/man3/)).

## Instalación


   ```bash
   1. git clone https://github.com/drosales96/minishell.git

   2. cd minishell

   3. make

   4. ./minishell

