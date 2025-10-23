#include <stdio.h>

int main() {
    int score;
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): "); // Prompts the user to enter an NFL score or one to stop
        scanf("%d", &score);
        if (score == 1) { // If one is entered the program ends
            printf("Program terminated.\n");
            break;
        }
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score); // If not one, all possible combinations are calculated below
        for (int td2 = 0; td2 * 8 <= score; td2++) {// TD + 2 point converstion = 8 points
            for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) {// TD + 1 extra point kick = 8 points
                for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) { // TD = 6 points
                    for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) { // Field Goal = 3 points
                        for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; safety++) { // Defensive Safety = 2 points
                            int total = td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2;
                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
