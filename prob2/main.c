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

void greedy(int coins[], int sum) {
    merge_sort(&coins, 4);
    int i = 3;
    printf("\nTried coins: ");
    int coin_number = 0;
    while(i >= 0) {
        if (coins[i] <= sum) {
            sum -= coins[i];
            printf("%d ", coins[i]);
            coin_number++;
        }
        else i--;
    }
    if (sum > 0)
        printf("\nThere is no possible way to pay the sum");
    else
        printf("\n%d coins spent", coin_number);
}

void greedy_other(int coins[4][2], int sum) {
    int i = 3;
    int coin_number = 0;
    printf("\nTried coins: ");
    while(i >= 0) {
        if (coins[i][0] <= sum && coins[i][1] > 0) {
            sum -= coins[i][0];
            printf("%d ", coins[i][0]);
            coin_number++;
            coins[i][1]--;
        }
        else i--;
    }
    if (sum > 0)
        printf("\nThere is no possible way to pay the sum");
    else
        printf("\n%d coins spent", coin_number);
}

int main() {
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    printf("\nArray: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(&a, n);
    int positive = 0;
    for(int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) break;
        positive++;

    }
    printf("\nSorted Array: ");
    print_vector(a, n);

    printf("There are %d positive numbers\n", positive);
    printf("\n\n\n");
    int sum;
    int coins[] = {5, 50, 10, 1};
    printf("\nFirst demonstration of greedy for unlimited coins: \n");
    greedy(coins, 111);
    printf("\n\nSecond demonstration of greedy for K limited coins\nOne coin for each value: ");
    printf("\nChoose sum: ");
    scanf("%d", &sum);
    int finite_coins[4][2] = {{1, 1},
                              {5, 1},
                              {10, 1},
                              {50, 1}};
    puts("\n");
    greedy_other(finite_coins, sum);

    return 0;
}
