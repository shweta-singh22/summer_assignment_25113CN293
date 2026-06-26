#include <stdio.h>

int main() {
    int score = 0;
    int answer;

    printf("===== QUIZ APPLICATION =====\n");

    // Question 1
    printf("\n1. What is the capital of India?\n");
    printf("1. Mumbai\n2. Delhi\n3. Kolkata\n4. Chennai\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 2) {
        score++;
    }

    // Question 2
    printf("\n2. Which language is used for C programming?\n");
    printf("1. English\n2. Spanish\n3. Programming Language\n4. Machine Code\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 3) {
        score++;
    }

    // Question 3
    printf("\n3. What is 5 + 3?\n");
    printf("1. 6\n2. 7\n3. 8\n4. 9\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 3) {
        score++;
    }

    // Question 4
    printf("\n4. Which is an input device?\n");
    printf("1. Monitor\n2. Keyboard\n3. Speaker\n4. Printer\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 2) {
        score++;
    }

    // Question 5
    printf("\n5. Which planet is known as Red Planet?\n");
    printf("1. Earth\n2. Venus\n3. Mars\n4. Jupiter\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 3) {
        score++;
    }

    // Result
    printf("\n===== RESULT =====\n");
    printf("Your Score: %d/5\n", score);

    if(score == 5) {
        printf("🏆 Excellent!\n");
    } else if(score >= 3) {
        printf("👍 Good Job!\n");
    } else {
        printf("📘 Keep Practicing!\n");
    }

    return 0;
}