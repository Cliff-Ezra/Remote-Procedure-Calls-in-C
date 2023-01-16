#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"

/*
 * Client-side function prototypes for the remote procedures.
 */
int *proc_1_1(int, CLIENT *);
float *proc_2_1(int, char *, CLIENT *);
char **proc_3_1(int, CLIENT *);

int main(int argc, char *argv[])
{
    printf("Client started\n");
    CLIENT *cl;
    int param1;
    int param2 = 15;
    char *param2_string = "2.5";
    int param3 = 7;

    /* Create a client handle for the server */
    cl = clnt_create(argv[1], ADD_PROG, ADD_VERS, "tcp");
    if (cl == NULL)
    {
        printf("error: could not connect to server.\n");
        exit(1);
    }

    /* Call procedure 1 */
    printf("Type a number that you want to be squared: ");
    scanf("%d", &param1);
    int procOneResult = *proc_1_1(param1, cl);
    printf("Result from procedure 1: %d\n", procOneResult);

    /* Call procedure 2 */
    float procTwoResult = *proc_2_1(param2, param2_string, cl);
    printf("Result from procedure 2: %f\n", procTwoResult);

    /* Call procedure 3 */
    char *result_string = *proc_3_1(param3, cl);
    printf("Result from procedure 3: %s\n", result_string);

    /* Clean up and exit */
    clnt_destroy(cl);
    return 0;
}