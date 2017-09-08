smaller(x,[],[])
smaller(x,[y|ys],[y|Smalls]) :-
	y =< x,
	smaller(x,ys,Smalls).

smaller(x,[y|ys], Smalls) :-
	y > x,
	smaller(x,ys,Smalls)