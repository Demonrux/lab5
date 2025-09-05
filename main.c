#include <stdio.h>
#include <stdlib.h>
#define CORRECT_ARR 1
#define MIN_SIZE 0

typedef enum {
    CORRECT_INPUT,
    INCORRECT_INPUT,
} InputStatus;

InputStatus inputArrSize(int* sizeArr);
InputStatus inputMas(double* arr, int sizeArr);
double* findFirstNegativeElem(double* arr, int sizeArr);
void outputMas(double* arr, int sizeArr);
void sortMas(double* arr, int sizeArr);
void swap(double* pa, double* pb);
double* memoryAllocation(int sizeArr);

int main() {
    int sizeArr;
    InputStatus inputStatus = inputArrSize(&sizeArr);
    if (inputStatus == INCORRECT_INPUT) {
        printf("Incorrect Input");
    }
    else {
        double *arr = memoryAllocation(sizeArr);
        if (arr == NULL) {
            inputStatus = INCORRECT_INPUT;
        }
        else {
            inputStatus = inputMas(arr, sizeArr);
            if (inputStatus == CORRECT_INPUT) {
                sortMas(arr, sizeArr);
                outputMas(arr, sizeArr);
            }
        }
        free(arr);
    }
    return inputStatus;
}

double* memoryAllocation(int sizeArr) {
    return (double*)calloc(sizeArr, sizeof(double));
}

double* findFirstNegativeElem(double* arr, int sizeArr) {
    double *pointerFirstNegativeElem = &arr[0];
    for (int i = 0; i < sizeArr; i++) {
        if (arr[i]  < 0 ) {
            pointerFirstNegativeElem = arr + i;
            break;
        }
    }
    return pointerFirstNegativeElem;
}

InputStatus inputMas(double* arr, int sizeArr) {
    InputStatus inputStatus = CORRECT_INPUT;
    for (int i = 0; i < sizeArr; i++) {
        if (!(scanf("%lf", arr + i))) {
            inputStatus = INCORRECT_INPUT;
            break;
        }
    }
    return inputStatus;
}

void sortMas(double* arr, int sizeArr) {
    for (int i = 0; i < sizeArr - 1; i++) {
        for (int j = i + 1; j < sizeArr; j++) {
            double* pa = (arr + i);
            double* pb = (arr + j);
            if (*pa < *pb) {
                swap(pa, pb);
            }
        }
    }
    double pointerFirstNegativeElem = findFirstNegativeElem(arr, sizeArr) - arr;
    for (int i = pointerFirstNegativeElem; i < sizeArr - 1; i++) {
        for (int j = i + 1; j < sizeArr; j++) {
            double* pa = (arr + i);
            double* pb = (arr + j);
            if (((*pa > *pb) && *pa < 0)) {
                swap(pa, pb);
            }
        }
    }
}

void swap(double* pa, double* pb) {
    double temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void outputMas(double* arr, int sizeArr) {
    for (int i = 0; i < sizeArr; i++) {
        printf("%.0lf ", *(arr + i));
    }
}

InputStatus inputArrSize(int* sizeArr) {
    InputStatus inpuStatus;
    if (scanf("%d", sizeArr) != CORRECT_ARR || (*sizeArr < MIN_SIZE)) {
        inpuStatus = INCORRECT_INPUT;
    }
    else {
        inpuStatus = CORRECT_INPUT;
    }
    return inpuStatus;
}

