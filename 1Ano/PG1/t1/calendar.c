#include <stdio.h>

// Calcula os dias do mês com base no mês e no ano
int get_month_days(int year, int month) {
    int days;

    switch (month) {
        case 2:
            // Verifica se o ano é bissexto
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                days = 29;
            } else {
                days = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
    }

    return days;
}

int showCalendar(int year, int month, int first_week_day) {
    char *months[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int days = get_month_days(year, month);
    int week_day = first_week_day;

    printf("%s %d\n", months[month - 1], year); // Mostra o mês e o ano na consola
    printf("    D  S  T  Q  Q  S  S\n"); // Mostra os dias da semana na consola

    // Adiciona espaços de acordo com o primeiro dia do mês de forma a ficar alinhado no primeiro dia
    for (int i = 0; i < first_week_day; i++) {
        printf("   ");
    }

    // Adiciona um espaço só para o alinhamento inicial
    printf("   ");
    for (int i = 1; i <= days; i++) {
        // Adiciona um espaço se for o primeiro dia da semana e se não for o primeiro dia do mês derivado a esse espaço já ser introduzido antes do loop
        if (week_day == 0 && i != 1) {
            printf("   ");
        }

        // Mostra o dia
        printf("%2d ", i);

        // Se estivermos no último dia da semana passa para a próxima linha e volta a meter o dia da semana no início. Se não só aumenta
        if (week_day == 6) {
            printf("\n");
            week_day = 0;
        } else {
            week_day++;
        }
    }

    printf("\n\n");
    return week_day;
}

int main() {
    int year, month, first_week_day;

    // Pergunta o ano, mês e dia ao utilizador
    printf("Qual o ano? ");
    scanf("%d", &year);

    printf("Qual o mes? ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Mes inválido\n");
        return 1;
    }

    printf("Qual o dia da semana? ");
    scanf("%d", &first_week_day);

    if (first_week_day < 0 || first_week_day > 6) {
        printf("Primeiro dia da semana invalido\n");
        return 1;
    }

    while (month <= 12) {
        // Mostra o calendário do mês em questão, atualiza o dia da semana de acordo com o resultado que saiu da função showCalendar e passa para o próximo mês
        int new_week_day = showCalendar(year, month, first_week_day);
        first_week_day = new_week_day;
        month++;
    }

    return 0;
}