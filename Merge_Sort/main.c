#include <stdio.h>
#include <malloc.h>

void inter(int *a, int n1, int *b, int n2, int *c) {
    int pa = 0, pb = 0, pc = 0;
    while (pa < n1 && pb < n2) {
        if(a[pa] <= b[pb]) {
            c[pc] = a[pa];
            pa++;
            pc++;
        }
        else {
            c[pc] = b[pb];
            pb++;
            pc++;
        }
    }

    while(pa < n1) {
        c[pc] = a[pa];
        pc++;
        pa++;
    }

    while(pb < n2) {
        c[pc] = b[pb];
        pb++;
        pc++;
    }




}

void print_vector(int *a, int n1) {
    for(int i = 0; i < n1; i++)
        printf("%d ", a[i]);
    puts("\n");
}

void merge_sort(int **x, int n) {
    int step = 1, *b = malloc(sizeof(int) * n), *q, *a = *x;

    

    for(int i = 0; i < n; i++) b[i] = a[i];
    while(step <= n) {
        int i = 0;
        for(; i <= n - 2 * step ; i += 2*step)
            inter(&(a[i]), step, &(a[i+step]), step, &(b[i]));

        int r = n - i;
        if(r > step) inter(&(a[i]), step, &(a[i+step]), r - step, &(b[i]));
        else for(; i < n; i++) b[i] = a[i];

        step *= 2;
        q = a;
        a = b;
        b = q;
    }
    *x = a;
}

int main() {


    int n = 7;
    int aux[] = {3, 4, 1, 12, 5, 8, 0};
    int *a = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        a[i] = aux[i];
    merge_sort(&a, n);
    print_vector(a, n);
    return 0;
}
