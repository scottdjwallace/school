{-
 	Page 76: 5.1, 5.2 - DONE
    Page 79: 5.6, 5.7
    Page 82: 5.8 - 5.11
    Page 119: 7.1 - 7.3
    Page 120: 7.4,7.5 (The functions in this set are defined in the Prelude, so you'll have to "hide" them or use different 
        function names if you want to test your solutions)
    Page 125: 7.6, 7.7, 7.8, 7.13
    Page 128: 7.14, 7.16, 7.17, 7.18
    Page 132-133: 7.20, 7.25, 7.26
-}
import Data.Char

maxOccurs :: Int -> Int -> (Int,Int)
maxOccurs a b 
	| a == b = (a,2)
	| otherwise = (m, 1)
	where 
		m = max a b

-- Brute Force
maxThreeOccurs :: Int -> Int -> Int -> (Int,Int)
maxThreeOccurs x y z
	| x == y && x == z = (x,3)
	| x == y && x > z = (x,2)
	| x == y && z > x = (z,1)
	| x == z && x > y = (x,2)
	| x == z && y > x = (y,1)
	| y == z && y > x = (y,2)
	| y == z && x > y = (x,1)
	| x > y && x > z = (x,1)
	| y > x && y > z = (y,1)
	| otherwise = (z,1)



orderTriple :: (Int,Int,Int) -> (Int,Int,Int)
orderTriple (x,y,z) 
	= (mn,mid,mx)
	where 
		mx = maxThree x y z
		mid = middle x y z
		mn = minThree x y z

	
maxThree :: Int -> Int -> Int -> Int
maxThree a b c = max (max a b) c

middle :: Int -> Int -> Int -> Int
middle a b c
	| a >= b && a <= c = a
	| a <= b && a >= c = a
	| b >= a && b <= c = b
	| b <= a && b >= c = b
	| otherwise = c

minThree :: Int -> Int -> Int -> Int
minThree a b c = min (min a b) c

items :: [Int] -> Int
items [] = 0
items list
	= 1 + items (tail list)  

{-
 - [[2,3]] is a list of lists
 - ^ has 1 item in the list
 -
 - [2 .. 2] => [2]
 - [2,7 .. 4] => [2]
 - [2,2..2] => a lot of [2,2,2,2,2,2,2....] 
 -} 

doubleAll :: [Int] -> [Int]
doubleAll [] = []
doubleAll xs = [x*2 | x<-xs]

divisors :: Int -> [Int]
divisors 0 = []
divisors x = divisorHelper x 1 []

divisorHelper :: Int -> Int -> [Int] -> [Int]
divisorHelper x y list
	| (x == y) = y : list
	| mod x y == 0 = divisorHelper x (y+1) (y : list)
	| otherwise = divisorHelper x (y+1) list

isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = True
isPrime n
	| n < 1 = False
	| length (divisors n) == 2 = True
	| otherwise = False

capitalized :: String -> String
capitalized [] = []
capitalized (head:tail) = toUpper head : map toLower tail

capsLock :: String -> String
capsLock str = map toUpper str

onThreeLines :: String -> String -> String -> String
onThreeLines w1 w2 w3 = w1 ++ "\n" ++ w2 ++ "\n" ++ w3

duplicate :: String -> Int -> String
duplicate s x 
	| x == 0 = s
	| otherwise = duplicate (s ++ s) (x-1)  

