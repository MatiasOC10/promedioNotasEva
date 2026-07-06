#include <stdio.h>

// Declaración de funciones
void calcularPromedioUnidad(int unidad);
float calcularACD(void);
float calcularAPE(void);
float calcularAA(void);
float calcularES(void);
float calcularPromedioTresUnidades(float sumaPromedios, int cantidadUnidades);
void determinarEstado(float promedioGeneral);

int main() {
    int unidad;
    const int NUMEROUNIDAD = 3; // Cantidad total de unidades a evaluar

    // Variables para almacenar los promedios ponderados de cada componente
    float promedioACD;
    float promedioAPE;
    float promedioAA;
    float promedioES;
    float promedioFinal;

    // Variables para calcular el promedio general
    float sumaPromedios = 0;
    float promedioGeneral;

    // Ciclo que se repite para las 3 unidades
    for (unidad = 1; unidad <= NUMEROUNIDAD; unidad++) {
        calcularPromedioUnidad(unidad); // Muestra el encabezado de la unidad

        // Se calculan los promedios ponderados de cada componente
        promedioACD = calcularACD();
        promedioAPE = calcularAPE();
        promedioAA = calcularAA();
        promedioES = calcularES();

        // Se suma cada componente para obtener el promedio final de la unidad
        promedioFinal = promedioACD + promedioAPE + promedioAA + promedioES;

        // Se muestran los resultados de la unidad
        printf("\nPromedio ACD de la unidad %d: %.2f\n", unidad, promedioACD);
        printf("Promedio APE de la unidad %d: %.2f\n", unidad, promedioAPE);
        printf("Promedio AA de la unidad %d: %.2f\n", unidad, promedioAA);
        printf("Promedio ES de la unidad %d: %.2f\n", unidad, promedioES);
        printf("Promedio Final de la Unidad %d: %.2f\n\n", unidad, promedioFinal);

        // Se acumula el promedio final de cada unidad
        sumaPromedios += promedioFinal;
    }

    // Se calcula el promedio general de las 3 unidades
    promedioGeneral = calcularPromedioTresUnidades(sumaPromedios, NUMEROUNIDAD);

    // Se muestra el promedio general
    printf("====================================\n");
    printf("Promedio general de las 3 unidades: %.2f\n", promedioGeneral);

    // Se determina el estado final del estudiante
    determinarEstado(promedioGeneral);

    return 0;
}

// Función que muestra el título de la unidad actual
void calcularPromedioUnidad(int unidad) {
    printf("\n========== Unidad %d ==========\n", unidad);
}

// Función que calcula el promedio ponderado de ACD
float calcularACD(void) {
    float promedioACD = 0, notaACD;
    int i, numero;

    // Se solicita la cantidad de actividades ACD
    // El número debe ser mayor o igual a 1
    do {
        printf("Ingrese el numero de actividades en ACD: ");
        scanf("%d", &numero);
    } while (numero < 1);

    // Se ingresan las notas de cada actividad ACD
    for (i = 1; i <= numero; i++) {
        do {
            printf("Ingrese la nota del ACD %d: ", i);
            scanf("%f", &notaACD);
        } while (notaACD < 0 || notaACD > 10); // Valida notas entre 0 y 10

        promedioACD += notaACD; // Acumula las notas
    }

    // Calcula el promedio simple de ACD
    promedioACD = promedioACD / numero;

    // Aplica el ponderado correspondiente al ACD: 20%
    promedioACD = promedioACD * 0.20;

    return promedioACD;
}

// Función que calcula el promedio ponderado de APE
float calcularAPE(void) {
    float promedioAPE = 0, notaAPE;
    int i, numero;

    // Se solicita la cantidad de actividades APE
    do {
        printf("Ingrese el numero de actividades en APE: ");
        scanf("%d", &numero);
    } while (numero < 1);

    // Se ingresan las notas de cada actividad APE
    for (i = 1; i <= numero; i++) {
        do {
            printf("Ingrese la nota del APE %d: ", i);
            scanf("%f", &notaAPE);
        } while (notaAPE < 0 || notaAPE > 10); // Valida notas entre 0 y 10

        promedioAPE += notaAPE; // Acumula las notas
    }

    // Calcula el promedio simple de APE
    promedioAPE = promedioAPE / numero;

    // Aplica el ponderado correspondiente al APE: 25%
    promedioAPE = promedioAPE * 0.25;

    return promedioAPE;
}

// Función que calcula el promedio ponderado de AA
float calcularAA(void) {
    float promedioAA = 0, notaAA;
    int i, numero;

    // Se solicita la cantidad de actividades AA
    do {
        printf("Ingrese el numero de actividades en AA: ");
        scanf("%d", &numero);
    } while (numero < 1);

    // Se ingresan las notas de cada actividad AA
    for (i = 1; i <= numero; i++) {
        do {
            printf("Ingrese la nota del AA %d: ", i);
            scanf("%f", &notaAA);
        } while (notaAA < 0 || notaAA > 10); // Valida notas entre 0 y 10

        promedioAA += notaAA; // Acumula las notas
    }

    // Calcula el promedio simple de AA
    promedioAA = promedioAA / numero;

    // Aplica el ponderado correspondiente al AA: 20%
    promedioAA = promedioAA * 0.20;

    return promedioAA;
}

// Función que calcula el promedio ponderado de ES
float calcularES(void) {
    float promedioES = 0;
    float notaABP, notaPD;
    float pABP, pPD;

    // Se solicita la nota del Aprendizaje Basado en Problemas
    do {
        printf("Ingrese la nota del Aprendizaje Basado en Problemas: ");
        scanf("%f", &notaABP);
    } while (notaABP < 0 || notaABP > 10);

    // Se solicita la nota del Portafolio Digital
    do {
        printf("Ingrese la nota del Portafolio Digital: ");
        scanf("%f", &notaPD);
    } while (notaPD < 0 || notaPD > 10);

    // Se solicitan los ponderados internos de ABP y PD
    // Ambos deben estar entre 0 y 10, y su suma debe ser 10
    do {
        printf("Ingrese el ponderado del Aprendizaje Basado en Problemas (1-10): ");
        scanf("%f", &pABP);

        printf("Ingrese el ponderado del Portafolio Digital (1-10): ");
        scanf("%f", &pPD);

        if (pABP < 0 || pPD < 0 || pABP > 10 || pPD > 10 ||
            (pABP + pPD < 9.99 || pABP + pPD > 10.01)) {
            printf("Error: los ponderados deben estar entre 0 y 10, y deben sumar 10.\n");
        }

    } while (pABP < 0 || pPD < 0 || pABP > 10 || pPD > 10 ||
             (pABP + pPD < 9.99 || pABP + pPD > 10.01));

    // Convierte los ponderados de escala 0-10 a escala decimal
    pABP = pABP / 10;
    pPD = pPD / 10;

    // Calcula el promedio interno de ES
    promedioES = (notaABP * pABP) + (notaPD * pPD);

    // Aplica el ponderado correspondiente al ES: 35%
    promedioES = promedioES * 0.35;

    return promedioES;
}

// Función que calcula el promedio general de las 3 unidades
float calcularPromedioTresUnidades(float sumaPromedios, int cantidadUnidades) {
    float promedioGeneral;

    promedioGeneral = sumaPromedios / cantidadUnidades;

    return promedioGeneral;
}

// Función que determina el estado final según el promedio general
void determinarEstado(float promedioGeneral) {
    if (promedioGeneral >= 7) {
        printf("Estado final: Aprobado\n");
    } else if (promedioGeneral >= 2.5) {
        printf("Estado final: Supletorio\n");
    } else {
        printf("Estado final: Desaprobado\n");
    }
}