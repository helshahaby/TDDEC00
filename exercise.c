#include "unity.h"

/* ----- production code ------ */
void some_production_code (void){

}


/* ----- test code ------ */
void some_test(void) {

}

/* ----- test runner ------ */
int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(some_test);
    // more RUN_TEST(*) lines....
    // more RUN_TEST(*) lines....

    return UNITY_END();
}
