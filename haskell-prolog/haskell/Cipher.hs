import Data.Char

cipher :: Char -> Int -> Char
cipher ch i 
	| (i < 0) || (i > 25) = error "Invalid range"
	|  