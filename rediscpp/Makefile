BIN=redisclient 
CC=g++
SRC=redisclient.cpp  

ADDSRC=/home/lau/redis-cplusplus-client-master/anet.c
INCLUDE=-I /home/lau/project/hiredis/rediscpp -I/home/lau/boost_1_55_0/sdk/include/boost  -I /usr/include
LINK=-L/home/lau/boost_1_55_0/sdk/lib -lredisclient -L/usr/lib -ljson -L/usr/lib -lboost_thread 

$(BIN):$(SRC)
	@$(CC) -o $@ $^ $(ADDSRC) $(INCLUDE)  $(LINK) -g -D_DEBUG_
.PHONY:clean
clean:
	rm -rf core.*
	rm -rf $(BIN)
