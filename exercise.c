#include "unity.h"
#include <string.h>

void romanFor(int arabicNumber,char *  romanStr){
	
	int arabicDict[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	char romanDict[][3]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int i;
	
	strcpy(romanStr,"");

	for(i=12;i>=0;i--)
	{
		while(arabicNumber>=arabicDict[i])
		{
		strcat(romanStr,romanDict[i]);
		arabicNumber-=arabicDict[i];
		}			
	}


    
}

/*------test helper-----*/
assertRoman(int arabicNumber,char *expectedRoman)
{
	char actualRoman[80];
	romanFor(arabicNumber,actualRoman);
    TEST_ASSERT_EQUAL_STRING(expectedRoman,actualRoman);	
}

/*------test Code ------*/
void arabic_1_is_roman_I(void)
{
    assertRoman(1, "I");
}

void arabic_2_is_roman_II(void)
{
    assertRoman(2, "II");
}

void arabic_3_is_roman_III(void)
{
    assertRoman(3, "III");
}

void arabic_4_is_roman_IV(void)
{
    assertRoman(4, "IV");
}

void arabic_5_is_roman_V(void)
{
    assertRoman(5, "V");
	
}

void arabic_6_is_roman_VI(void)
{
    assertRoman(6, "VI");
}
void arabic_7_is_roman_VII(void)
{
    assertRoman(7, "VII");
}
void acceptanceTest(void)
{
    assertRoman(1990, "MCMXC");
	assertRoman(2008, "MMVIII");
	assertRoman(99, "XCIX");
	assertRoman(47, "XLVII");
}
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(arabic_1_is_roman_I);
    RUN_TEST(arabic_2_is_roman_II);
    RUN_TEST(arabic_3_is_roman_III);
	RUN_TEST(arabic_4_is_roman_IV);
	RUN_TEST(arabic_5_is_roman_V);
	RUN_TEST(arabic_6_is_roman_VI);
	RUN_TEST(arabic_7_is_roman_VII);
	RUN_TEST(acceptanceTest);
    return UNITY_END();
}
