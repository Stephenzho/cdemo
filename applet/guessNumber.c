//
// Created by 周树义 on 2020/1/18.
//
#include <stdio.h>

#define MAX_GUESS_N  10
#define N 48

int32_t  san();
void answer(int32_t i, unsigned int n);

int main(void) {
    int32_t i = 0;
    unsigned gn = 0;
    
    while ((i = san()) != N){
        gn++;
        if (gn >= MAX_GUESS_N){
            printf("game over,The number of times has been used up");
        }

        answer(i, gn);
    }

    printf("Bingo! number is %d", N);
}


int32_t san(){
    int i =0;
    printf("Please enter your number\n");
    scanf("%d", &i);

    return (int32_t) i;
}

void answer(int32_t i, unsigned int n) {
    if (i < N) {
        printf("Your number is small.You have %d times left\n", n);
    } else if (i > N){
        printf("Your number is big.You have %d times left\n", n);
    }
}