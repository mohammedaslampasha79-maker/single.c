// QUIZ GAME PROJECT
// Author: <Aslam Pasha>
// Description:
//     This program allows users to play a quiz game with 3 levels:
//     Easy, Medium, and Hard. Each round contains 4 questions.
//     User scores are recorded & displayed in a scoreboard.
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>  // for sleep()
int main() {
    // Question bank for Easy Level
    char easyq[][100] = {
        "1. Which planet is known as the Red Planet?",
        "2. How many days are there in a leap year?",
        "3. What is the largest mammal in the world?",
        "4. Which gas do plants release during photosynthesis?"
    };
    // Options for Easy level
    char easyo[][100] = {
        "A. Earth\nB. Venus\nC. Mars\nD. Jupiter",
        "A. 365\nB. 366\nC. 360\nD. 364",
        "A. Elephant\nB. Blue Whale\nC. Shark\nD. Giraffe",
        "A. Oxygen\nB. Carbon dioxide\nC. Nitrogen\nD. Hydrogen"
    };
    // Correct answers for Easy level
    char easyans[] = {'C', 'B', 'B', 'A'};
    // Question bank for Medium Level
    char medq[][100] = {
        "1. Who wrote the national anthem of India?",
        "2. Which country is known as the Land of the Rising Sun?",
        "3. Which country has the highest population?",
        "4. Which is the longest river in the world?"
    };
    // Options for Medium level
    char medo[][100] = {
        "A. Rabindranath Tagore\nB. Mahatma Gandhi\nC. Subhas Chandra Bose\nD. Nehru",
        "A. China\nB. Japan\nC. Korea\nD. Thailand",
        "A. India\nB. China\nC. United States\nD. Indonesia",
        "A. Nile\nB. Amazon\nC. Ganga\nD. Yangtze"
    };
    // Correct answers for Medium level
    char medans[] = {'A', 'B', 'B', 'A'};
    // Question bank for Hard Level
    char hardq[][100] = {
        "1. What is the smallest bone in the human body?",
        "2. Which Indian missile is called the 'Agni'?",
        "3. Who proposed the theory of relativity?",
        "4. Which element has the highest melting point?"
    };
    // Options for Hard level
    char hardo[][100] = {
        "A. Femur\nB. Stapes\nC. Ulna\nD. Tibia",
        "A. Surface-to-air\nB. Ballistic\nC. Cruise\nD. Anti-tank",
        "A. Newton\nB. Einstein\nC. Tesla\nD. Maxwell",
        "A. Gold\nB. Iron\nC. Tungsten\nD. Platinum"
    };
    // Correct answers for Hard level
    char hardans[] = {'B', 'B', 'B', 'C'};
    // Quiz game variables
    int questioncount = 4;
    char guess = '\0';
    int scores[100];          // Store scores of each attempt
    float percentages[100];   // Store percentage of each attempt
    int attempts = 0;
    char playAgain;
    int level;
    // MAIN GAME LOOP (user can play multiple rounds)
    do {
        int score = 0; // reset score every round
        // Display welcome screen & instructions
        printf("         =====================================\n");
        printf("                  WELCOME TO QUIZ GAME        \n");
        printf("         =====================================\n");
        printf("\nInstructions:\n");
        printf("1. Choose a difficulty level: Easy, Medium, or Hard.\n");
        printf("2. Each question has 4 options: A, B, C, and D.\n");
        printf("3. Type the letter of your answer and press Enter.\n");
        printf("4. Correct answer = +1 point.\n");
        printf("5. Wrong answer = -1 point.\n");
        printf("6. You can play multiple rounds; all results will be stored.\n");
        printf("7. At the end, your Scoreboard will be displayed.\n");
        printf("8. At the end of the quiz, you can receive prizes!\n");
        printf("---------------------------------------------\n");
        printf("\nPress ENTER to START the quiz...");
        getchar(); // waits for Enter key
        // Choose difficulty level
        printf("\nChoose Your Difficulty Level:\n");
        printf("1. Easy\n2. Medium\n3. Hard\n");
        printf("Enter choice (1 to 3): ");
        scanf("%d", &level);
        printf("\nYou have chosen level %d\n",level);
        printf("\nLevel %d Starting in...\n", level);
        // Countdown timer
        for (int t = 3; t > 0; t--) {
            printf("%d...\n", t);
            sleep(1);
        }
        // Display questions and validate answers
        for (int i = 0; i < questioncount; i++) {
            // Print question and options based on level
            if (level == 1) {
                printf("\n%s\n", easyq[i]);
                printf("\n%s\n", easyo[i]);
            } else if (level == 2) {
                printf("\n%s\n", medq[i]);
                printf("\n%s\n", medo[i]);
            } else if (level == 3) {
                printf("\n%s\n", hardq[i]);
                printf("\n%s\n", hardo[i]);
            } else {
                printf("Invalid choice!\n");
                break;
            }
            // Take user answer
            printf("\nEnter your guess: ");
            scanf(" %c", &guess);
            guess = toupper(guess); // convert to uppercase
            // Compare answers and update score
            if ((level == 1 && guess == easyans[i]) ||
                (level == 2 && guess == medans[i]) ||
                (level == 3 && guess == hardans[i])) {
                printf("\nCORRECT!\n");
                score++;
            } else {
                printf("\nWRONG!\n");
                score--;
            }
        }
        // Store final score & percentage for this attempt
        scores[attempts] = score;
        percentages[attempts] = (score * 100.0f) / questioncount;
        attempts++;
        // Display score
        printf("\n your score is %d out of %d\n",score, questioncount);
        // Prize Logic
        printf("\nPrize Received:\n");
        if (score == 4)
            printf("Gold Medal + Certificate of Excellence!\n");
        else if (score == 3)
            printf("Silver Medal + Achievement Badge!\n");
        else if (score == 2)
            printf("Bronze Medal!\n");
        else if (score == 1)
            printf("Participation Badge!\n");
        else if (score == 0)
            printf("Try Again Token!\n");
        else
            printf("No Prize Received!\n");
        // Play again or exit
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);

    } while (playAgain == 'Y');
    // Display Final Scoreboar
    printf("\n =======================\n");
    printf("          SCOREBOARD     \n");
    printf(" =======================\n");
    printf("Attempt\tScore\tPercentage\n");
    for (int i = 0; i < attempts; i++) {
        printf("%d\t%d/%d\t%.2f%%\n",
               i + 1,
               scores[i],
               questioncount,
               percentages[i]);
    }
    // Exit message with countdown
    printf("\nExiting the Quiz in...\n");
    for (int k = 3; k > 0; k--) {
        printf(" %d...\n", k);
        sleep(1);
    }
    printf("=============================================\n");
    printf("             THANK YOU FOR PLAYING!          \n");
    printf("=============================================\n");
    printf("Keep learning, keep exploring, and come back soon!\n");
    printf("=============================================\n");

    return 0;
}
