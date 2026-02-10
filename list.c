#include <stdio.h>
int main(){
    int num;
    printf("Enter an octal number: ");
    scanf("%d", &num);
    int decNum = 0, base = 1;
    while (num != 0){
        int rem = num % 10;
        decNum += rem * base;
        base *= 8;
        num /= 10;
    }
    printf("Decimal Number = %d", decNum);
    return 0;
}
