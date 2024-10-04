#include <stdio.h>

void findCombos(int score) {
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);// iterates through each possiblity of score combos with in the given score, then only prints the ones that fit
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
        for (int td1pt = 0; td2pt * 8 + td1pt * 7 <= score; td1pt++) {
            for (int td = 0; td2pt * 8 + td1pt * 7 + td * 6 <= score; td++) {
                for (int fg = 0; td2pt * 8 + td1pt * 7 + td * 6 + fg * 3 <= score; fg++) {
                    for (int safety = 0; td2pt * 8 + td1pt * 7 + td * 6 + fg * 3 + safety * 2 <= score; safety++) {
                        if (td2pt * 8 + td1pt * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                    td2pt, td1pt, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {//loops until user inputs 1 or 0
    //asks user for score then calls findCombinations to print the combos that match
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }

        findCombos(score);
    }

    return 0;
}
