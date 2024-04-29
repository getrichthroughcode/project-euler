#include <stdio.h>
#include <stdlib.h>

int number_days (int m, int y){
    switch (m) {
    case 2:
      if ((y%4 == 0 && y%100 != 0) || y%400 == 0) {
        return 29;
      }
      else {
        return 28;
      }
      
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;

    default:
      return 31;
  }
}


int main(){
    int out = 0, f_day = 0;
    for(int y = 1901; y < 2001; y++){
        for (int m = 1; m < 13; m++){
            if (f_day == 5){
                out++;
            }
            f_day = (f_day + number_days(m,y))%7;
        }
    }
    printf("%d\n",out);
    return 1;
}