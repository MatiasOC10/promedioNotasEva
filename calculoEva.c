#include <stdio.h>

void calcularPromedioUnidad(int unidad);
float calcularACD(void);
float calcularAPE(void);
float calcularAA(void);
float calcularES(void);
float calcularPromedioTresUnidades(float sumaPromedios, int cantidadUnidades);
void determinarEstado(float promedioGeneral);

int main() {
    int unidad;
    const int NUMEROUNIDAD = 3;

    float promedioACD;
    float promedioAPE;
    float promedioAA;
    float promedioES;
    float promedioFinal;

    float sumaPromedios = 0;
    float promedioGeneral;

    for (unidad = 1; unidad <= NUMEROUNIDAD; unidad++) {
        calcularPromedioUnidad(unidad);

        promedioACD = calcularACD();
        promedioAPE = calcularAPE();
        promedioAA = calcularAA();
        promedioES = calcularES();

        promedioFinal = promedioACD + promedioAPE + promedioAA + promedioES;

        printf("\nPromedio ACD de la unidad %d: %.2f\n", unidad, promedioACD);
        printf("Promedio APE de la unidad %d: %.2f\n", unidad, promedioAPE);
        printf("Promedio AA de la unidad %d: %.2f\n", unidad, promedioAA);
        printf("Promedio ES de la unidad %d: %.2f\n", unidad, promedioES);
        printf("Promedio Final de la Unidad %d: %.2f\n\n", unidad, promedioFinal);

        sumaPromedios += promedioFinal;
    }

    promedioGeneral = calcularPromedioTresUnidades(sumaPromedios, NUMEROUNIDAD);

    printf("====================================\n");
    printf("Promedio general de las 3 unidades: %.2f\n", promedioGeneral);

    determinarEstado(promedioGeneral);

    return 0;
}

void calcularPromedioUnidad(int unidad) {
    printf("\n========== Unidad %d ==========\n", unidad);
}

float calcularACD(void) {
    float promedioACD = 0, notaACD;
    int i, numero;

    do {
        printf("Ingrese el numero de actividades en ACD: ");
        scanf("%d", &numero);
    } while (numero < 1);

    for (i = 1; i <= numero; i++) {
        do {
            printf("Ingrese la nota del ACD %d: ", i);
            scanf("%f", &notaACD);
        } while (notaACD < 0 || notaACD > 10);

        promedioACD += notaACD;
    }

    promedioACD = promedioACD / numero;
    promedioACD = promedioACD * 0.20;

    return promedioACD;
}

float calcularAPE(void) {
    float promedioAPE = 0, notaAPE;
    int i, numero;

    do {
        printf("Ingrese el numero de actividades en APE: ");
        scanf("%d", &numero);
    } while (numero < 1);

    for (i = 1; i <= numero; i++) {
        do {
            printf("Ingrese la nota del APE %d: ", i);
            scanf("%f", &notaAPE);
        } while (notaAPE < 0 || notaAPE > 10);

        promedioAPE += notaAPE;
    }

    promedioAPE = promedioAPE / numero;
    promedioAPE = promedioAPE * 0.25;

    return promedioAPE;
}

float calcularAA(void) {
    float promedioAA = 0, notaAA;
    int i, numero;

    do {
        printf("Ingrese el numero de actividades en AA: ");
        scanf("%d", &numero);
    } while (numero < 1);

    for (i = 1; i <= numero; i++) {
        do {
            printf("Ingrese la nota del AA %d: ", i);
            scanf("%f", &notaAA);
        } while (notaAA < 0 || notaAA > 10);

        promedioAA += notaAA;
    }

    promedioAA = promedioAA / numero;
    promedioAA = promedioAA * 0.20;

    return promedioAA;
}

float calcularES(void) {
    float promedioES = 0;
    float notaABP, notaPD;
    float pABP, pPD;

    do {
        printf("Ingrese la nota del Aprendizaje Basado en Problemas: ");
        scanf("%f", &notaABP);
    } while (notaABP < 0 || notaABP > 10);

    do {
        printf("Ingrese la nota del Portafolio Digital: ");
        scanf("%f", &notaPD);
    } while (notaPD < 0 || notaPD > 10);

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

    pABP = pABP / 10;
    pPD = pPD / 10;

    promedioES = (notaABP * pABP) + (notaPD * pPD);
    promedioES = promedioES * 0.35;

    return promedioES;
}

float calcularPromedioTresUnidades(float sumaPromedios, int cantidadUnidades) {
    float promedioGeneral;

    promedioGeneral = sumaPromedios / cantidadUnidades;

    return promedioGeneral;
}

void determinarEstado(float promedioGeneral) {
    if (promedioGeneral >= 7) {
        printf("Estado final: Aprobado\n");
    } else {
        printf("Estado final: Desaprobado\n");
    }
}