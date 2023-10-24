#include<stdio.h>

int main(void){
    /***  ***/
    float sahen, uhen, answer; 
    char enzan;

    printf("数値1(左辺)を入力してください。=>");
    scanf("%f",&sahen);

    getchar();

    printf("¥n");

    printf("演算子を入力してください。=>");
    scanf("%c", &enzan);

    printf("¥n");

    printf("数値2を入力してください。=>");
    scanf("%f", &uhen);

    if (enzan == '+') {
        answer = sahen + uhen;
    }
    else if (enzan == '-') {
        answer = sahen - uhen;
    }
    else if (enzan == '*') {
        answer = sahen * uhen;
    }
    else if (enzan == '/') {
        if (uhen != 0) {
            answer = sahen / uhen;
        }
        else {
            printf("0では割り算ができません。¥n");
            return 0;
        }
    }
    else {
        printf("無効な演算子です。¥n");
        return 0;
    }

    printf("計算結果:%.2f¥n", answer); //少数第二位まで表示

    return 0;
}