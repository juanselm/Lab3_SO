#!/bin/bash

# Script para realizar mediciones automáticas del cálculo de Pi
# Ejecuta 30 mediciones para cada configuración de hilos (2, 4, 8, 16)

# Borrar ejecutable previo si existe
[ -f pi2 ] && rm pi2

# Compilar el programa
echo "Compilando programa..."
#gcc -fopenmp -O2 -o pi_parallel pi_parallel.c -lm
gcc -fopenmp -O2 -o pi2 pi2.c -lm

if [ $? -ne 0 ]; then
    echo "Error en la compilación"
    exit 1
fi

# Configuraciones de hilos a evaluar
THREADS=(2 4 8 16)
MEDICIONES=30

# Crear directorio para resultados solo si no existe
[ ! -d resultados ] && mkdir resultados

echo "Iniciando mediciones..."
echo "Cada configuración realizará $MEDICIONES mediciones"
echo ""

# Para cada configuración de hilos
for threads in "${THREADS[@]}"; do
    echo "=== Midiendo con $threads hilos ==="
    
    # Archivo de salida para esta configuración
    output_file="resultados/tiempos_${threads}_hilos.txt"
    
    # Escribir encabezado
    echo "# Tiempos de ejecución con $threads hilos" > $output_file
    echo "# Medición\tTiempo(segundos)" >> $output_file
    
    # Realizar 30 mediciones
    for i in $(seq 1 $MEDICIONES); do
        echo -n "  Medición $i/$MEDICIONES... "
        
        # Ejecutar programa y extraer tiempo
        resultado=$(./pi2 $threads | grep "Tiempo de ejecución" | awk '{print $4}')

        
        # Guardar resultado
        echo -e "$i\t$resultado" >> $output_file
        echo "Tiempo: $resultado s"
        
        # Pequeña pausa para evitar sobrecarga
        sleep 1
    done
    
    echo "Completado: $threads hilos"
    echo ""
done

echo "¡Todas las mediciones completadas!"
echo "Los resultados están en la carpeta 'resultados/'"
echo ""
echo "Archivos generados:"
ls -la resultados/