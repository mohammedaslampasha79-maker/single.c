# single.c
This is our C Project
# project title
QUIZ GAME
## objective
The objective of this project is to create an interactive C language quiz game where users can select a difficulty level (Easy, Medium, or Hard) and answer a set of questions. The program evaluates responses, calculates scores, displays prizes, and finally shows a scoreboard summarizing all attempts.
This C program allows users to play a quiz game consisting of three difficulty levels:

Easy Level – Basic knowledge questions

Medium Level – General knowledge questions

Hard Level – Advanced general science questions

Each level contains 4 questions with 4 multiple-choice options, and the program:

Accepts user inputs

Validates answers

Tracks score

Shows prizes based on performance

Stores multiple attempts

Displays a full scoreboard at the end

The game includes a countdown timer, uppercase answer validation, and prize logic.
## how to Compile and run the programe
1.Open a terminal
2.Compile: 'gcc single.c'
3.Run: './a'
## Important notes/assumptions
The program uses the sleep() function for countdown timers.

Works normally on Linux/Mac.

Windows users must install MinGW (GCC) or use an online compiler for smooth execution.

The quiz contains 3 difficulty levels: Easy, Medium, and Hard — each level has 4 questions.

The program accepts answers in a case-insensitive manner (e.g., a and A considered the same).

Scoring rules are fixed:

+1 point for a correct answer

−1 point for a wrong answer

Maximum possible score per round: 4 points
Minimum possible score: −4 points

After each round, the program stores the score and percentage, which are shown later in a Scoreboard.

The scoreboard displays:

Attempt number

Score out of 4

Percentage

Users can play the quiz multiple times in a single session.

Inputs must be valid:

Difficulty level → 1, 2, or 3

Answer choice → A, B, C, or D

Invalid level input stops the round and prints an “Invalid choice” message.

All quiz questions, options, and answers are stored in arrays.

Prizes are awarded based on score:

4 → Gold Medal

3 → Silver Medal

2 → Bronze Medal

1 → Participation Badge

0 → Try Again Token

Below 0 → No Prize

The program runs in a terminal/command-line interface only (no GUI).

All user inputs must be followed by pressing the Enter key.

The game ends with a countdown exit animation for a better user experience.
