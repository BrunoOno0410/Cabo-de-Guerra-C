// Bruno Giordano Ono
//  RA = 202120043

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define ARRAY_SIZE 75

char cabo[ARRAY_SIZE];
int posicao_atual;
pthread_mutex_t mutex;
pthread_t thread;
int q1, q2;
int p = 36;

void *proinicio(void *arg);
void *profim(void *arg);

int main(int argc, char **argv)
{
    srand48(time(0));
    q1 = 11 + (int)(drand48() * (23 - 11 + 1));
    q2 = 11 + (int)(drand48() * (23 - 11 + 1));

    for (int i = 0; i < 74; i++)
    {
        cabo[i] = '_';
        cabo[i + 1] = '\0';
    }

    cabo[p] = 'B';
    cabo[p + 1] = 'O';

    pthread_mutex_init(&mutex, NULL);

    int dif = 0;
    int q3 = q1;
    int q4 = q2;

    if (q1 >= q2)
    {
        dif = q1;
    }
    else
    {
        dif = q2;
    }

    while (dif > 0)
    {
        if (q1 > 0)
        {
            pthread_create(&thread, NULL, proinicio, NULL);
            q1--;
        }
        if (q2 > 0)
        {
            pthread_create(&thread, NULL, profim, NULL);
            q2--;
        }
        dif--;
    }

    while (1)
    {
        system("clear");
        printf("proinicio: %d\tprofim: %d\n", q3, q4);
        printf("%s\n", cabo);

        if (p + 1 == 73)
        {

            printf("\nProfim Venceu!\n");
            break;
        }
        else if (p == 0)
        {

            printf("\nProinicio Venceu!\n");
            break;
        }
        usleep(1000);
    }
    return 0;
}

void *proinicio(void *arg)
{
    long t;
    t = (long)(drand48() * 202120043 / 83.0);
    while (p != 0)
    {
        pthread_mutex_lock(&mutex);
        p--;

        cabo[p + 2] = '_';
        cabo[p] = 'B';
        cabo[p + 1] = 'O';

        pthread_mutex_unlock(&mutex);
        usleep(t);
    }
}

void *profim(void *arg)
{
    long t;
    t = (long)(drand48() * 202120043 / 83.0);
    while (p + 1 <= 73)
    {
        pthread_mutex_lock(&mutex);
        p++;

        cabo[p - 1] = '_';
        cabo[p] = 'B';
        cabo[p + 1] = 'O';

        pthread_mutex_unlock(&mutex);
        usleep(t);
    }
}