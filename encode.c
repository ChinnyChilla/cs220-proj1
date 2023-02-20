#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{

	srand(time(0)); // Use the current time as the seed for random generator

	if (argc != 2)
	{
		fprintf(stderr, "Please invoke as %s <key>\n", argv[0]);
		return 1; // Indicate something went wrong
	}
	char *key=argv[1];
	int nextChar = getchar();
	int whatToShiftBy = 0;
	int currentIndex = 1;
	while (*key != '\0') {
		char currentChar = *key;
		whatToShiftBy += ((int) currentChar) * currentIndex;
		currentIndex++;
		key++;
	}
	currentIndex = 0;
	int maxIndex = 93;
	int offset = 33;
	while (nextChar != EOF)
	{
		if ((int) nextChar >=33 && (int) nextChar <=126) {
			int test = ((int)nextChar) - offset + whatToShiftBy + currentIndex;
			printf("%c", (char)(test % maxIndex + offset));
		} else {
			printf("%c", nextChar);
		}
		currentIndex++;
		/* TODO:
			Using the key, write an decoded character to standard out
			For example, if you decode nextChar and save it in variable deCoded,
			You can use: putchar(deCoded);
		*/
	currentIndex++;
		nextChar = getchar();
	}
	return 0; // Indicate nothing went wrong
}
