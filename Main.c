#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

char version[] = "0.1b"; //If store such as char version = "0.1b" will produce an error
double matrixbonus[3][3] = { {-1.0,-1,-1} , {-1,-1,-1} , {-1,-1,-1} };
double matrixposition[3][3] = { {-1,-1,-1} , {-1,-1,-1} , {-1,-1,-1} };
int main() {
  /*
  Define main menu GUI
  */
  srand(time(NULL));
  int numplayer;
  printf("Welcome to TacTokToe! \nVersion %s \n\n\n",version);
  int turncount = 0;
  printf("Type amount of player:\n");
  scanf("%d", &numplayer);
    /*
  End of Define main menu GUI
  */
  //printf("Your number is: %d\n", numplayer); // for debug
  //showtable(turncount); //for debug
  createbonustable(); //create a bonus table
  if (numplayer == 1) {
    singleplayer();
  } else if (numplayer == 2) {
    printf("Coming Soon!");
  } else if (numplayer == 0) {
    botplayer();
  }
    
    
}
void createbonustable(){
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        matrixbonus[i][j] = -2.0 + 0.5 * (rand() % 9);
    }
    
}
  //showtable(0,matrixbonus);
}


void showtable(int turncount, double mat[3][3]) {
  int i, j;
  printf("Current Turn Count: %d\n",turncount);
  printf("----------\n");
  for (i = 0; i < 3; i++) {

    printf("|");
    for (j = 0; j < 3; j++) {
    printf(" %.2f ", mat[i][j]);
    printf("|");
    }
    printf("\n");
    printf("----------\n");
  }
}
void singleplayer() {
    int humanmark, botmark;
    int r, c;
    int mark = rand() % 2;
    float humanscore = 0;
    float botscore = 0;
    humanmark = (mark == 1) ? 1 : 0;
    botmark   = 1 - humanmark;

    for (int turn = 0; turn < 3; turn++) {

        // ===== PLAYER TURN =====
        do {
            printf("This is Player Turn\n");
            printf("Enter Row Column (0-2): ");
            scanf("%d %d", &r, &c);
        } while (r < 0 || r > 2 || c < 0 || c > 2 || matrixposition[r][c] != -1);
        printf("Player Chose %d,%d!\n",r,c);
        matrixposition[r][c] = humanmark;

        // ===== BOT TURN =====
        do {
            srand(time(NULL));
            r = rand() % 3;
            srand(time(NULL));
            c = rand() % 3;
        } while (matrixposition[r][c] != -1);

        matrixposition[r][c] = botmark;
        printf("Computer Chose %d,%d!\n",r,c);

        showtable(0, matrixposition);
    }
    //Calculate score part //Human 
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (matrixposition[i][j] == humanmark){
          humanscore += matrixbonus[i][j]; 
        } else if (matrixposition[i][j] == botmark){
          botscore += matrixbonus[i][j]; 
        }
        
    }

    
  }
  printf("≡≡≡Summary≡≡≡\n");
  printf("Human Score: %f\n",humanscore);
  printf("botscore: %f\n\n\n",botscore);
  if (humanscore > botscore) {
    printf("\n ≡≡≡PLAYER Wins!≡≡≡≡\n");
  } else if (humanscore == botscore){
    printf("\n ≡≡≡TIES!≡≡≡≡\n");
  }else if (humanscore < botscore){
    printf("\n ≡≡≡Computer Wins!≡≡≡≡\n");
  }
}
void delay(int number_of_seconds)
{
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds)
		;
}
void botplayer() { //retains same logic and variable // just didffers at how the postition for first player is obtained
    int bot1mark, bot2mark;
    int r, c;
    int mark = rand() % 2;
    float bot1score = 0;
    float bot2score = 0;
    bot1mark = (mark == 1) ? 1 : 0;
    bot2mark   = 1 - bot1mark;

    for (int turn = 0; turn < 3; turn++) {

        // ===== Computer 1 TURN =====
        do {
            printf("This is Computer1 Turn\n");
            srand(time(NULL));
            r = rand() % 3;
            srand(time(NULL));
            c = rand() % 3;
            delay(1);

        } while (r < 0 || r > 2 || c < 0 || c > 2 || matrixposition[r][c] != -1);

        matrixposition[r][c] = bot1mark;
        printf("Computer 1 Chose %d,%d!\n",r,c);

        // ===== Computer 2 TURN =====
        do {
            printf("This is Computer2 Turn\n");
            srand(time(NULL));
            r = rand() % 3;
            srand(time(NULL));
            c = rand() % 3;
            delay(1);
        } while (matrixposition[r][c] != -1);

        matrixposition[r][c] = bot2mark;
        printf("Computer 2 Chose %d,%d!\n",r,c);

        showtable(0, matrixposition);
    }
    //Calculate score part //Human 
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (matrixposition[i][j] == bot1mark){
          bot1score += matrixbonus[i][j]; 
        } else if (matrixposition[i][j] == bot2mark){
          bot2score += matrixbonus[i][j]; 
        }
        
    }

    
  }
  printf("≡≡≡Summary≡≡≡\n");
  printf("Computer 1 Score: %f\n",bot1score);
  printf("Computer 2 Score: %f\n\n\n",bot2score);
  if (bot1score > bot2score) {
    printf("\n ≡≡≡Computer 1 Wins!≡≡≡≡\n");
  } else if (bot1score == bot2score){
    printf("\n ≡≡≡TIES!≡≡≡≡\n");
  }else if (bot1score < bot2score){
    printf("\n ≡≡≡Computer 2 Wins!≡≡≡≡\n");
  }
}
