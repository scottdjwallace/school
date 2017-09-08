corner(union,barrie).

route([]).
route([A]).
route([X,Y|Ys]) :-
	checkIntersection(X,Y),
	route([Y|Ys]).

checkIntersection(corner(A,B),corner(C,D)) :- A = C ; A = D ; B = C ; B = D.

solid(a,b).
solid(b,c).
solid(c,d).
solid(d,e).
solid(f,e).

dashed(b,d).
dashed(c,f).
dashed(e,a).
dashed(e,f).

% review searching

route2([]).
route2([corner(_,_)]).
route2([corner(A,B),corner(C,D)|Lis]) :-
	A = C ; A = D ; B = C ; B = D,
	route2([corner(C,D)|Lis]).

listSection([X,_Y|Tail],[X|NewTail]) :- listSection(Tail,NewTail),!.
listSection([],[]).
listSection([Z],[Z]).
listSection([_Head|Tail], NewTail) :-
	listSection(Tail, NewTail).

% 6A - [a], []
% 6B - [a],[b],[]
% 6C - [a,c],[a],[b],[c],[]
% 6D - [d], []
% 6E - [d]
% 6F - [d,f]

runningSums([],[]). 
runningSums([X],[X]).
runningSums([X,Y|Tail],[X|Zs]) :-
	A is X+Y,
	runningSums([A|Tail],Zs).

changeList([],[]).
changeList([X],[X]).
changeList([X,Y],[X,Y]).
changeList([X,Y,Z|Tail],[Z|NewTail]) :-
	X < Y,
	changeList(Tail,NewTail).
changeList([X,Y,Z|Tail],[X|NewTail]) :-
	Y < Z,
	changeList(Tail,NewTail).
changeList([X,Y,Z|Tail],[Y|NewTail]) :-
	X < Z,
	changeList(Tail,NewTail).

puzzle([1,Num|_],Num).
puzzle([6,Num|_],Num).
puzzle([_|Xs],Num) :-
	puzzle(Xs,Num), !.
