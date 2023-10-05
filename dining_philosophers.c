#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <unistd.h>




void napping(int t);

void* Philosopher(void *id);

int pickup_chopsticks(int id);

int putdown_chopsticks(int id);


static pthread_mutex_t chopsticks[5];


int main(int argc, char* argv[]){

    pthread_t philosophers[5];


    // Creates the Mutexes
    for (int i = 0; i < 5; i++){
        pthread_mutex_init(&chopsticks[i], NULL);
    }


    // Creates the Philosopher Threads
    for (int i = 0; i < 5; i++) {

        int *philosopher_id = (int *)malloc(sizeof(int));

        *philosopher_id = i;

        pthread_create(&philosophers[i], NULL, Philosopher, (void *)philosopher_id);
        
    }


    // Joins the Threads
    for (int i = 0; i < 5; i++) {

        pthread_join(philosophers[i], NULL);

    }
    return 0;

}

int pickup_chopsticks(int id) {
    
    if(id % 2 == 0){
        pthread_mutex_lock(&chopsticks[id]);
        printf("Philosopher %d picking up chopstick %d\n", id, id);
        fflush(stdout);

        pthread_mutex_lock(&chopsticks[(id + 1) % 5]);
        printf("Philosopher %d picking up chopstick %d\n", id, (id+1)%5);
        fflush(stdout);
    }
    else{
        pthread_mutex_lock(&chopsticks[(id + 1) % 5]);
        printf("Philosopher %d picking up chopstick %d\n", id, (id+1)%5);
        fflush(stdout);

        pthread_mutex_lock(&chopsticks[id]);
        printf("Philosopher %d picking up chopstick %d\n", id, id);
        fflush(stdout);
    }

    return 0;
}

int putdown_chopsticks(int id) {

    pthread_mutex_unlock(&chopsticks[id]);
    printf("Philosopher %d putting down chopstick %d\n", id, id);
    fflush(stdout);

    pthread_mutex_unlock(&chopsticks[(id + 1) % 5]);
    printf("Philosopher %d putting down chopstick %d\n", id, (id+1)%5);
    fflush(stdout);


    return 0;
}



void napping(int t){

    unsigned int seed = (unsigned int)t;
    int time = rand_r(&seed) % t+1;
    sleep(time);
}



void* Philosopher(void *id){
    
    int philosopher_id = *((int *)id);

    while(1){

        printf("Philosopher %d is thinking.\n", philosopher_id);
        fflush(stdout);

        napping(1);

        printf("Philosopher %d is hungry.\n", philosopher_id); 
        fflush(stdout);

        // Critical Section
        
        pickup_chopsticks(philosopher_id);

        printf("Philosopher %d is starting to eat.\n", philosopher_id);
        fflush(stdout);

        napping(2);

        putdown_chopsticks(philosopher_id);
        
        // End Critical Section

        printf("Philosopher %d is done eating.\n", philosopher_id);
        fflush(stdout);
    }

}


