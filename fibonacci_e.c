int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n,i;
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        if (i < n - 1)
            printf("%d ", fibonacci(i));
        else
            printf("%d", fibonacci(i));
    }

    return 0;
}
