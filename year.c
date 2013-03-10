#include<stdio.h>
/* 判断两个日期相差多少天 */
/*             run   1   2   3   4   5   6   7   8   9  10  11  12*/
int days[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int judge(int year)
{
  if(year % 400 == 0){
    return 1;
  }else if(year % 100 == 0){
    return 0;
  }else if(year % 4 == 0){
    return 1;
  }
  return 0;
}
int main()
{
  int year1, mouth1, day1;
  int year2, mouth2, day2;
  int sum = 0;
  while(1){
    printf("begin year: yyyy-mm-dd\n");
    scanf("%d-%d-%d", &year1, &mouth1, &day1);
    printf("end year: yyyy-mm-dd\n");
    scanf("%d-%d-%d", &year2, &mouth2, &day2);
    int i;
    for(i = yeanr1+1; i < year2; i++){
      if(judge(i)){
        sum += 366;
      }else{
        sum += 365;
      }
    }
    if(year1 == year2){         
      for(i = mouth1+1; i < mouth2; i++)
        if(i==2 && judge(year1) == 1) sum += days[0];
        else sum += days[i];

    }else{
      for(i = mouth1+1; i <= 12; i++)
        if(i==2 && judge(year1) == 1) sum += days[0];
        else sum += days[i];
      
      for(i = 1; i < mouth2; i++)
        if(i==2 && judge(year2) == 1) sum += days[0];
        else sum += days[i];

    }
    if(mouth1 == 2 && judge(year1))
      sum += (29 - day1);
    else
      sum += (days[mouth1] - day1);
      
    sum += day2;
    printf("sum: %d\n", sum);
    sum = 0;
  }
  return 0;
}
