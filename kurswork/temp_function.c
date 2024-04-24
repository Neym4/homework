
#include "temp_function.h"

int read_csv_file(const char *filename, TemperatureData **data_array, int *num_rows) {
    setlocale(LC_ALL, "RUS");
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Ошибка открытия файла %s\n", filename);
        return -1;
    }

    *data_array = malloc(sizeof(TemperatureData));
    if (*data_array == NULL) {
        fprintf(stderr, "Ошибка: невозможно выделить память для массива структур\n");
        fclose(file);
        return -1;
    }

    *num_rows = 0;
    int line_number = 0; 
    char buffer[256]; 
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strlen(buffer) <= 1) { 
            continue;
        }

        int result = sscanf(buffer, "%d;%d;%d;%d;%d;%d", 
                            &((*data_array)[*num_rows].year),
                            &((*data_array)[*num_rows].month),
                            &((*data_array)[*num_rows].day),
                            &((*data_array)[*num_rows].hour),
                            &((*data_array)[*num_rows].minute),
                            &((*data_array)[*num_rows].temperature));

        if (result == 6) {
            (*num_rows)++;

            TemperatureData *tmp = realloc(*data_array, (*num_rows + 1) * sizeof(TemperatureData));
            if (tmp == NULL) {
                fprintf(stderr, "Ошибка: невозможно выделить память для массива структур\n");
                fclose(file);
                free(*data_array);
                return -1;
            }
            *data_array = tmp;
        } else {
            fprintf(stderr, "Неправильный формат строки в файле %s на строке %d\n", filename, line_number + 1);
        }

        line_number++;
    }

    fclose(file);
    return line_number; 
}

void print_monthly_statistics(const TemperatureData *data_array, int num_rows, int target_month) {
    setlocale(LC_ALL, "RUS");

    int month_count[MAX_MONTHS] = {0}; 
    int month_sum[MAX_MONTHS] = {0};   
    int month_min[MAX_MONTHS];  
    int month_max[MAX_MONTHS]; 

    for (int i = 0; i < num_rows; i++) {
        int month_index = data_array[i].month - 1; 

        month_count[month_index]++;
        month_sum[month_index] += data_array[i].temperature;

        if (month_count[month_index] == 1) { 
            month_min[month_index] = data_array[i].temperature;
            month_max[month_index] = data_array[i].temperature;
        } else {
            if (data_array[i].temperature < month_min[month_index]) {
                month_min[month_index] = data_array[i].temperature;
            }
            if (data_array[i].temperature > month_max[month_index]) {
                month_max[month_index] = data_array[i].temperature;
            }
        }
    }

    printf("Статистика по месяцам:\n");
    if (target_month == 0) {
        for (int i = 0; i < MAX_MONTHS; i++) {
            if (month_count[i] > 0) {
                printf("Месяц %d:\n", i + 1);
                printf("  Средняя температура: %.2f\n", (float)month_sum[i] / month_count[i]);
                if (month_min[i] == month_max[i]) {
                    printf("  Минимальная/Максимальная температура: %d\n", month_min[i]);
                } else {
                    printf("  Минимальная температура: %d\n", month_min[i]);
                    printf("  Максимальная температура: %d\n", month_max[i]);
                }
            }
        }
    } else {
        int index = target_month - 1;
        if (month_count[index] > 0) {
            printf("Статистика для месяца %d:\n", target_month);
            printf("  Средняя температура: %.2f\n", (float)month_sum[index] / month_count[index]);
            if (month_min[index] == month_max[index]) {
                printf("  Минимальная/Максимальная температура: %d\n", month_min[index]);
            } else {
                printf("  Минимальная температура: %d\n", month_min[index]);
                printf("  Максимальная температура: %d\n", month_max[index]);
            }
        } else {
            printf("Данные отсутствуют для указанного месяца.\n");
        }
    }
}

void print_yearly_statistics(const TemperatureData *data_array, int num_rows) {
    setlocale(LC_ALL, "RUS");
    int year_sum = 0;   
    int year_min = 99;  
    int year_max = -99; 

    for (int i = 0; i < num_rows; i++) {
        year_sum += data_array[i].temperature;

        if (data_array[i].temperature < year_min) {
            year_min = data_array[i].temperature;
        }

        if (data_array[i].temperature > year_max) {
            year_max = data_array[i].temperature;
        }
    }

    printf("Статистика за год:\n");
    printf("  Среднегодовая температура: %.2f\n", (float)year_sum / num_rows);
    printf("  Минимальная температура: %d\n", year_min);
    printf("  Максимальная температура: %d\n", year_max);
}

void print_temperature_data(const TemperatureData *data_array, int num_rows) {
    printf("%-4s %-6s %-4s %-4s %-6s %-11s\n", 
           "Год", "Месяц", "День", "Час", "Минута", "Температура");
    for (int i = 0; i < num_rows; ++i) {
        printf("%-4d %-6d %-4d %-4d %-6d %-11d\n", 
               data_array[i].year, 
               data_array[i].month, 
               data_array[i].day, 
               data_array[i].hour, 
               data_array[i].minute, 
               data_array[i].temperature);
    }
}
