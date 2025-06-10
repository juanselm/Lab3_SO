/*
 * Cálculo paralelo de Pi usando OpenMP
 * Modificado para análisis de desempeño
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

double CalcPi(int n, int num_threads);
double f(double a);

int main(int argc, char **argv)
{
    int n = 2000000000;  // Valor representativo según el enunciado
    const double fPi25DT = 3.141592653589793238462643;
    double fPi;
    double fTimeStart, fTimeEnd, walltime;
    int num_threads;
    
    // Leer número de hilos desde argumentos de línea de comandos
    if (argc != 2) {
        printf("Uso: %s <numero_de_hilos>\n", argv[0]);
        printf("Ejemplo: %s 4\n", argv[0]);
        return 1;
    }
    
    num_threads = atoi(argv[1]);
    
    if (num_threads <= 0) {
        printf("El número de hilos debe ser mayor a 0\n");
        return 1;
    }
    
    // Configurar OpenMP
    omp_set_num_threads(num_threads);
    
    printf("Calculando Pi con n=%d usando %d hilos...\n", n, num_threads);
    
    // Medir tiempo de ejecución
    fTimeStart = omp_get_wtime();
    
    /* Cálculo paralelo de Pi */
    fPi = CalcPi(n, num_threads);
    
    fTimeEnd = omp_get_wtime();
    walltime = fTimeEnd - fTimeStart;
    
    // Mostrar resultados
    printf("Pi calculado: %.20f\n", fPi);
    printf("Error: %.20f\n", fabs(fPi - fPi25DT));
    printf("Tiempo de ejecución: %.6f segundos\n", walltime);
    printf("Hilos utilizados: %d\n", num_threads);
    
    return 0;
}

double f(double a)
{
    return (4.0 / (1.0 + a*a));
}

double CalcPi(int n, int num_threads)
{
    const double fH = 1.0 / (double) n;
    double fSum = 0.0;
    double fX;
    int i;

    // Paralelización con OpenMP
    #pragma omp parallel for private(fX) reduction(+:fSum) num_threads(num_threads)
    for (i = 0; i < n; i++)
    {
        fX = fH * ((double)i + 0.5);
        fSum += f(fX);
    }
    
    return fH * fSum;
}