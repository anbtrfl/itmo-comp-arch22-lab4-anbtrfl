#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <omp.h>

float R;
long long cnt;
int key1;


int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Too few parameters");
        exit(-1);
    }
    key1 = atoi(argv[1]);
    if (key1 < -1) {
        printf("Wrong number of threads");
        exit(-1);
    }
    if (key1 > omp_get_max_threads()) {
        printf("Too many number of threads");
        exit(-1);
    }
    if (key1 == -1) key1 = 1;
    if (key1 == 0) key1 = omp_get_max_threads();

    FILE* inp = fopen(argv[2], "rt");
    if (!inp) {
        printf("Can`t open input file");
        exit(-1);
    }
    if (fscanf(inp, "%f%d", &R, &cnt) != 2) {
        printf("Error reading input file");
        exit(-1);
    }
    if ((R <= 0) || (cnt <= 0)) {
        printf("Wrong input parameters");
        exit(-1);
    }
    fclose(inp);

    omp_set_num_threads(key1);
    double tstart = omp_get_wtime();
    int hitcnt = 0;

#pragma omp parallel
    {
        srand(int(time(NULL)) ^ omp_get_thread_num());
#pragma omp for schedule(static)
        for (int i = 1; i < cnt; i++) {
            double x = ((double)rand() / 32767) * 2 - 1;
            double y = ((double)rand() / 32767) * 2 - 1;
            bool hit = (x * x + y * y) <= 1;
            if (hit) {
#pragma omp atomic
                hitcnt += 1;
            }
        }
    }

    double tend = omp_get_wtime();
    printf("Time(%i thread(s)): %g ms\n", key1, (tend - tstart) * 1000);
    FILE* outp = fopen(argv[3], "wt");
    fprintf(outp, "%f", (double)hitcnt / cnt * R * R * 4);
    fclose(outp);
}
