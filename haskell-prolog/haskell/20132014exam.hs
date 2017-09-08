module Exam where

-- thirds, takes a list of values, any type
-- and returns a list of every third element
thirds :: [Int] -> [Int]
thirds [] = []
thirds (x:y:z:zs) 
	| length (x:y:z:zs) >= 3 = [z] ++ (thirds zs)
	| otherwise = []