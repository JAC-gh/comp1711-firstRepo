#include <stdio.h>

int main(){
    float width, height;
    printf("Enter width: ");
    scanf("%f", &width);
    printf("Enter height: ");
    scanf("%f", &height);
    float area = width*height;
    printf("Area = %f\n", area);
    return 0;
}