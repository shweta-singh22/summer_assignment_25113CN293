#include<stdio.h>
int main() {
    long long N;
    long long total_sum;
    printf("Enter the value of N: ");
    if(scanf("%lld", &N) !=1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }
    if (N<1){
        printf("Please enter a valid positive number(N>=1).\n");
    } else{
        total_sum = (N*(N+1))/2;
        printf("The sum of the first %lld natural numbers is: %lld\n",N, total_sum);
    }
    return 0;
}