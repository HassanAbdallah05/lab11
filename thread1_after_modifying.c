#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *printMessage(void *vargp){
    sleep(1);
    printf("This message is printed from the Thread\n");
    return NULL;
}

void *print_name(void *vargp){
    sleep(1);
    printf("Full Name: Hassan Mahmoud Abdalla\n");
    return NULL;
}

void *print_graduation_year(void *vargp){
    sleep(1);
    printf("Expected Graduation Year: 2028\n");
    return NULL;
}

int main(){
    pthread_t thread1, thread2, thread3;

    printf("This message is printed from the main program\n");

    pthread_create(&thread1, NULL, printMessage, NULL);
    pthread_create(&thread2, NULL, print_name, NULL);
    pthread_create(&thread3, NULL, print_graduation_year, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("After Threads\n");
    exit(0);
}
