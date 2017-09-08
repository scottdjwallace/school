module Quiz2 where

-- 5.1

maxOccurs :: Int -> Int -> (Int, Int)
maxOccurs a b
	| a == b = (a, 2)
	| a > b = (a, 1)
	| otherwise = (b, 1)

maxThreeOccurs :: Int -> Int -> Int -> (Int, Int)
maxThreeOccurs a b c
	| a == b && a == c = (a, 3)
	| a == b && a > c = (a, 2)
	| a == c && a > b = (a, 2)
	| a > b && a > c = (a, 1)
	| otherwise = maxThreeOccurs b c a

-- 5.2 

orderTriple :: (Int, Int, Int) -> (Int, Int, Int)
orderTriple (a, b, c) = (x, y, z)
	where 
		x = minThree a b c
		y = middle a b c
		z = maxThree a b c

maxThree :: Int -> Int -> Int -> Int
maxThree a b c 
	| a >= b && a >= c = a
	| otherwise = maxThree b c a

middle :: Int -> Int -> Int -> Int
middle a b c
	| a <= b && a >= c = a
	| a >= b && a <= c = a
	| otherwise = middle b c a

minThree :: Int -> Int -> Int -> Int
minThree a b c 
	| a <= b && a <= c = a
	| otherwise = minThree b c a

-- 5.6

-- [2,3] - 2
-- [[2,3]] - 1
-- [[2,3]] - [[Int]]

-- 5.7

-- [2..2] - [2]
-- [2,7..4] - [2]
-- [2,2..2] - [2 -- infinitty]

-- 5.8

doubleAll :: [Int] -> [Int]
doubleAll [] = []
doubleAll (x:xs) = 2*x : doubleAll xs

isPrime :: Int -> Int -> Bool
isPrime x n
	| mod x n == 0 = True
	| otherwise = False

-- 7.4 
{-
product :: [Int] -> Int
product [] = 1
product (x:xs) = x * (product xs)
-}
q3E x y z = (x+z):y

q3F x y z w = y (z w x)



