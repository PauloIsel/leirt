#include <stdio.h>

#define MAX_N 80 // Máximo de caracteres do nome
#define MAX_T 1000 // Máximo de tarefas

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    int hours, minutes;
} Hour;

typedef struct {
    Date date;   // Data da tarefa
    Hour h_in;   // Hora de entrada
    Hour h_out;  // Hora de saída
} Task;

typedef struct {
    int id;               // Número do trabalhador
    char name[MAX_N];     // Nome do trabalhador
    Task tasks[MAX_T];    // Tarefas efetuadas
    int nTasks;           // Total de tarefas
} Worker;

int cmpData(Date d1, Date d2) {
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year > d2.year) {
        return 1;
    } else {
        if (d1.month < d2.month) {
            return -1;
        } else if (d1.month > d2.month) {
            return 1;
        } else {
            if (d1.day < d2.day) {
                return -1;
            } else if (d1.day > d2.day) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int countMinutesOfWork(Worker *w, Date dtInit, Date dtFinal) {
    int totalMinutes = 0;

    for (int i = 0; i < w->nTasks; i++) {
        Date taskDate = w->tasks[i].date;

        if (cmpData(taskDate, dtInit) >= 0 && cmpData(taskDate, dtFinal) <= 0) {
            Hour inTime = w->tasks[i].h_in;
            Hour outTime = w->tasks[i].h_out;

            totalMinutes += (outTime.hours * 60 + outTime.minutes) - (inTime.hours * 60 + inTime.minutes);
        }
    }

    return totalMinutes;
}

int moreWorkersThan(Worker w[], int nw, Date dtInit, Date dtFinal, int nMinutes, int id[]) {
    int count = 0;

    for (int i = 0; i < nw; i++) {
        int minutesWorked = countMinutesOfWork(&w[i], dtInit, dtFinal);

        if (minutesWorked > nMinutes) {
            id[count++] = w[i].id;
        }
    }

    return count;
}

int main() {
    // Example usage
    Worker workers[] = {
        {1, "John Doe", {{{2022, 1, 1}, {8, 0}, {12, 30}}, {{2022, 1, 2}, {9, 15}, {17, 45}}}, 2},
        {2, "Jane Doe", {{{2022, 1, 1}, {8, 30}, {14, 0}}, {{2022, 1, 2}, {10, 0}, {18, 0}}}, 2},
        // Add more workers as needed
    };

    Date startDate = {2022, 1, 1};
    Date endDate = {2022, 12, 31};

    int id[MAX_N];
    int result = moreWorkersThan(workers, 2, startDate, endDate, 300, id);

    printf("Number of workers with more than 300 minutes: %d\n", result);
    for (int i = 0; i < result; i++) {
        printf("Worker ID: %d\n", id[i]);
    }

    return 0;
}
