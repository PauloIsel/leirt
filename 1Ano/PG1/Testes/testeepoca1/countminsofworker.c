#include <stdio.h>

#define MAX_N 80 //Máximo de caracteres do nome
#define MAX_T 1000 //Máximo de tarefas

typedef struct {
 int day, month, year;
} Date;

typedef struct {
 int hours, minutes;
} Hour;

typedef struct {
 Date date; // Data da tarefa
 Hour h_in; // Hora de entrada
 Hour h_out; // Hora de saída
} Task;

typedef struct {
 int id; // número do trabalhador
 char name[MAX_N]; // nome do trabalhador
 Task tasks[MAX_T]; // tarefas efetuadas
 int nTasks; // total de tarefas
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

int countMinutesOfWorker(Worker *w, Date dtInit, Date dtFinal) {
    int workedmins = 0;

    for(int i = 0; i < w->nTasks; i++) {
        Date taskdate = w->tasks[i].date;

        if(cmpData(taskdate, dtInit) >= 0 && cmpData(taskdate, dtFinal) <= 0) {
            Hour taskh_in = w->tasks[i].h_in;
            Hour taskh_out = w->tasks[i].h_out;

            workedmins += (taskh_out.hours * 60 + taskh_out.minutes) - (taskh_in.hours * 60 + taskh_in.minutes);
        }
    }
    return workedmins;
}


int main() {
    // Exemplo de uso
    Worker worker = {
        .id = 1,
        .name = "John Doe",
        .nTasks = 2,
        .tasks = {
            {{2022, 1, 1}, {8, 0}, {12, 30}},
            {{2022, 1, 2}, {9, 15}, {17, 45}},
        },
    };

    Date startDate = {2022, 1, 1};
    Date endDate = {2022, 12, 31};

    int totalMinutes = countMinutesOfWorker(&worker, startDate, endDate);

    printf("Total minutes worked: %d\n", totalMinutes);

    return 0;
}