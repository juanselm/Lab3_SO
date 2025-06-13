# Lab3_SO
Laboratorio 3 de la asignatura de Sistemas operativos y laboratios ingeniería de sistemas Udea

[Documento guía](https://docs.google.com/document/d/1XTyIWSTN3SjTvzNtWrbXYFHgCfro4-QLti6oBtim2U0/edit?tab=t.0#heading=h.ixcc4ve701lz)

# Análisis de Desempeño del Cálculo Paralelo de Pi

## Descripción
Este proyecto implementa un algoritmo paralelo para el cálculo aproximado del número π usando OpenMP, con análisis de desempeño para diferentes configuraciones de hilos.

## Archivos del proyecto
- `pi2.c` - Código principal con implementación paralela
- `ejecutarMediciones.sh` - Script para automatizar las mediciones
- `README.md` - Este archivo de documentación

## Requisitos
- GCC con soporte OpenMP
- Sistema operativo Linux/Unix
- Al menos 16 núcleos de CPU (recomendado para pruebas con 16 hilos)

## Instalación de dependencias

### Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install gcc libomp-dev
```

### CentOS/RHEL:
```bash
sudo yum install gcc libgomp-devel
```

## Compilación

### Compilación manual:
```bash
gcc -fopenmp -O2 -o pi2 pi2.c -lm
```
## Uso

### Ejecución individual:
```bash
./pi2 <numero_de_hilos>

# Ejemplos:
./pi2 2    # Ejecutar con 2 hilos
./pi2 4    # Ejecutar con 4 hilos
./pi2 8    # Ejecutar con 8 hilos
./pi2 16   # Ejecutar con 16 hilos
```

### Ejecución automatizada (30 mediciones por configuración):
```bash
chmod +x ejecutarMediciones.sh
./ejecutarMediciones.sh
```

## Parámetros del experimento
- **Valor de n**: 20,000,000,000 (según especificaciones del proyecto)
- **Configuraciones de hilos**: 2, 4, 8, 16
- **Mediciones por configuración**: 30 (para significancia estadística)
- **Método de paralelización**: OpenMP con `#pragma omp parallel for`

## Resultados
Los resultados se guardan automáticamente en la carpeta `resultados/`:
- `tiempos_2_hilos.txt`
- `tiempos_4_hilos.txt` 
- `tiempos_8_hilos.txt`
- `tiempos_16_hilos.txt`

## Análisis esperado
El proyecto incluye análisis de:
- Tiempo de ejecución (walltime)
- Speedup relativo
- Eficiencia paralela
- Distribución estadística de tiempos

## Autores
- Juan Sebastian Loaiza Mazo
- Sulay Gisela Martínez Barreto

## Curso
Sistemas operativos - Universidad de antioquia
