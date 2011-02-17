data example;
    infile "inputXY" delimiter=',';
    input X0 X1 Y;
run;

proc logistic data = example;
    model y = x1;
    exact x1 / estimate = both outdist = out;
run;
proc print data = out;
run;

