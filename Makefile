FLAGS = -pedantic-errors -std=c++11

animation.o: animation.cpp animation.h
	g++ $(FLAGS) -c $<

Posmove.o: Posmove.cpp Posmove.h
	g++ $(FLAGS) -c $<

CheckWin.o: CheckWin.cpp CheckWin.h
	g++ $(FLAGS) -c $<

checkmate.o: checkmate.cpp checkmate.h
	g++ $(FLAGS) -c $<

printboard.o: printboard.cpp printboard.h
	g++ $(FLAGS) -c $<

historynotes.o: historynotes.cpp historynotes.h
	g++ $(FLAGS) -c $<

playvscomp.o: playvscomp.cpp playvscomp.h
	g++ -std=c++11 -c $<

vsComp.o: vsComp.cpp vsComp.h
	g++ $(FLAGS) -c $<

play.o: play.cpp play.h
	g++ -std=c++11 -c $<

main.o: main.cpp animation.h Posmove.h CheckWin.h checkmate.h printboard.h historynotes.h playvscomp.h vsComp.h play.h
	g++ $(FLAGS) -c $<

main: animation.o Posmove.o CheckWin.o checkmate.o printboard.o historynotes.o playvscomp.o vsComp.o play.o main.o
	g++ $^ -o $@

clean:
	rm -f main main.o animation.o Posmove.o checkmate.o CheckWin.o printboard.o historynotes.o playvscomp.o vsComp.o play.o 

.PHONY: clean