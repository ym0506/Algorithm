/*****************************************************************************
 * 파일명: dS.c
 * 작성자: 이윤명
 * 작성일: 2025.03.21
 *
 * [프로그램 설명/작성 의도]
 *  - 1) 난수를 생성한 뒤 선택 정렬로 정렬하는 간단한 프로그램,
 *  - 2) srand와 time을 사용해 랜덤한 난수를 생성하는 버전,
 *  - 3) 매크로 대신 swap 함수를 직접 구현한 버전,
 *  - 4) 정렬 후 이진 탐색 함수를 통해 특정 수를 찾는 버전,
 *  - 5) compare 함수를 분리해 가독성과 유지보수성을 높인 이진 탐색 버전,

 * [프로그램 분석 내용]
 *  - 난수 생성: rand() 함수를 사용하여 범위 내 임의의 정수를 생성합니다.
 *  - 선택 정렬(Selection Sort): 가장 작은(혹은 가장 큰) 원소를 찾아서
 *    맨 앞으로 이동시키는 정렬 알고리즘
 *  - 이진 탐색(Binary Search): 오름차순 정렬된 배열에서 원하는 값을 
 *    절반씩 나누어 빠르게 찾는 알고리즘
 *  - swap 함수/매크로: 배열 내 두 원소의 위치를 교환
 *  - compare 함수: 두 값을 비교해 -1, 0, 1을 반환

 *****************************************************************************/

 // ===== 1. 난수를 생성하여 선택 정렬만 수행하는 코드 =====
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

//     // 난수 생성 후 배열에 저장
//     for (int i = 0; i < n; i++) {
//         list[i] = rand() % 1000;
//         printf("%d ", list[i]);
//     }

//     // 선택 정렬 수행
//     sort(list, n);

//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
//     return 0;
// }

// // 선택 정렬을 통해 배열을 오름차순으로 정렬
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


 //===== 2. srand와 time을 이용해 더욱 랜덤한 난수를 생성하여 정렬 =====
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

//     // 시간에 따라 난수 설정
//     srand(time(NULL));
//     for (int i = 0; i < n; i++) {
//         list[i] = rand() % 1000;
//         printf("%d ", list[i]);
//     }

//     // 선택 정렬 수행
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


 // ===== 3. swap 함수(매크로 대신 별도 함수로 구현) =====
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

//     // 선택 정렬 수행
//     sort(list, n);

//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
    
//     return 0;
// }

// // 선택 정렬 시, 매크로 대신 swap 함수를 사용
// void sort(int list[], int n) {
//     int min;
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


 // ===== 4. 정렬 후 이진 탐색 함수를 사용하여 특정 수 찾기 =====
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <time.h>
// #define MAX_SIZE 101
// #define compare(x,y) ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))

// void sort(int [], int);
// void swap(int [], int, int);
// int binary_search(int [], int, int, int);

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

//     // 정렬 수행
//     sort(list, n);
//     printf("\n Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", list[i]);
//     }
//     printf("\n");

//     // 탐색할 숫자 입력
//     printf("Enter the number to search: ");
//     scanf("%d", &search_num);

//     // 이진 탐색 수행
//     int result = binary_search(list, search_num, 0, n - 1);
//     if (result == -1) printf("Not found\n");
//     else printf("Found at %d\n", result);

//     return 0;
// }

// void sort(int list[], int n) {
//     int min;
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

// // compare 매크로를 사용하여 list[middle]와 search_num을 비교
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


 //===== 5. compare 함수를 별도로 분리하여 가독성 및 유지보수성 강화 =====
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 101

void sort(int [], int);
void swap(int [], int, int);
int compare(int, int);
int binary_search(int [], int, int, int);

int main(void) {
    int n, search_num;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Improper value of n\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }

    // 정렬 수행
    sort(list, n);
    printf("\n Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    // 탐색할 숫자 입력
    printf("Enter the number to search: ");
    scanf("%d", &search_num);

    // 이진 탐색 수행
    int result = binary_search(list, search_num, 0, n - 1);
    if (result == -1) printf("Not found\n");
    else printf("Found at %d\n", result);

    return 0;
}

void sort(int list[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (list[j] < list[min]) min = j;
        }
        swap(list, i, min);
    }
}

void swap(int list[], int i, int j) {
    int temp;
    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

// compare 함수를 통해 x < y, x == y, x > y인 경우 -1, 0, 1을 각각 반환
int compare(int x, int y) {
    return (x < y) ? -1 : (x == y) ? 0 : 1;
}

// compare 함수를 사용하여 이진 탐색 수행
int binary_search(int list[], int search_num, int left, int right) {
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (compare(list[middle], search_num) == 0) return middle;
        else if (compare(list[middle], search_num) > 0) right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}

