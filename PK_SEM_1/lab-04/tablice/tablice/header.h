#pragma once
const int K = 10, W = 10;


/*
Kolorki Adam.T
1  - dark  Blue
2  - dark  green
3  -	   Cyan
4  - dark  Red
5  -	   Purple
6  - dark  Gold
7  - dark  White
8  -	   Grey
9  - Deep  Blue
10 - Light Green
11 - light Blue
12 -	   Red
13 -       Pink
14 -       Yellow
15 -       White
16 -	   Black
k*16 +kolor teksu  k- kolor tla  
*/
void color(const int &a);

int los(const int &a,const int &b);
void spirala( int tab[][K]);
void zygzak(int tab[][K]);