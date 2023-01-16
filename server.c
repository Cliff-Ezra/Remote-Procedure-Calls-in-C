#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "add.h"

/*
 * Procedure 1 accepts an integer and returns an integer.
 */
int *proc_1_1_svc(int argp, struct svc_req *rqstp)
{
    static int result;
    printf("Received request for procedure 1 with argument %d\n", argp);
    result = argp * argp; // Square the argument
    return &result;
}

/*
 * Procedure 2 accepts a structure and returns a float.
 */
float *proc_2_1_svc(int argp, char *argp2, struct svc_req *rqstp)
{
    static float result;
    printf("Received request for procedure 2 with arguments %d and %s\n", argp, argp2);
    result = (float)argp / atof(argp2); // convert the string and int to a float and divide them
    return &result;
}

/*
 * Procedure 3 accepts an integer and returns a string
 */
char **proc_3_1_svc(int argp, struct svc_req *rqstp)
{
    static char *result;
    printf("Received request for procedure 3 with argument %d\n", argp);
    result = (char *)malloc(10);
    int n = strlen(result) - 1;
    sprintf(result, "%d is", argp); // convert the int to a string
    result[n] = '\0';
    printf("\nEnd of third procedure; You can exit the server\n");
    printf("**********************************************\n");
    return &result;
}
