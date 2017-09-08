qsort [] = []
qsort (x:xs) = (qsort smalls) ++ [x] ++ (qsort bigs)
	where
	smalls = [val | val <- xs, val <= x]
	bigs = [val | val <- xs, val > x]
	