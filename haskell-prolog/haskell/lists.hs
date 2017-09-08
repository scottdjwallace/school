{-
 - Practicing with lists and lists comprehensions
 -}

module Lists where

import Data.Char


--
-- LIST COMPREHENSIONS
--

-- Input: [2,5,6,10,13]
-- Output: [6, 16]
returnNums numz = [z+1 | z<-numz, mod z 5 == 0, mod z 2 /= 0]
-- every z in our list numz, that is a multiple of 5 and odd, then return that +1
-- format of comprehesion
-- [return this | put elements of list into z, conditions that have to be met]


--
-- PRELUDE FUNCTIONS AND OPERATORS
-- 

-- length [3,2,6] --> 3
-- length "computer" --> 8

-- reverse [5..10] --> [10,9,8,7,6,5]
-- reverse "computer" --> "retupmoc"

-- sum [1,2,3] --> 6
-- sum [2.3, 4.3] -> 6.6

-- (:) 
-- 3 : [2,3] --> [3,2,3]
-- (3:) [2,3] --> [3,2,3]

-- (++)
-- [1,2] ++ [3,4] --> [1,2,3,4]

-- show -- converts to a string
-- show 12.34 --> "12.34"
-- show [1,2,3] --> "[1,2,3]"

-- read -- string to int
-- (read "123") --> 123 

-- isSingle :: [a] -> Bool
-- true if singleton list

-- 
-- EXERCISES
--

-- firstOdd
firstOdd :: [Int] -> Int
firstOdd [] = 0
firstOdd (x:xs) 
	| mod x 2 /= 0 = x
	| otherwise = firstOdd xs

-- capitalize
capitalize :: String -> String
capitalize "" = ""
capitalize str = [toUpper ch | ch <- str]