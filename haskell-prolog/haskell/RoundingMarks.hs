{-
	Grade boundaries
	50% - C
	65% - B
	80% - A

	Never give 48,49,64,79

-}

roundMark :: Float -> Int
roundMark x 
	| x <= 0 = 0
	| x >= 100 = 100 
	| (round x) == 48 = 50
	| (round x) == 49 = 50
	| (round x) == 64 = 65
	| (round x) == 79 = 80
	| otherwise = round x 


-- a b c f
letterGrade :: Float -> Char
letterGrade x
	| (roundMark x) < 50 = 'F'
	| (roundMark x) < 65 = 'C'
	| (roundMark x) < 80 = 'B'
	| (roundMark x) < 100 = 'A'
	| otherwise = 'Z'
