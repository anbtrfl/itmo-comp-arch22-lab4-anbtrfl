#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    FILE *fin = fopen("example_input", "rb");
    int n;
    fscanf(fin, "%i", &n);
    fclose(fin);  
    
    float tstart = omp_get_wtime();
    int sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
    {
      #pragma omp atomic
      sum += i;
    }
    float tend = omp_get_wtime();
    
    FILE *fout = fopen("example_output", "wb");
    fprintf(fout, "%i\n", sum);
    fclose(fout);

    printf("Time (sec): %f", tend - tstart);
    
    return 0;
}
