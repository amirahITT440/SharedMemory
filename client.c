#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 50

int main(int args, char *argc[])
{
	int shmid;
	key_t key ;
	char *shm;
	char *s;

	key = 5510;

	shmid = shmget(key, SHSIZE, 0666);

	if(shmid < 0)
	{
		perror("shmget");
		exit(1);
	}

	shm = shmat(shmid, NULL, 0);

	if(shm == (char *) -1)
	{
		perror("shmat");
		exit(1);
	}

	for(s = shm; *s != 0; s++)
		printf("%c", *s);

	printf("\n");

	*shm = '*';

	return 0;
}

