#include "unity.h"

/* ----- production code ------ */
int convertFahrenheit2Celsius (int Fahrenheit){

    return (Fahrenheit-32)*5/9;
    
}


/* ----- production  code ------ */
int convertCelsius2Fahrenheit(int Celsius) {
 
    return (Celsius*9/5)+32;

}


/* ----- Test  code ------ */
void convert_20Celsius_TO_68Fahrenheit(void) {
int Celsius = 20;
int expected_result = 68;    
    
int Fahrenheit = convertCelsius2Fahrenheit(Celsius);

TEST_ASSERT_EQUAL_UINT32(expected_result,Fahrenheit);    
}

void convert_30Celsius_TO_86Fahrenheit(void) {
int Celsius = 30;
int expected_result = 86;    
    
int Fahrenheit = convertCelsius2Fahrenheit(Celsius);

TEST_ASSERT_EQUAL_UINT32(expected_result,Fahrenheit);    
}

void convert_Minus10Celsius_TO_14Fahrenheit(void) {
int Celsius = -10;
int expected_result = 14;    
    
int Fahrenheit = convertCelsius2Fahrenheit(Celsius);

TEST_ASSERT_EQUAL_UINT32(expected_result,Fahrenheit);    
}

void convert_20Fahrenheit_TO_Minus6pt67Celsius(void) {
int Fahrenheit = 20;
int expected_result = -6.67;    
    
int Celsius = convertFahrenheit2Celsius(Fahrenheit);

TEST_ASSERT_FLOAT_WITHIN(0.5,expected_result,Celsius);    
}

void convert_113Fahrenheit_TO_45Celsius(void) {
int Fahrenheit = 113;
int expected_result = 45;    
    
int Celsius = convertFahrenheit2Celsius(Fahrenheit);

TEST_ASSERT_EQUAL_UINT32(expected_result,Celsius);    
}

void convert_77Fahrenheit_TO_25Celsius(void) {
int Fahrenheit = 77;
int expected_result = 25;    
    
int Celsius = convertFahrenheit2Celsius(Fahrenheit);

TEST_ASSERT_EQUAL_UINT32(expected_result,Celsius);    
}

/* ----- test runner ------ */
int main(void) {
    
    UNITY_BEGIN();
    
    RUN_TEST(convert_20Celsius_TO_68Fahrenheit);
    RUN_TEST(convert_30Celsius_TO_86Fahrenheit);
    RUN_TEST(convert_Minus10Celsius_TO_14Fahrenheit);
    
    RUN_TEST(convert_20Fahrenheit_TO_Minus6pt67Celsius);
    RUN_TEST(convert_113Fahrenheit_TO_45Celsius);
    RUN_TEST(convert_77Fahrenheit_TO_25Celsius);
    
      
    return UNITY_END();
}
