#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void signal_handler (int sig_num){
	printf("cached signal %d\n", sig_num);
}


int main() {
    printf("My pid: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    while(1);
    printf("done\n");
    return 0;
}

