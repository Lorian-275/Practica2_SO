#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("Error al leer el comando.\n");
            continue;
        }

        // Elimina el salto de línea al final del comando
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "EXIT") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == -1) {
            printf("Error al crear el proceso hijo.\n");
            continue;
        }

        if (pid == 0) {
            // El proceso hijo ejecuta el comando
            if (execlp(command, command, NULL) == -1) {
                printf("Error al ejecutar el comando.\n");
                exit(1);
            }
        } else {
            // El proceso padre espera a que el hijo termine
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                if (WEXITSTATUS(status) == 0) {
                    printf("Comando ejecutado correctamente.\n");
                } else {
                    printf("Error en la ejecución del comando.\n");
                }
            }
        }
    }

    return 0;
}


