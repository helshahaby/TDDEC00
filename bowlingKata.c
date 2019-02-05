#include "unity.h"
#include "stdlib.h"
#include "string.h"

#define FRAMES_PER_GAME 10

static int gameScore =-1;
static int rolls[21];//worst case last strike : 20-1+2 
static int nextIndex=0;


/* ----- production code ------ */
void initGame (void){
	nextIndex=0;
memset(rolls,0,sizeof(rolls));//avoid segmentation errors
}

void roll (int pins){
    rolls[nextIndex]=pins;
	nextIndex++;
}

int getScore (void){
	
	int i;
	int thisBall=0;
	int total =0;
	
	for( i=0 ; i< FRAMES_PER_GAME ; i++){
		if(rolls[thisBall]+rolls[thisBall+1]==10)
		{
			total += 10+rolls[thisBall+2];	
			thisBall += 2;
		}
		else if(rolls[thisBall]==10)
		{
			total += 10+rolls[thisBall+1]+rolls[thisBall+2];
			thisBall ++;
		}
		else
		{
			total+=rolls[thisBall]+rolls[thisBall+1];	
			thisBall += 2;
		}
		
		
	}
	return total;
}

/* ----- test code ------ */
void gutter_score_is_0(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(0); //gutter
	
	//Then
	TEST_ASSERT_EQUAL_INT(0,getScore());
}

void open_frame_score_is_sum_of_rolls(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(3);
	roll(4);
	
	//Then
	TEST_ASSERT_EQUAL_INT(7,getScore());
}


void spare_score_adds_next_roll(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(7);
	roll(3);
	roll(4);
	
	//Then
	TEST_ASSERT_EQUAL_INT(18,getScore());
}

void ten_in_two_frames_is_not_a_spare(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(2);
	roll(7);
	roll(3);
	roll(4);
	
	//Then
	TEST_ASSERT_EQUAL_INT(16,getScore());
}

void stike_adds_next_two_rolls(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(2);
	roll(7);
	roll(10);
	roll(4);
	roll(5);
	
	//Then
	TEST_ASSERT_EQUAL_INT(37,getScore());
}

void nabil_fights_riham(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(2);
	roll(7);
	roll(0);
	roll(10);//spare
	roll(5);
	roll(3);
	
	//Then
	TEST_ASSERT_EQUAL_INT(32,getScore());
}

void bonus_for_spare_adds_one_extra_roll(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);
	
	roll(0);
	roll(0);	
	
	roll(5);
	roll(5);
	
	roll(2);
	
	//Then
	TEST_ASSERT_EQUAL_INT(12,getScore());
}

void perfect_game_score_is_300(void) {

	//given a new game
	initGame();
	
	//When I hit no pins
	roll(10);
	roll(10);
	
	roll(10);
	roll(10);
	
	roll(10);
	roll(10);
	
	roll(10);
	roll(10);
	
	roll(10);
	roll(10);
	
	roll(10);
	roll(10);
	
	
	//Then
	TEST_ASSERT_EQUAL_INT(300,getScore());
}
/* ----- test runner ------ */
int main(void) {
    UNITY_BEGIN();
    
  RUN_TEST(gutter_score_is_0);
	RUN_TEST(open_frame_score_is_sum_of_rolls);
	RUN_TEST(spare_score_adds_next_roll);
	RUN_TEST(ten_in_two_frames_is_not_a_spare);
	RUN_TEST(stike_adds_next_two_rolls);
	RUN_TEST(nabil_fights_riham);
	RUN_TEST(bonus_for_spare_adds_one_extra_roll);
	RUN_TEST(perfect_game_score_is_300);
    // more RUN_TEST(*) lines....
    // more RUN_TEST(*) lines....

    return UNITY_END();
}
