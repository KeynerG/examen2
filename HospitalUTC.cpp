#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_PACIENTES 20
#define MAX_MEDICOS 10
#define MAX_CITAS 10

// Vectores para almacenar datos de pacientes
char cedulaPacientes[MAX_PACIENTES][20];
char nombresPacientes[MAX_PACIENTES][50];
char apellidosPacientes[MAX_PACIENTES][50];
int edadesPacientes[MAX_PACIENTES];
char telefonosPacientes[MAX_PACIENTES][20];
int totalPacientes = 0;

// Vectores para almacenar datos de médicos
char cedulaMedicos[MAX_MEDICOS][20];
char nombresMedicos[MAX_MEDICOS][50];
char especialidadesMedicos[MAX_MEDICOS][50];
char diasDisponiblesMedicos[MAX_MEDICOS][100];
int totalMedicos = 0;

// Vectores para almacenar datos de citas
char fechasCitas[MAX_CITAS][20];
char cedulaPacientesCitas[MAX_CITAS][20];
char cedulaMedicosCitas[MAX_CITAS][20];
char especialidadesCitas[MAX_CITAS][50];
char sintomasCitas[MAX_CITAS][100];
int totalCitas = 0;

void inicialiarVectores()
{
    for (int i = 0; i < MAX_PACIENTES; i++)
    {
        cedulaPacientes[i][0] = '\0';
        nombresPacientes[i][0] = '\0';
        apellidosPacientes[i][0] = '\0';
        edadesPacientes[i] = 0;
        telefonosPacientes[i][0] = '\0';
    }

    for (int i = 0; i < MAX_MEDICOS; i++)
    {
        cedulaMedicos[i][0] = '\0';
        nombresMedicos[i][0] = '\0';
        especialidadesMedicos[i][0] = '\0';
        diasDisponiblesMedicos[i][0] = '\0';
    }

    for (int i = 0; i < MAX_CITAS; i++)
    {
        fechasCitas[i][0] = '\0';
        cedulaPacientesCitas[i][0] = '\0';
        cedulaMedicosCitas[i][0] = '\0';
        especialidadesCitas[i][0] = '\0';
        sintomasCitas[i][0] = '\0';
    }
}

void registrarPaciente()
{
    system("cls");
    if (totalPacientes >= MAX_PACIENTES)
    {
        printf("No se pueden registrar mas pacientes.\n");
        return;
    }

    char cedula[20];
    printf("Ingrese la cedula del paciente: ");
    scanf("%s", cedula);

    for (int i = 0; i < totalPacientes; i++)
    {
        if (strcmp(cedulaPacientes[i], cedula) == 0)
        {
            printf("El paciente ya esta registrado.\n");
            getch();
            return;
        }
    }

    strcpy(cedulaPacientes[totalPacientes], cedula);
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombresPacientes[totalPacientes]);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellidosPacientes[totalPacientes]);
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &edadesPacientes[totalPacientes]);
    printf("Ingrese el telefono del paciente: ");
    scanf("%s", telefonosPacientes[totalPacientes]);

    totalPacientes++;
    printf("Paciente registrado correctamente.\n");
    getch();
}

void registrarMedico()
{
    system("cls");
    if (totalMedicos >= MAX_MEDICOS)
    {
        printf("No se pueden registrar mas medicos.\n");
        return;
    }

    char cedula[20];
    printf("Ingrese la cedula del medico: ");
    scanf("%s", cedula);

    for (int i = 0; i < totalMedicos; i++)
    {
        if (strcmp(cedulaMedicos[i], cedula) == 0)
        {
            printf("El medico ya esta registrado.\n");
            getch();
            return;
        }
    }

    strcpy(cedulaMedicos[totalMedicos], cedula);
    printf("Ingrese el nombre del medico: ");
    scanf("%s", nombresMedicos[totalMedicos]);

    // Selección de especialidad
    printf("Seleccione la especialidad del medico:\n");
    printf("1. Medicina General\n");
    printf("2. Pediatria\n");
    printf("3. Cardiologia\n");
    printf("4. Dermatologia\n");
    printf("Seleccione una opción: ");
    int opcionEspecialidad;
    scanf("%d", &opcionEspecialidad);

    switch (opcionEspecialidad)
    {
    case 1:
        strcpy(especialidadesMedicos[totalMedicos], "Medicina General");
        break;
    case 2:
        strcpy(especialidadesMedicos[totalMedicos], "Pediatria");
        break;
    case 3:
        strcpy(especialidadesMedicos[totalMedicos], "Cardiologia");
        break;
    case 4:
        strcpy(especialidadesMedicos[totalMedicos], "Dermatologia");
        break;
    default:
        printf("Opción invalida. Especialidad no registrada.\n");
        return;
    }

    printf("Ingrese los días disponibles del medico (separados por comas): ");
    scanf("%s", diasDisponiblesMedicos[totalMedicos]);

    totalMedicos++;
    printf("Medico registrado correctamente.\n");
    getch();
}

void programarCita()
{
    system("cls");
    if (totalCitas >= MAX_CITAS)
    {
        printf("No se pueden programar mas citas.\n");
        return;
    }

    char cedulaPaciente[20], cedulaMedico[20];
    printf("Ingrese la fecha de la cita (DD/MM/AAAA): ");
    scanf("%s", fechasCitas[totalCitas]);

    printf("Ingrese la cédula del paciente: ");
    scanf("%s", cedulaPaciente);

    int pacienteEncontrado = 0;
    for (int i = 0; i < totalPacientes; i++)
    {
        if (strcmp(cedulaPacientes[i], cedulaPaciente) == 0)
        {
            pacienteEncontrado = 1;
            break;
        }
    }

    if (!pacienteEncontrado)
    {
        printf("Paciente no encontrado.\n");
        return;
    }

    printf("Ingrese la cedula del medico: ");
    scanf("%s", cedulaMedico);

    int medicoEncontrado = 0;
    for (int i = 0; i < totalMedicos; i++)
    {
        if (strcmp(cedulaMedicos[i], cedulaMedico) == 0)
        {
            medicoEncontrado = 1;
            strcpy(especialidadesCitas[totalCitas], especialidadesMedicos[i]);
            break;
        }
    }

    if (!medicoEncontrado)
    {
        printf("Medico no encontrado.\n");
        return;
    }

    strcpy(cedulaPacientesCitas[totalCitas], cedulaPaciente);
    strcpy(cedulaMedicosCitas[totalCitas], cedulaMedico);

    // Selección de síntomas
    printf("Seleccione los sintomas del paciente:\n");
    printf("1. Fiebre\n");
    printf("2. Dolor de estomago\n");
    printf("3. Dolor de cabeza\n");
    printf("4. Dolor muscular\n");
    printf("Seleccione una opcion: ");
    int opcionSintoma;
    scanf("%d", &opcionSintoma);

    switch (opcionSintoma)
    {
    case 1:
        strcpy(sintomasCitas[totalCitas], "Fiebre");
        break;
    case 2:
        strcpy(sintomasCitas[totalCitas], "Dolor de estomago");
        break;
    case 3:
        strcpy(sintomasCitas[totalCitas], "Dolor de cabeza");
        break;
    case 4:
        strcpy(sintomasCitas[totalCitas], "Dolor muscular");
        break;
    default:
        printf("Opcion invalida. Sintoma no registrado.\n");
        return;
    }

    totalCitas++;
    printf("Cita programada correctamente.\n");
    getch();
}

void historialMedico()
{
    system("cls");
    char cedula[20];
    printf("Ingrese la cedula del paciente: ");
    scanf("%s", cedula);

    int pacienteEncontrado = 0;
    for (int i = 0; i < totalPacientes; i++)
    {
        if (strcmp(cedulaPacientes[i], cedula) == 0)
        {
            pacienteEncontrado = 1;
            printf("Historial medico del paciente %s %s:\n", nombresPacientes[i], apellidosPacientes[i]);
            break;
        }
    }

    if (!pacienteEncontrado)
    {
        printf("Paciente no encontrado.\n");
        return;
    }

    for (int i = 0; i < totalCitas; i++)
    {
        if (strcmp(cedulaPacientesCitas[i], cedula) == 0)
        {
            printf("Fecha: %s, Medico: %s, Especialidad: %s, Sintomas: %s\n",
                   fechasCitas[i], cedulaMedicosCitas[i], especialidadesCitas[i], sintomasCitas[i]);
        }
    }
    getch();
}

void mostrarReportes()
{
    system("cls");
    printf("Reportes:\n");
    printf("1. Cantidad de pacientes atendidos: %d\n", totalCitas);

    // Enfermedad más común
    char enfermedadComun[100] = "";
    int maxFrecuencia = 0;
    for (int i = 0; i < totalCitas; i++)
    {
        int frecuencia = 0;
        for (int j = 0; j < totalCitas; j++)
        {
            if (strcmp(sintomasCitas[i], sintomasCitas[j]) == 0)
            {
                frecuencia++;
            }
        }
        if (frecuencia > maxFrecuencia)
        {
            maxFrecuencia = frecuencia;
            strcpy(enfermedadComun, sintomasCitas[i]);
        }
    }
    printf("2. Enfermedad mas comun: %s (%d casos)\n", enfermedadComun, maxFrecuencia);

    // Médico con más pacientes
    char medicoPopular[50] = "";
    maxFrecuencia = 0;
    for (int i = 0; i < totalMedicos; i++)
    {
        int frecuencia = 0;
        for (int j = 0; j < totalCitas; j++)
        {
            if (strcmp(cedulaMedicos[i], cedulaMedicosCitas[j]) == 0)
            {
                frecuencia++;
            }
        }
        if (frecuencia > maxFrecuencia)
        {
            maxFrecuencia = frecuencia;
            strcpy(medicoPopular, nombresMedicos[i]);
        }
    }
    printf("3. Medico con mas pacientes: %s (%d pacientes)\n", medicoPopular, maxFrecuencia);

    // Especialidad más solicitada
    char especialidadPopular[50] = "";
    maxFrecuencia = 0;
    for (int i = 0; i < totalMedicos; i++)
    {
        int frecuencia = 0;
        for (int j = 0; j < totalCitas; j++)
        {
            if (strcmp(especialidadesMedicos[i], especialidadesCitas[j]) == 0)
            {
                frecuencia++;
            }
        }
        if (frecuencia > maxFrecuencia)
        {
            maxFrecuencia = frecuencia;
            strcpy(especialidadPopular, especialidadesMedicos[i]);
        }
    }
    printf("4. Especialidad mas solicitada: %s (%d citas)\n", especialidadPopular, maxFrecuencia);
    getch();
}

void mostrarMenu()
{
    int opcion;
    do
    {
        system("cls");
        printf("\nHOSPITAL UTC\n");
        printf("1. Registro de Pacientes\n");
        printf("2. Registro de Medicos\n");
        printf("3. Programación de Consultas\n");
        printf("4. Historial Medico de Pacientes\n");
        printf("5. Reportes\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            registrarPaciente();
            break;
        case 2:
            registrarMedico();
            break;
        case 3:
            programarCita();
            break;
        case 4:
            historialMedico();
            break;
        case 5:
            mostrarReportes();
            break;
        case 6:
            printf("Saliendo del sistema...\n");
            break;
        default:
            printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 6);
}

int main()
{
    inicialiarVectores();
    mostrarMenu();
    return 0;
}
