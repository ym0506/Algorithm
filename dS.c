//1. SORT

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #define MAX_SIZE 101
// #define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

// void sort(int [], int);

// int main(void) {
//     int n;
//     int list[MAX_SIZE];
//     printf("Enter the number of numbers to generate: ");
//     scanf("%d", &n);
//     if (n < 1 || n > MAX_SIZE) {
//         fprintf(stderr, "Improper value of n\n");
//         exit(1);
//     }
//     for (int i = 0; i < n; i++) {
//         list[i] = rand() % 1000;
//         printf("%d ", list[i]);
//     }
//     sort(list, n);
//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
//     return 0;
// }

// void sort(int list[], int n) {
//     int min, temp;
//     for (int i = 0; i < n - 1; i++) {
//         min = i;
//         for (int j = i + 1; j < n; j++) {
//             if (list[j] < list[min]) min = j;
//         }
//         SWAP(list[i], list[min], temp);
//     }
// }

//2. srand 이용

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <time.h>
// #define MAX_SIZE 101
// #define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

// void sort(int [], int);

// int main(void) {
//     int n;
//     int list[MAX_SIZE];
//     printf("Enter the number of numbers to generate: ");
//     scanf("%d", &n);
//     if (n < 1 || n > MAX_SIZE) {
//         fprintf(stderr, "Improper value of n\n");
//         exit(1);
//     }
//     srand(time(NULL));
//     for (int i = 0; i < n; i++) {
//         list[i] = rand() % 1000;
//         printf("%d ", list[i]);
//     }
//     sort(list, n);
//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
//     return 0;
// }

// void sort(int list[], int n) {
//     int min, temp;
//     for (int i = 0; i < n - 1; i++) {
//         min = i;
//         for (int j = i + 1; j < n; j++) {
//             if (list[j] < list[min]) min = j;
//         }
//         SWAP(list[i], list[min], temp);
//     }
// }

//3.SWAp 일반 함수

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #define MAX_SIZE 101

// void sort(int [], int);
// void swap(int [], int, int);

// int main(void) {
//     int n;
//     int list[MAX_SIZE];
//     printf("Enter the number of numbers to generate: ");
//     scanf("%d", &n);
//     if (n < 1 || n > MAX_SIZE) {
//         fprintf(stderr, "Improper value of n\n");
//         exit(1);
//     }
//     for (int i = 0; i < n; i++) {
//         list[i] = rand() % 1000;
//         printf("%d ", list[i]);
//     }
//     sort(list, n);
//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
    
//     return 0;
// }

// void sort(int list[], int n) {
//     int min, temp;
//     for (int i = 0; i < n - 1; i++) {
//         min = i;
//         for (int j = i + 1; j < n; j++) {
//             if (list[j] < list[min]) min = j;
//         }
//         swap(list, i, min);
//     }
// }

// void swap(int list[], int i, int j) {
//     int temp;
//     temp = list[i];
//     list[i] = list[j];
//     list[j] = temp;
// }

//4. search_num 입력받아 binary_search 추가

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <time.h>
// #define MAX_SIZE 101
// #define compare(x,y) ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))

// void sort(int [], int);
// void swap(int [], int, int);
// int binary_search(int [], int search_num, int left, int right);

// int main(void) {
//     int n, search_num;
//     int list[MAX_SIZE];
//     printf("Enter the number of numbers to generate: ");
//     scanf("%d", &n);
//     if (n < 1 || n > MAX_SIZE) {
//         fprintf(stderr, "Improper value of n\n");
//         exit(1);
//     }
//     srand(time(NULL));
//     for (int i = 0; i < n; i++) {
//         list[i] = rand() % 1000;
//         printf("%d ", list[i]);
//     }
//     sort(list, n);
//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
//     printf("Enter the number to search: ");
//     scanf("%d", &search_num);
//     int result = binary_search(list, search_num, 0, n - 1);
//     if (result == -1) printf("Not found\n");
//     else printf("Found at %d\n", result);

//     return 0;
// }

// void sort(int list[], int n) {
//     int min, temp;
//     for (int i = 0; i < n - 1; i++) {
//         min = i;
//         for (int j = i + 1; j < n; j++) {
//             if (list[j] < list[min]) min = j;
//         }
//         swap(list, i, min);
//     }
// }

// void swap(int list[], int i, int j) {
//     int temp;
//     temp = list[i];
//     list[i] = list[j];
//     list[j] = temp;
// }

// int binary_search(int list[], int search_num, int left, int right) {
//     int middle;
//     while (left <= right) {
//         middle = (left + right) / 2;
//         if (compare(list[middle], search_num) == 0) return middle;
//         else if (compare(list[middle], search_num) > 0) right = middle - 1;
//         else left = middle + 1;
//     }
//     return -1;
// }


//5. compare 함수 추가

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <time.h>
// #define MAX_SIZE 101

// void sort(int [], int);
// void swap(int [], int, int);
// int binary_search(int [], int search_num, int left, int right);

// int main(void) {
//     int n, search_num;
//     int list[MAX_SIZE];
//     printf("Enter the number of numbers to generate: ");
//     scanf("%d", &n);
//     if (n < 1 || n > MAX_SIZE) {
//         fprintf(stderr, "Improper value of n\n");
//         exit(1);
//     }
//     srand(time(NULL));
//     for (int i = 0; i < n; i++) {
//         list[i] = rand() % 1000;
//         printf("%d ", list[i]);
//     }
//     sort(list, n);
//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
//     printf("Enter the number to search: ");
//     scanf("%d", &search_num);
//     int result = binary_search(list, search_num, 0, n - 1);
//     if (result == -1) printf("Not found\n");
//     else printf("Found at %d\n", result);

//     return 0;
// }

// void sort(int list[], int n) {
//     int min, temp;
//     for (int i = 0; i < n - 1; i++) {
//         min = i;
//         for (int j = i + 1; j < n; j++) {
//             if (list[j] < list[min]) min = j;
//         }
//         swap(list, i, min);
//     }
// }

// void swap(int list[], int i, int j) {
//     int temp;
//     temp = list[i];
//     list[i] = list[j];
//     list[j] = temp;
// }

// int compare(int x, int y) {
//     return x < y ? -1 : x == y ? 0 : 1;
// }

// int binary_search(int list[], int search_num, int left, int right) {
//     int middle;
//     while (left <= right) {
//         middle = (left + right) / 2;
//         if (compare(list[middle], search_num) == 0) return middle;
//         else if (compare(list[middle], search_num) > 0) right = middle - 1;
//         else left = middle + 1;
//     }
//     return -1;
// }

