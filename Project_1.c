#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  
#include <math.h>

#define EPSILON 0.001  

int main() {
    int b = 0; 
    float a;

  
    sleep(1);  

    srand(time(0) ^ getpid());

    int integerPart = rand();
    if (rand() % 2 == 0) {
        integerPart *= -1;
    }

    int decimalPart = rand() % 100;

    float randomNumber = integerPart + decimalPart / 100.0;

    printf("Welcome to the Number Guessing Game!\n");
    printf("Rules of the game:\n");
    printf("1. A random number with two decimal places has been generated.\n");
    printf("2. The number can be positive, negative, or zero.\n");
    printf("3. Your task is to guess this number.\n");
    printf("4. After each guess, you will receive feedback:\n");
    printf("   - 'Too high!' if your guess is greater than the number.\n");
    printf("   - 'Too low!' if your guess is less than the number.\n");
    printf("5. Keep guessing until you find the correct number.\n");
    printf("6. The game will tell you how many guesses it took to get the correct answer.\n");
    printf("Good luck!\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%f", &a);
        b++;  
        if (a > randomNumber) {
            printf("Too high!\n");
        } else if (a < randomNumber) {
            printf("Too low!\n");
        } else if (fabs(a - randomNumber) < EPSILON) {  
            printf("You guessed the number in %d guesses!\n", b);
            break;
        }
    } while (1);

    return 0;
}
