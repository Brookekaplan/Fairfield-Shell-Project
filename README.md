# Fairfield Shell Project

## Description
Fairfield Shell (fsh) is a simple Unix-like shell that mimics the behavior of a typical terminal. The user can run commands, navigate to files, and run basic built-in commands. The shell creates child processes to execute commands entered by the user.


This project shows an understanding of how a shell works, how processes are created, and how the command line enviroment operates. 
## Features

- Custom prompt (`fsh>`)
- Execute commands entered by the user (e.g., `ls`, `cat`, etc.)
- Support for the `exit` built-in command
- Support for the `cd` built-in command to change directories
- Error handling for invalid commands
- Simple and interactive command-line interface

## Installation

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/YourUsername/Fairfield-Shell-Project.git
    ```

2. Navigate to the project directory:

    ```bash
    cd Fairfield-Shell-Project
    ```

3. Compile the `fsh` shell:

    ```bash
    gcc -o fsh fsh.c
    ```

4. Run the shell:

    ```bash
    ./fsh
    ```

You should see the `fsh>` prompt ready to accept commands.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [Linux man pages](https://man7.org/linux/man-pages/)
- [Tutorial on writing a Unix shell](https://www.tutorialspoint.com/unix/unix-commands.htm)
