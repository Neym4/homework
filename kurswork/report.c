#include "temp_function.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "RUS");
    if (argc < 2 || strcmp(argv[1], "-h") == 0) {
        printf("Описание функционала приложения:\n");
        printf("Список ключей, которые обрабатывает данное приложение и их назначение:\n");
        printf("  -f <filename.csv> : входной файл csv для обработки\n");
        printf("  -m <номер месяца> : если задан данный ключ, то выводится только статистика за указанный месяц\n");
        printf("  -h : выдать описание функционала приложения\n");
        printf("  -y : вывести статистику за год\n");
        printf("  -a : вывести все значения\n");
        return 0;
    }

    char *filename = NULL;
    int month = 0;
    TemperatureData *data_array;
    int num_rows;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                filename = argv[i + 1];
                read_csv_file(filename, &data_array, &num_rows);
                if (i + 2 < argc && strcmp(argv[i + 2], "-m") == 0) {
                    if (i + 3 < argc) {
                        month = atoi(argv[i + 3]);
                        print_monthly_statistics(data_array, num_rows, month);
                    } else {
                        printf("Ошибка: не указан номер месяца\n");
                        return -1;
                    }
                } else if (i + 2 < argc && strcmp(argv[i + 2], "-y") == 0) {
                    print_yearly_statistics(data_array, num_rows);
                } else {
                    print_monthly_statistics(data_array, num_rows, 0);
                    print_yearly_statistics(data_array, num_rows);
                }
                break;
            } else {
                printf("Ошибка: не указано имя файла\n");
                return -1;
            }
        }else if (strcmp(argv[i], "-a") == 0) {
            if (i + 1 < argc) {
                filename = argv[i + 1];
                read_csv_file(filename, &data_array, &num_rows);
                print_temperature_data(data_array, num_rows);
            }
        }
    }

    if (filename == NULL) {
        printf("Ошибка: не указано имя файла\n");
        return -1;
    }

    free(data_array); 
    return 0;
}
