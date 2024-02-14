
// Please change the following into your name
// #0#BEGIN# DO NOT MODIFY COMMENT LINE!
// Avery
// Fox
// #0#END# DO NOT MODIFY COMMENT LINE!
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

// We need 5 different semaphores, because we use each semaphore value indicates
//the usage
// of each resource(chopstick). Initially, the semaphore value for each chopstick
//is 1.
// After using it, the value decrease 1 and becames 0.
// In other words, zero means chopstick currently is occupied and not available.
// We define a semaphore type array of total 5 chopsticks. (N=5):

int state[N];
int phil[N] = { 0, 1, 2, 3, 4 };

sem_t mutex;
sem_t S[N];

// Please define a new semaphore type single variable called m
// #1#BEGIN# DO NOT MODIFY COMMENT LINE!
// #1#END# DO NOT MODIFY COMMENT LINE!
// m indicates the total number of philosorphers are eating at the same time
// We have Philosopher Zero, Philosopher One, ..., Philosopher Four.
// The id of 5 philosophers stored in the integer array philosophers

void test(int phnum)
{
if (state[phnum] == HUNGRY
&& state[LEFT] != EATING
&& state[RIGHT] != EATING) {
// state that eating
state[phnum] = EATING;

sleep(2);

printf("Philosopher %d takes fork %d and %d\n",
phnum + 1, LEFT + 1, phnum + 1);

printf("Philosopher %d is Eating\n", phnum + 1);

// sem_post(&S[phnum]) has no effect
// during takefork
// used to wake up hungry philosophers
// during putfork
sem_post(&S[phnum]);
}
}

// take up chopsticks
void take_fork(int phnum)
{

sem_wait(&mutex);

// state that hungry
state[phnum] = HUNGRY;

printf("Philosopher %d is Hungry\n", phnum + 1);

// eat if neighbours are not eating
test(phnum);

sem_post(&mutex);

// if unable to eat wait to be signalled
sem_wait(&S[phnum]);

sleep(1);
}

// put down chopsticks
void put_fork(int phnum)
{

sem_wait(&mutex);

// state that thinking
state[phnum] = THINKING;

printf("Philosopher %d putting fork %d and %d down\n",
phnum + 1, LEFT + 1, phnum + 1);
printf("Philosopher %d is thinking\n", phnum + 1);

test(LEFT);
test(RIGHT);

sem_post(&mutex);
}

void* philosopher(void* num)
{

// left hand chopstick should be indexed as the id of the philosopher + 1
// it is also the right hand chopstick of the next philosopher sit after him
// if the value equals 5, the left hand chopsticks of the last philosopher
// also be the first philosopher's right hand chopsticks, because the table
// is round
// index left hand chopstick as the id of the philosopher + 1
// Note the value loop back to 0 when equals N. Consider use % operation.
// #2#BEGIN# DO NOT MODIFY COMMENT LINE!
// #2#END# DO NOT MODIFY COMMENT LINE!

while (1) {

int* i = num;

sleep(1);

take_fork(*i);

sleep(0);

put_fork(*i);
}
}

int main()
{

int i;
pthread_t thread_id[N];

// initialize the semaphores
sem_init(&mutex, 0, 1);

for (i = 0; i < N; i++)

sem_init(&S[i], 0, 0);

for (i = 0; i < N; i++) {

// create philosopher processes
pthread_create(&thread_id[i], NULL,
philosopher, &phil[i]);

// wait for the semaphore m first, make sure no more than 4 philosophers
// pick their first chopstick at the same time.
// after using it, the value will decrease 1
// THAT IS WHY use need to use &, because the semaphore need to be modifie

printf("Philosopher %d is thinking\n", i + 1);
}

// when any right chopstick been released,
// increase semaphore m to release one of capacity of philosophers eats
// at the same time
// please release one unit capacity of philosophers
// #4#BEGIN# DO NOT MODIFY COMMENT LINE!
// #4#END# DO NOT MODIFY COMMENT LINE!

// Use srand function to create dynamic random numbers
// based on time(NULL) function result.
// #5#BEGIN# DO NOT MODIFY COMMENT LINE!
// #5#END# DO NOT MODIFY COMMENT LINE!

// change your the following id into your banner id
// #6#BEGIN# DO NOT MODIFY COMMENT LINE!

int banner_id = 904188737;

// #6#END# DO NOT MODIFY COMMENT LINE!

// #7#BEGIN# DO NOT MODIFY COMMENT LINE!
// #7#END# DO NOT MODIFY COMMENT LINE!

// initialize the new semaphore m
// think what should be the initial value, and why?
// #8#BEGIN# DO NOT MODIFY COMMENT LINE!
// #8#END# DO NOT MODIFY COMMENT LINE!
// use pthread_create function to create threads

// #9#BEGIN# DO NOT MODIFY COMMENT LINE!
// #9#END# DO NOT MODIFY COMMENT LINE!

// also do not forgot to destroy the m semaphore
// #10#BEGIN# DO NOT MODIFY COMMENT LINE!
// #10#END# DO NOT MODIFY COMMENT LINE!

for (i = 0; i < N; i++)

pthread_join(thread_id[i], NULL);
}
