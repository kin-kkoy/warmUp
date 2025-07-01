/*
    MACHINE LEARNING type of stuff. Normalization is also called  Min-Max Scaling.   Haven't delve really into machine learning but I do know that this is either part or at least similar to logistic regression.

    What it does (based on what I know/understand): Takes in an array or a list of inputs, gets the smallest and the largest numbers, and then normalizes them using the formula: (n - min)/(max - min) where n is the current number or data or element.
    Describe by AI and the net:  Normalization rescales data features to a common range (usually 0 to 1) so that no single feature dominates others due to scale differences, ensuring fair comparison and optimal performance in machine learning algorithms.
*/

#include <stdio.h>

void getList(int *input, int numOfInputs){
    printf("Input data to be normalized:\n");
    for(int i = 0; i < numOfInputs; i++){
        printf("Data %d:  ", i + 1);
        scanf("%d", &input[i]);
    }

    printf("\nData Inputted:\n[ ");
    for(int i = 0; i < numOfInputs; i++){
        printf("%d", input[i]);
        if(i < (numOfInputs - 1)){ printf(", "); }
    }
    printf(" ]\n");
}

int normalize(int *data, float *output, int size){
    // get smallest and largest -> normalize using formula and just overwrite the input with the normalized value
    int successful = 0;

    int min = 999, max = -999;
    for(int i = 0; i < size; i++){
        if(data[i] < min) min = data[i];
        if(data[i] > max) max = data[i];
    }

    if(min != max){
        // (n - min)/(max - min)
        int minnedMax = max - min;
        for(int i = 0; i < size; i++){
            output[i] = (float)(data[i] - min) / minnedMax;
        }
        successful = 1;
    }
    return successful;
}

int main(){
    int nInputs;
    printf("Min-Max or Normalize data!\n\nInput the number of elements to be normalized:  ");
    scanf("%d", &nInputs);
    int input[nInputs];
    float normalized[nInputs];
    
    getList(input, nInputs);
    if(normalize(input, normalized, nInputs) == 1){
        printf("\nNormalized Data:\n[ ");
        for(int i = 0; i < nInputs; i++){
            printf("%.3f", normalized[i]);
            if(i < (nInputs - 1)){ printf(", "); }
        }
        printf(" ]\n");
    }else{
        printf("All input values are the same. Normalization is not possible.\n");
    }
    return 0;
}