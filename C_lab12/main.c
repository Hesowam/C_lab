#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX_YEAR 2020
#define MIN_YEAR 1970
typedef  struct {
    int day;
    int year;
    int month;
} sDate;

typedef struct {
    double minimal_temperature;
    double maximal_temperature;
} sTemperature;

typedef struct {
    int maximal_pressure;
    int minimal_pressure;
}sPressure;

typedef struct {
    sDate;
    sTemperature;
    sPressure;
}structureWeather ;
int random(int minimal, int maximal){
    srand((unsigned)time(NULL));
    return minimal + rand() % (maximal - minimal +1);
}
structureWeather * getWeatherList(n){
    structureWeather  * structureWeatherList = (structureWeather*)malloc(10 * sizeof(structureWeather));
    srand((unsigned)time(NULL));
    for (int i = 0; i<n; i++){
        structureWeatherList[i].day = 1 + rand() % (30 - 1 +1);
        structureWeatherList[i].month = 1 + rand() % (12 - 1 +1);
        structureWeatherList[i].year = random(MIN_YEAR,MAX_YEAR);
        double min_temp = random(1,50), max_temp = random(1,50);
        structureWeatherList[i].minimal_temperature = min(min_temp, max_temp);
        structureWeatherList[i].maximal_temperature = max(min_temp, max_temp);
        double min_pressure = random(600,800), max_pressure = random(600,800);
        structureWeatherList[i].maximal_pressure = max(min_pressure, max_pressure);
        structureWeatherList[i].minimal_pressure = min(min_pressure, max_pressure);
    }
    return structureWeatherList;
}

int main(){
    int n = 10;
    structureWeather  * structureWeatherList = (structureWeather*)malloc(10 * sizeof(structureWeather));
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; ++i) {
        structureWeatherList[i].day = 1 + rand() % (30 - 1 +1);
        structureWeatherList[i].month = 1 + rand() % (12 - 1 +1);
        structureWeatherList[i].year = random(MIN_YEAR,MAX_YEAR);
        double min_temp = 1 + rand() % (30 - 1 +1), max_temp = random(1,50);
        structureWeatherList[i].minimal_temperature = min(min_temp, max_temp);
        structureWeatherList[i].maximal_temperature = max(min_temp, max_temp);
        double min_pressure = random(600,800), max_pressure = random(600,800);
        structureWeatherList[i].maximal_pressure = max(min_pressure, max_pressure);
        structureWeatherList[i].minimal_pressure = min(min_pressure, max_pressure);
    }
    printf("+---------------------------------------------------------------------------------+\n");
    for (int i = 0; i < n; i++) {
        printf("|%10i |%10i |%10i |%1f |%1f |%10i |%10i |\n",
                structureWeatherList[i].year, structureWeatherList[i].month, structureWeatherList[i].day,
               structureWeatherList[i].minimal_temperature, structureWeatherList[i].maximal_temperature,
               structureWeatherList[i].minimal_pressure, structureWeatherList[i].maximal_pressure);
        printf("+---------------------------------------------------------------------------------+\n");
    }
}