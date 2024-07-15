#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 1100

int main () {
        int **no_of_pages;
        int *total_no_of_books;

        int shelfs, queries;

        int x,y;

        printf("Enter the No.of shelfs : ");
        scanf("%d", &shelfs);

        printf("Toal No.of Queries : ");
        scanf("%d", &queries);

        no_of_pages = (int**) malloc(shelfs * sizeof(int*));

        if (no_of_pages == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
        }

        total_no_of_books = (int*) malloc(shelfs * sizeof(int));

        if (total_no_of_books == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                free(no_of_pages);
                return 1;
        }

        for (int i = 0; i < shelfs; i++) {
                no_of_pages[i] = NULL;
                total_no_of_books[i] = 0;
        }

        int query_type;
        int B;
        while (queries--) {
                printf("Enter the query type : ");
                scanf("%d", &query_type);

                if (query_type == 1 ) {
                        printf("Which shelf you want add book : ");
                        scanf("%d", &x);

                        printf("No of pages in Book : ");
                        scanf("%d", &y);

                        if (x < 1 || x > shelfs) {
                                printf("Invalid shelf number\n");
                                continue;
                        }

                        B = ++total_no_of_books[x-1];
                        printf("B = %d\n",B);

                        no_of_pages[x-1] = (int*)realloc(no_of_pages[x-1],B*sizeof(int));

                        if (no_of_pages[x-1] == NULL) {
                                fprintf(stderr, "Memory allocation failed\n");
                                free(total_no_of_books);
                                free(no_of_pages[x-1]);
                                return 1;
                        }

                        no_of_pages[x-1][B-1] = y;
                }
                else if (query_type == 2) {
                        printf("Enter the shelf : ");
                        scanf("%d", &x);

                        printf("which book No.of pages you want to know : ");
                        scanf("%d", &y);

                        if (x < 1 || x > shelfs) {
                                printf("Invalid shelf number\n");
                                continue;
                        }

                        if (total_no_of_books[x-1] < y) {
                                printf("Invalid Book number\n");
                                continue;
                        }
                        printf("%d shelf %d book pages : %d\n",x,y, no_of_pages[x-1][y-1]);
                }
                else if (query_type == 3) {
                        printf("Enter the shelf Number : ");
                        scanf("%d", &x);
                        printf("No of Books in %d shelf : %d\n",x,total_no_of_books[x-1]);
                }
                else {
                        printf("Invaild Query Type\n");
                        continue;
                }
        }
        for (int i = 0; i < shelfs; i++) {
                for (int j = 0; j < total_no_of_books[i]; j++) {
                        printf("Shelf %d - %d\n", i +1, no_of_pages[i][j]);
                }
        }

        for (int i = 0; i < shelfs; i++) {
               printf("Total_no_of_books in %d shelf : %d\n",i+1, total_no_of_books[i]);
        }

        for (int i = 0; i < shelfs; i++) {
                free(no_of_pages[i]);
        }

        free(no_of_pages);
        free(total_no_of_books);

        return 0;
}
