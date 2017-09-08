sortPerm(List, sortedList) :-
	permutation(List, sortedList),
	ordered(sortedList).

ordered([_]).
ordered([]).
ordered([x,y|xs]) :-
	x =< y,
	ordered([y|xs]).

