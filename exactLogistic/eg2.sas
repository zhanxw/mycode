data dose;
input y x0 x1 @@;
datalines;
0 1 1
1 1 1 
0 1 2
1 1 0
;
run;
proc logistic data=dose descending;
model y = x0 x1;
exact x0 / estimate=both;
exact x1 / estimate = both;
run;
