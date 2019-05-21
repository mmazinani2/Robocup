SRCS = $(wildcard Connection/*.cpp Connection/*.h AI/*.cpp AI/*.h WorldModel/*.cpp WorldModel/*.h Formation/*.cpp Formation/*.h Geometry/*.cpp Geometry/*.h Parser/*.cpp Parser/*.h Commander/*.cpp Commander/*.h Skill/*.cpp Skill/*.h Run/*.cpp Run/*.h Sensor/*.cpp Sensor/*.h Types/*.cpp Types/*.h Util/*.cpp Util/*.h Loger/*.cpp Loger/*.h   GameModel/*.h GameModel/*.cpp)
SRC = $(wildcard Connection/*.cpp Connection/*.h AI/*.cpp AI/*.h WorldModel/*.cpp WorldModel/*.h Formation/*.cpp Formation/*.h Geometry/*.cpp Geometry/*.h Parser/*.cpp Parser/*.h Commander/*.cpp Commander/*.h Skill/*.cpp Skill/*.h  Sensor/*.cpp Sensor/*.h Types/*.cpp Types/*.h Util/*.cpp Util/*.h Loger/*.cpp Loger/*.h Coach/*.cpp  GameModel/*.h GameModel/*.cpp)
OBJS = $(SRCS:.cpp=.o)
OBJ = $(SRC:.cpp=.o)
CC=$(Connection/)
CXXFLAGS = -O5  -fmessage-length=0 -MMD -MP
LIBFLAGS = -lpthread
Agent : $(OBJS)
	g++ $(CXXFLAGS) $(LIBFLAGS) $(OBJS) -o $@

%.o: %.cpp
	g++ -O3 -c -fmessage-length=0 -MMD -MP -MF$(@:%.o=%.d) -MT$(@:%.o=%.d)  $< -o $@

CoachAgent : $(OBJ)
	g++ $(CXXFLAGS) $(LIBFLAGS) $(OBJ) -o $@ 
%.o: %.cpp
	g++ -O3 -c -fmessage-length=0 -MMD -MP -MF$(@:%.o=%.d) -MT$(@:%.o=%.d)  $< -o $@ 

clean:
	rm -f Connection/*.o Connection/*. Connection/*.cpp~ Connection/*.h~ AI/*.o AI/*. AI/*.cpp~ AI/*.h~ WorldModel/*.o *. WorldModel/*.cpp~ WorldModel/*.h~ Formation/*.o Formation/*. Formation/*.cpp~ Formation/*.h~ Geometry/*.o Geometry/*. Geometry/*.cpp~ Geometry/*.h~ Parser/*.o Parser/*. Parser/*.cpp~ Parser/*.h~ Commander/*.o Commander/*. Commander/*.cpp~ Commander/*.h~ Skill/*.o Skill/*. Skill/*.cpp~ Skill/*.h~ Run/*.o Run/*. Run/*.cpp~ Run/*.h~ Sensor/*.o Sensor/*. Sensor/*.cpp~ Sensor/*.h~ Types/*.o Types/*. Types/*.cpp~ Types/*.h~ Util/*.o Util/*. Util/*.cpp~ Util/*.h~ Loger/*.o Loger/*. Loger/*.cpp~ Loger/*.h~ Connection/*.d AI/*.d WorldModel/*.d Formation/*.d Geometry/*.d Parser/*.d Commander/*.d Skill/*.d Run/*.d Sensor/*.d Types/*.d Util/*.d Loger/*.d
	rm -f Coach/*.o Coach/*. Coach/*.cpp~ Coach/*.h~  Thread/*.o Thread/*.h~ Thread/*.cpp~ GameModel/*.o GameModel/*.cpp~ GameModel/*.h~
	rm Agent
	rm CoachAgent
	
all: clean Agent
	cp Agent /usr/local/bin
	cp Coach1 /usr/local/bin
copy: Agent
	cp Agent /usr/local/bin
	cp Coach1 /usr/local/bin
