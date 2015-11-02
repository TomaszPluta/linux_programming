#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void signal_handler (int sig_num){
	printf("cached signal %d\n", sig_num);
}


int main() {
    printf("My pid: %d\nYou can kill me from different console, I can't resist >>kill -9<< %d\n", getpid(), getpid());
    int sig_number;
    for (sig_number=0; sig_number <32; sig_number++){
    signal(sig_number, signal_handler);
    }
    while(1);
    printf("done\n");
    return 0;
}

