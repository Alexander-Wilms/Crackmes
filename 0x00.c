#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long is_prime(int num) {
	if (num <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 37;
}

void process_string(const char *input) {
	// String must consist of prime numbers separated by dashes

	char *token;
	char *copy = strdup(input);
	int count = 0;

	char all_prime = 1;

	char granted[] = {
		0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x20, 0x67,
		0x72, 0x61, 0x6e, 0x74, 0x65, 0x64, 0x0a, 0x00, // access granted
		0x41, 0x43, 0x43, 0x45, 0x53, 0x53, 0x20, 0x44,
		0x45, 0x4E, 0x49, 0x45, 0x44, 0x20, 0x0a, 0x00}; // ACCESS DENIED
	if (strlen(input) != 10) {
		goto WRONG_LENGTH;
	}
	int separator[] = {0x2d, 0x00};

	// Split the string at each '-' character
	token = strtok(copy, separator);
	while (token != 0) {
		// Convert the resulting elements to integers
		int num = atoi(token);
		if (!is_prime(num)) {
			all_prime = 0;
			break;
		}
		count++;
		token = strtok(0, separator);
	}

	free(copy);

WRONG_LENGTH:
	all_prime *= count;

	// Check if all numbers are prime
	char output[256];
	strcpy(output, granted + (16 * (int)(bool)!all_prime));
	printf(output);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s password\n", argv[0]);
		return 1;
	}

	process_string(argv[1]);

	return 0;
}
