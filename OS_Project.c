#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *reader(void *arg);
void *writer(void *arg);
sem_t mutex,wrt;
int rc=0,data=0;
int main()
{
int i,p;
pthread_t rtid[5],wtid[5];
sem_init(&mutex,0,1);
sem_init(&wrt,0,1);
for(i=0;i<2;i++)
{
pthread_create(&wtid[i],NULL,writer,(void *)i);
pthread_create(&rtid[i],NULL,reader,(void *)i);
}
for(i=0;i<2;i++)
{
pthread_join(wtid[i],NULL);
pthread_join(rtid[i],NULL);
}
  return 0;
}
void *writer(void *arg)
{
int f;
f=(int)arg;
sem_wait(&wrt);
data++'
printf("\nData written by writer is %d",data);
sleep(1);
sem_post(&wrt);
}
