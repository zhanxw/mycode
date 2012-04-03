EXE = test_exprtk gen_test test_mathpresso test_muParserX test_muParser test_embedPython

all: $(EXE)
test_exprtk: test_exprtk.cpp
	g++ -o $@ $<
gen_test: gen_test.cpp

LIB_MU = /net/fantasia/home/zhanxw/mycode/mathExpression/software/muparserx-read-only/bin/libmuparserx.a
test_muParserX: test_muParserX.cpp
	g++ -o $@ $< $(LIB_MU)

LIB_MUX = /net/fantasia/home/zhanxw/mycode/mathExpression/software/muparser_v2_2_2/lib/libmuparser.a
test_muParser: test_muParser.cpp
	g++ -o $@ $< $(LIB_MUX)


LIB = /net/fantasia/home/zhanxw/mycode/mathExpression/software/mathpresso/Build/CMakeFiles/exptest.dir/MathPresso/lib-MathPress.a /net/fantasia/home/zhanxw/mycode/mathExpression/software/mathpresso/MathPresso/libAsmJit.so
test_mathpresso.o: test_mathpresso.cpp
	g++ -c $<
test_mathpresso: test_mathpresso.o	
	g++ -o $@ $< $(LIB)

PYTHON_INC = /net/fantasia/home/zhanxw/python27/include/python2.7
PYTHON_LIB = /net/fantasia/home/zhanxw/python27/lib/libpython2.7.a
test_embedPython.o: test_embedPython.cpp
	g++ -c $<  -I$(PYTHON_INC) 
test_embedPython: test_embedPython.o
	g++ -o $@ $< $(PYTHON_LIB) -Xlinker -export-dynamic -ldl -lrt -lutil
