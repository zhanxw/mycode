#!/usr/bin/python
import sys, os

class EightQueenProblem:
    def __init__(self):
        self.count = 8
        self.solution = [0 for i in range(self.count)]
    def printSolution(self):
        print "Solution: ", self.solution
    def solve(self):
        self.queen(0)

    def queen(self, n): # place queen at self.solution[n] place
        if n == 8:
            self.printSolution()
            return
        for i in range(8):
            self.solution[n] = i
            if self.solutionValid(n):
                self.queen(n+1)

    def solutionValid(self, n):
        for i in range(n):
            if (self.solution[n] == self.solution[i]): return False
            if (self.solution[n] - self.solution[i] == n - i  or
                self.solution[n] - self.solution[i] == i - n): return False
        return True

eqp = EightQueenProblem()
eqp.solve()
