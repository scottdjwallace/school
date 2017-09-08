module Exam where

-- Exam Breakdown
-- 2x haskell & prolog simple functions
-- haskell - proof, data type, output of high order
-- prolog - rules, output with cuts/negation, searching

-- thirds, takes a list of values, any type
-- and returns a list of every third element
thirds :: [Int] -> [Int]
thirds [] = []
thirds [a] = []
thirds [a,b] = []
thirds (x:y:z:zs) = [z] ++ (thirds zs)

-- subSquareMax takes a list of lists of Intsts
-- returns max of each sublist and returns the sum of squares of those maxs
subSquareMax :: [ [Int] ] -> Int
subSquareMax [] = 0
subSquareMax (x:xs) = a * a + (subSquareMax xs)
	where 
		a = maxOfList x 0

maxOfList :: [Int] -> Int -> Int
maxOfList [] x = x
maxOfList (x:xs) n
	| n < x = maxOfList xs x
	| otherwise = maxOfList xs n

-- Algebraic Types
data Tree = MakeTree String [Tree]

mom = MakeTree "Helen" [
		MakeTree "Marge" [
		MakeTree "Carol" [],
		MakeTree "Val" [],
		MakeTree "Ian" []
		],
		MakeTree "Barb" []
 	]

-- proof
doubleAll [] = []
doubleAll (x:xs) = 2*x : doubleAll xs
sum1 [] = 0
sum1 (x:xs) = x + sum1 xs

{-
	Prove: sum (doubleAll lis) == 2 * (sum lis)
	
	1. Base Case, make lis = []
	sum (doubleAll []) == 2 * (sum [])
	sum [] = 0 
	2 * sum [] = 0

	2.  Inductive Step
	Assume it holds for all finite lis
	Want to prove it holds for x:lis

	3. Proving Inductive Step
	sum (doubleAll (x:lis)) == 2 * (sum (x:lis))
	LHS 
		sum (2*x : doubleAll lis) rule 2
		2*x + sum (doubleAll lis)
	RHS
		2 * (x + sum lis) rule 4
		2*x + 2 * sum lis
		use inductive step to prove
-}

lazy = 1 : (zipWith (\x y -> x+y+1) lazy (map (2*) lazy))
