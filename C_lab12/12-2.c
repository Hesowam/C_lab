#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_YEAR 2020
#define MIN_YEAR 1970
typedef struct {
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
} sPressure;

typedef struct {
    sDate date;
    sTemperature temperature;
    sPressure pressure;
} structureWeather;

int randomValue(int minimal, int maximal) {
    return minimal + rand() % (maximal - minimal + 1);

}

int minValue(a, b) {
    if (a > b) { return b; }
    return a;
}

int maxValue(a, b) {
    if (a < b) { return b; }
    return a;
}

structureWeather *getWeatherList(n) {
    structureWeather *structureWeatherList = (structureWeather *) malloc(10 * sizeof(structureWeather));
    for (int i = 0; i < n; i++) {
        structureWeatherList[i].date.day = randomValue(1, 30);
        structureWeatherList[i].date.month = randomValue(1, 12);
        structureWeatherList[i].date.year = randomValue(MIN_YEAR, MAX_YEAR);
        int min_temp = randomValue(1, 50), max_temp = randomValue(1, 50);
        structureWeatherList[i].temperature.minimal_temperature = minValue(min_temp, max_temp);
        structureWeatherList[i].temperature.maximal_temperature = maxValue(min_temp, max_temp);
        int min_pressure = randomValue(600, 800), max_pressure = randomValue(600, 800);
        structureWeatherList[i].pressure.maximal_pressure = maxValue(min_pressure, max_pressure);
        structureWeatherList[i].pressure.minimal_pressure = minValue(min_pressure, max_pressure);
    }
    return structureWeatherList;
}

structureWeather getMidWeather(structureWeather *structureWeatherList, int n) {
    structureWeather maxMidWeather = structureWeatherList[0];
    int maxMid = -100;
    for (int i = 0; i < n; i++) {
        double mid = (structureWeatherList[i].temperature.minimal_temperature +
                      structureWeatherList[i].temperature.maximal_temperature) / 2;
        if (mid > maxMid) {
            maxMid = mid;
            maxMidWeather = structureWeatherList[i];
        }
    }
    return maxMidWeather;
}

int main() {
    srand((unsigned) time(NULL));
    int n = 10;
    structureWeather *structureWeatherList = (structureWeather *) malloc(10 * sizeof(structureWeather));
    structureWeatherList = getWeatherList(n);
    printf("| Year | Month | Day | Min. Temperature | Max. Temperature | Min. Pressure | Max. Pressure |\n");
    printf("+---------------------------------------------------------------------------------+\n");
    for (int i = 0; i < n; i++) {
        printf("|%10i |%10i |%10i |%1f |%1f |%10i |%10i |\n",
               structureWeatherList[i].date.year, structureWeatherList[i].date.month, structureWeatherList[i].date.day,
               structureWeatherList[i].temperature.minimal_temperature,
               structureWeatherList[i].temperature.maximal_temperature,
               structureWeatherList[i].pressure.minimal_pressure, structureWeatherList[i].pressure.maximal_pressure);
        printf("+---------------------------------------------------------------------------------+\n");
    }
    structureWeatherList = getWeatherList(n, structureWeatherList);
    printf("| The month with the highest average air temperature |\n");
    printf("+---------------------------------------------------------------------------------+\n");
    printf("|%10i |%10i |%10i |%1f |%1f |%10i |%10i |\n",
           structureWeatherList[0].date.year, structureWeatherList[0].date.month, structureWeatherList[0].date.day,
           structureWeatherList[0].temperature.minimal_temperature,
           structureWeatherList[0].temperature.maximal_temperature,
           structureWeatherList[0].pressure.minimal_pressure, structureWeatherList[0].pressure.maximal_pressure);
    printf("+---------------------------------------------------------------------------------+\n");
}