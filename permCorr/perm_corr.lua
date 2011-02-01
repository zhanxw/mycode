#!/home/zhanxw/bin/lua5.1
X, Y = {}, {}
N = 0
for line in io.lines("inputX") do
   N = N + 1
   X[N] = tonumber(line)
end
N = 0
for line in io.lines("inputY") do
   N = N + 1
   Y[N] = tonumber(line)
end

local function mean(x)
   local sum = 0.0
   for i = 1, N do sum = sum + x[i] end
   return (sum/N)
end

local function std(x)
   local m = mean(x)
   --print("mean", m)
   local sum_xx = 0.0
   for i = 1, N do
      x[i] = x[i] - m
      sum_xx =  sum_xx + (x[i] * x[i])
   end
   return math.sqrt(sum_xx/(N-1))
end

local function cor(x,y)
   local c = 0.0
   for i = 1, N do
      c = c + x[i] * y[i]
   end
   return c/(N-1)
end

local function shuffle(x)
   local t
   for i = N, 2, -1 do
      j = math.random(i) -- 1 <= j <= i
      t = x[i]
      x[i] = x[j]
      x[j] = t
   end
end

times = tonumber(arg and arg[1]) or  1
print("shuffle times = ", times)
local std_x = std(X)
--print(std_x)
local std_y = std(Y)
--print(std_y)
for i = 1, times do
   local corr_xy = cor(X, Y)
   shuffle(Y)
   print(corr_xy/(std_x*std_y))
end
