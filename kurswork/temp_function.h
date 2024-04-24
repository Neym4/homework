#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#define MAX_MONTHS 12  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureData;

int read_csv_file(const char *filename, TemperatureData **data_array, int *num_rows);

void print_monthly_statistics(const TemperatureData *data_array, int num_rows, int target_month);

void print_yearly_statistics(const TemperatureData *data_array, int num_rows);

void print_temperature_data(const TemperatureData *data_array, int num_rows);

#endif
