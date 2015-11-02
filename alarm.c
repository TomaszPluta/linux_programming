#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void handle(int sig) {
    printf("tick - alarm rised\n");
    alarm(3); 
}

int main() {
    printf("My pid: %d", getpid()); //pront pid of that process
    signal(SIGALRM, handle); //connect signal with handle
    alarm(3);	//call system function "alarm"
    while(1);   //wait for [ctrl] + [c]
    return 0;
}

