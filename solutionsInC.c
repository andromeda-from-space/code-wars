#include <stddef.h>
#include <stdio.h>

unsigned long long sum_factorial(size_t z, const int array[z]) {
    unsigned long long total = 0;
    unsigned long long curr;
    for(int i = 0; i < z; i++){
        curr = 1;
        for(int j = 2; j <= array[i]; j++){
            curr *= j;
        }
        total += curr;
    }
    return total;
}

void test_sum_factorial(){
    const int temp[2] = {4, 6};
    unsigned long long res = sum_factorial(2, temp);
    unsigned long long exp = 744;
    fprintf(stdout, "Result: %lld Expected %lld\n", res, exp);
}

int main(){
    test_sum_factorial();
    return 0;
}