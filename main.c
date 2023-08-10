#include <stdio.h>
#include <stdlib.h>

// declare function
void callStack(int n);
void callHeap();
void callData();
void stackOverflow(int depth);

int main(){
    // stack (recursive 5 time)
    callStack(5);

    // heap 
    callHeap();

    // data
    callData();

    // make it overflow
    printf("let`s make stack overflow !!!\n");
    stackOverflow(1);
    return 0;
}

// stack 
void callStack(int n) {
    if (n == 0) {
        printf("-------------------------\n");
        return ;
    }
    printf("stack address: %p\n", &n);
    return callStack(n - 1);
}

// heap
void callHeap() {
    // heap (malloc)
    int *p1, *p2, *p3, *p4, *p5;
    p1 = (int *)malloc(sizeof(int));
    p2 = (int *)malloc(sizeof(int));
    p3 = (int *)malloc(sizeof(int));
    p4 = (int *)malloc(sizeof(int));
    p5 = (int *)malloc(sizeof(int));
    printf("heap  address: %p\n", p1);
    printf("heap  address: %p\n", p2);
    printf("heap  address: %p\n", p3);
    printf("heap  address: %p\n", p4);
    printf("heap  address: %p\n", p5);
    printf("-------------------------\n");
} 

// data (global variable)
int a = 5, b = 6;
int c, d, e;

// data
void callData() {
    // global variable
    printf("data  address: %p\n", &a);
    printf("data  address: %p\n", &b);
    printf("data  address: %p\n", &c);
    printf("data  address: %p\n", &d);
    printf("data  address: %p\n", &e);
    printf("-------------------------\n");
}

// make stack overflow 
void stackOverflow(int depth) {
    printf("stack adress: %p (depth = %d)\n", &depth, depth);
    stackOverflow(depth+1);
}
