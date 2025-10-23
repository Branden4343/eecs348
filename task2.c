#include <stdio.h>

double toCelsius(double t, char s) { // Converts the given temperature to Celsius
    if (s == 'C' || s == 'c') return t;
    else if (s == 'F' || s == 'f') return (t - 32) * 5.0 / 9.0;
    else if (s == 'K' || s == 'k') return t - 273.15;
    else { printf("Invalid input scale.\n"); return 0; }
}

double fromCelsius(double tC, char s) { // Converts the given temperature from Celsius to either Fahrenheit or Kelvin
    if (s == 'C' || s == 'c') return tC;
    else if (s == 'F' || s == 'f') return (tC * 9.0 / 5.0) + 32;
    else if (s == 'K' || s == 'k') return tC + 273.15;
    else { printf("Invalid target scale.\n"); return 0; }
}

void categorize(double tC) {
    if (tC < 0)
        printf("Temperature category: Freezing\nWeather advisory: Stay warm and avoid ice!\n");
    else if (tC < 10)
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket.\n");
    else if (tC < 25)
        printf("Temperature category: Comfortable\nWeather advisory: Enjoy the nice weather!\n");
    else if (tC < 35)
        printf("Temperature category: Hot\nWeather advisory: Drink lots of water!\n");
    else
        printf("Temperature category: Extreme Heat\nWeather advisory: Stay indoors and stay hydrated!\n");
}

int main() {
    double temp, result, tempC;
    char inScale, outScale;

    printf("Enter the temperature value: "); // Asks for the user input temperature
    scanf("%lf", &temp);
    printf("Enter the original scale (C, F, or K): "); // Asks for the user input scale
    scanf(" %c", &inScale);
    printf("Enter the scale to convert to (C, F, or K): "); // Asks for the user input scale to convert to
    scanf(" %c", &outScale);

    tempC = toCelsius(temp, inScale);
    result = fromCelsius(tempC, outScale);

    printf("Converted temperature: %.2f %c\n", result, outScale); // Returns the converted temperature
    categorize(tempC);
    return 0;
}
