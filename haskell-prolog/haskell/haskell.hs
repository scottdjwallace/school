module Haskell where

runningSums :: [Int] -> [Int]
runningSums (x:xs) = runningHelper xs [x] x

runningHelper :: [Int] -> [Int] -> Int -> [Int]
runningHelper [] sums _ = sums 
runningHelper (x:xs) sums previous = runningHelper xs (sums ++ [x+previous]) (x+previous)

mystery = map (+3) (5: mystery)

check x y = mod (5*x + 2*y) 3 == 0

nums = 1:3:(zipWith (+) nums (tail nums))