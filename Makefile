
CXX = g++
CXX_FLAGS = -I include/

CXX_FLAGS_OBJ = ${CXX_FLAGS} -c

BUILD_DIR = build

SRC_DIR = src

OBJS = ${BUILD_DIR}/Node.o ${BUILD_DIR}/Directory.o ${BUILD_DIR}/File.o

all: ${BUILD_DIR}


${BUILD_DIR}: ${BUILD_DIR}/main
	mkdir -p ${BUILD_DIR}


${BUILD_DIR}/main: ${SRC_DIR}/main.cpp ${OBJS}
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/Node.o: ${SRC_DIR}/Node.cpp
	${CXX} -o $@ ${CXX_FLAGS_OBJ} $^ 

${BUILD_DIR}/Directory.o: ${BUILD_DIR}/Node.o ${SRC_DIR}/Directory.cpp
	${CXX} -o $@ ${CXX_FLAGS_OBJ} $^ 

${BUILD_DIR}/File.o: ${BUILD_DIR}/Node.o ${SRC_DIR}/File.cpp
	${CXX} -o $@ ${CXX_FLAGS_OBJ}  $^ 

