#include <stdio.h>

main () {
    int p;      // deklarer variablen p som kan lagre int. (heltall)
    p = fork();     // lager ny child process

    if(p == 0) {        // sjekker om det er child, fordi p = 0 betyr child
    printf("My PID is %d", getpid());       // hvis p = 0 (altså child), printer "getpid() is process id"
    exec("/bin/date");

    }


}