#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum OPERATOR {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    INVALID
} Operator;

typedef enum DIRECTION {
    LEFT,
    RIGHT
} Direction;

Operator getOperator(char symbol) {
    if (symbol == '+') return ADD;
    if (symbol == '-') return SUBTRACT;
    if (symbol == '*') return MULTIPLY;
    if (symbol == '/') return DIVIDE;
    return INVALID;
}

void insertNewLine(void) {
    printf("\n");
}

Operator inputOperator(void) {
    char inputOperator;
    Operator operator;

    printf("演算子を入力してください。=>");
    scanf("%c%*[^\n]%*c", &inputOperator);
    operator = getOperator(inputOperator);
    insertNewLine();
    return operator;
}

double inputOperand(Direction direction) {
    char* value = (direction == LEFT) ? "左辺" : "右辺";
    double operand;

    printf("数値（%s）を入力してください。=>", value);
    scanf("%lf%*c", &operand);
    insertNewLine();
    return operand;
}

void zeroDivisionError(void) {
    printf("0では割り算ができません。\n");
    exit(1);
}

bool isZeroDivision(double rightOperand) {
    return rightOperand == 0; 
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (isZeroDivision(b)) zeroDivisionError();
    return a / b;
}

void exitWithInvalidOperandError(void) {
    printf("無効な演算子です。\n");
    exit(1);
}

double calculator(Operator operator, double a, double b) {
    if (operator == INVALID) exitWithInvalidOperandError();
    if (operator == ADD) return add(a, b);
    if (operator == SUBTRACT) return subtract(a, b);
    if (operator == MULTIPLY) return multiply(a, b);
    if (operator == DIVIDE) return divide(a, b);
    return 0;
}

void printResult(double result) {
    printf("計算結果:%.2lf\n", result);
}

int main(void) {
    double leftOperand, rightOperand, result;
    Operator operator;

    leftOperand = inputOperand(LEFT);
    operator = inputOperator();
    rightOperand = inputOperand(RIGHT);
    result = calculator(operator, leftOperand, rightOperand);
    printResult(result);

    return 0;
}
