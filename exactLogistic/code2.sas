data youna;
    infile "youna";
    input no race$ pheno$ age;
run;

data x1; 
    infile "inputXY.modify"; 
    input X0 X1 Y; 
run; 

data all;
    merge youna x1;
run;

proc print data = all;
run;

proc logistic data = all; 
  class race;
  model Y = X1 age race; 
  exact X1 / estimate = both;
run; 

proc logistic data = all; 
  model Y = X1 ;
  exact X1 / estimate = both; 
run; 

