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

	// Check if all numbers are prime
	if (all_prime && count > 0) {
		printf("Access granted\n");
	} else {
		printf("Access denied\n");
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <input_string>\n", argv[0]);
		return 1;
	}

	process_string(argv[1]);

	return 0;
}
