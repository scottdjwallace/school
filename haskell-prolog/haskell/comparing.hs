overlap :: Int -> Int -> Int -> Int -> Bool
overlap sf ef ss es
	| errorCheck sf ef ss es == False = error "Illegal input."
	| (ss < ef) && (ss > sf) = True
	| (sf < es) && (sf > ss) = True
	| otherwise = False

-- returns false for an error
errorCheck :: Int -> Int -> Int -> Int -> Bool
errorCheck sf ef ss es
	| (sf < 0) || (sf > 23) = False
	| (ef < 0) || (ef > 23) = False
	| (ss < 0) || (ss > 23) = False
	| (es < 0) || (es > 23) = False
	| (ef - sf) < 0 = False
	| (es - ss) < 0 = False
	| otherwise = True