#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "/Kardaiev"

int main(int argc, char **argv)
{
    sem_t *sem;
    if (argc != 2)
    {
        if ((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED)
        {
            fprintf(stderr, "ERROR while opening Kardaievs semaphore!");
            return 1;
        }
        printf("Kardaievs semaphore is opened and taken.\nwaiting for it to be dropped.\n");
        if (sem_wait(sem) < 0)
            fprintf(stderr, "ERROR while waiting for Kardaievs semaphore!");
        if (sem_close(sem) < 0)
            fprintf(stderr, "ERROR while closing Kardaievs semaphore! ");
        return 0;
    }
    else
    {
        printf("Dropping Kardaievs semaphore...\n");
        if ((sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED)
        {
            fprintf(stderr, "ERROR while opening Kardaievs semaphore!");
            return 1;
        }
        sem_post(sem);
        printf(" Kardaievs semaphore dropped and posted. \n");
        return 0;
    }
}