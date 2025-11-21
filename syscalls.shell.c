#include <stdio.h>

int main(void) {
while (1) {
char command[1024];
printf("Enter a command: ");
fgets(command, 1024, stdin);

// Remove newline character
command[strcspn(command, "\n")] = 0;

// Check if the user wants to exit
if (strcmp(command, "exit") == 0) {
break;
}

// execute the command in a new process,
// wait for it to finish
}
return 0;
}
