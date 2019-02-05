#include "unity.h"
#include "stdbool.h"

/* ----- production code ------ */
bool isItaLeapYear (int Year){
	
	 //("begin\n");
	if (Year % 4 == 0 )
	{
	    //printf("mod4\n");

		if (Year % 100 == 0 )
		{
			//printf("mod100\n");
			if(Year % 400 == 0)
			{
				//printf("mod400\n");
				return true;
			}
			else
			{
				//printf("elsemod400\n");
				return false;
			}
		}
		else
		{
			//printf("elsemod100 Year %d" , Year % 100);
			return true;
		}
	}
    else
	{
		//int c=Year % 4;
		//printf("elsemod4 Year %d \n" ,c );
		return false;
	}
}


/* ----- test code ------ */
void simpleNotLeapYear(void) {

int Year = 1930;
bool isLeapYearExpected = false;    
    
bool isLeapYearObtained = isItaLeapYear(Year);

TEST_ASSERT_EQUAL_UINT32(isLeapYearExpected,isLeapYearObtained);    
	
}

void simpleLeapYear(void) {

int Year = 2012;
bool isLeapYearExpected = true;    
    
bool isLeapYearObtained = isItaLeapYear(Year);

TEST_ASSERT_EQUAL_UINT32(isLeapYearExpected,isLeapYearObtained);    
	
}

void isLeapYear2000AC(void) {

int Year = 2000;
bool isLeapYearExpected = true;    
    
bool isLeapYearObtained = isItaLeapYear(Year);

TEST_ASSERT_EQUAL_UINT32(isLeapYearExpected,isLeapYearObtained);    
	
}

void isLeapYear1996AC(void) {

int Year = 1996;
bool isLeapYearExpected = true;    
    
bool isLeapYearObtained = isItaLeapYear(Year);

TEST_ASSERT_EQUAL_UINT32(isLeapYearExpected,isLeapYearObtained);    
	
}

void isLeapYear2001AC(void) {

int Year = 2001;
bool isLeapYearExpected = false;    
    
bool isLeapYearObtained = isItaLeapYear(Year);

TEST_ASSERT_EQUAL_UINT32(isLeapYearExpected,isLeapYearObtained);    
	
}

void isLeapYear1900AC(void) {

int Year = 1900;
bool isLeapYearExpected = false;    
    
bool isLeapYearObtained = isItaLeapYear(Year);

TEST_ASSERT_EQUAL_UINT32(isLeapYearExpected,isLeapYearObtained);    
	
}

/* ----- test runner ------ */
int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(simpleNotLeapYear);
	RUN_TEST(simpleLeapYear);
	RUN_TEST(isLeapYear2000AC);
	RUN_TEST(isLeapYear1900AC);
	RUN_TEST(isLeapYear1996AC);
	RUN_TEST(isLeapYear2001AC);
    // more RUN_TEST(*) lines....
    // more RUN_TEST(*) lines....

    return UNITY_END();
}
