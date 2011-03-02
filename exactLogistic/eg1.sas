data dose;
input Dose Deaths Total @@;
datalines;
0 0 3
1 0 3
2 0 3
3 0 3
4 1 3
5 2 3
;
run;
proc logistic data=dose descending;
model Deaths/Total = Dose;
exact Dose / estimate=both outdist=eg1outdist;
run;
proc print data = eg1outdist;
run;

