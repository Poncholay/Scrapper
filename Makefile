##
## Makefile for Makefile in /Users/noboud_n/rendu/cpp_plazza
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Tue Apr 12 14:58:00 2016 Nyrandone Noboud-Inpeng
## Last update Thu Apr 21 16:48:44 2016 guillaume wilmot
##

SRC	= ClientSocket.cpp		\
	  ClientSocketLocal.cpp		\
	  CommunicationError.cpp	\
	  CondThread.cpp		\
	  CondVar.cpp			\
	  Core.cpp			\
	  CryptCaesar.cpp		\
	  CryptXor.cpp			\
	  Errors.cpp			\
	  Listener.cpp			\
	  ParseAv.cpp			\
	  Parsing.cpp			\
	  Pipes.cpp			\
	  PipeOut.cpp			\
	  PipeIn.cpp			\
	  Process.cpp			\
	  ReadAndFind.cpp		\
          Search.cpp			\
	  ServeurSocket.cpp		\
	  ServeurSocketLocal.cpp	\
	  Sockets.cpp			\
          SocketsLocal.cpp		\
	  Thread.cpp			\
	  ThreadPool.cpp		\
	  Timer.cpp			\
	  TimerError.cpp		\
          Regex.cpp			\
	  RegexError.cpp		\
	  UsageError.cpp

SRCMAIN	= $(SRC)			\
	  Main.cpp			\
	  Displayer.cpp

SRCUI	= $(SRC)			\
	  Gui.cpp			\
	  MainGui.cpp			\
	  MenuFiles.cpp			\
	  MenuTasks.cpp			\
	  DisplayerGui.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRCMAIN:.cpp=.o))
OBJUI	= $(addprefix $(OBJDIR), $(SRCUI:.cpp=.o))

RM	= rm -f

CXX	= g++ -std=c++11 -g

NAME	= plazza
GUI	= gui

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/

MAKEOBJ	= obj

LDFLAGS 	+= -lpthread -lboost_regex -lrt
UIFLAGS 	= $(LDFLAGS) -lmenu -lncurses
CXXFLAGS	+= -W -Wall -Wextra -Werror

all:
	@make --no-print-directory $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(MAKEOBJ)
	$(CXX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

$(GUI):  $(OBJUI)
	$(CXX) -o $(GUI) $(OBJUI) $(UIFLAGS)

ui:
	@make --no-print-directory $(GUI)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJUI)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(GUI)

re: fclean all
