#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Bubble.o \
	${OBJECTDIR}/PhysObj.o \
	${OBJECTDIR}/Model.o \
	${OBJECTDIR}/Fish.o \
	${OBJECTDIR}/QuadTree.o \
	${OBJECTDIR}/BoundingBox.o \
	${OBJECTDIR}/vmath.o \
	${OBJECTDIR}/Background.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lGL -lglut -lpng -lGLU
CXXFLAGS=-lGL -lglut -lpng -lGLU

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fishy

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fishy: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fishy ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Bubble.o: nbproject/Makefile-${CND_CONF}.mk Bubble.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Bubble.o Bubble.cpp

${OBJECTDIR}/PhysObj.o: nbproject/Makefile-${CND_CONF}.mk PhysObj.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/PhysObj.o PhysObj.cpp

${OBJECTDIR}/Model.o: nbproject/Makefile-${CND_CONF}.mk Model.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Model.o Model.cpp

${OBJECTDIR}/Fish.o: nbproject/Makefile-${CND_CONF}.mk Fish.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Fish.o Fish.cpp

${OBJECTDIR}/QuadTree.o: nbproject/Makefile-${CND_CONF}.mk QuadTree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/QuadTree.o QuadTree.cpp

${OBJECTDIR}/BoundingBox.o: nbproject/Makefile-${CND_CONF}.mk BoundingBox.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/BoundingBox.o BoundingBox.cpp

${OBJECTDIR}/vmath.o: nbproject/Makefile-${CND_CONF}.mk vmath.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/vmath.o vmath.cpp

${OBJECTDIR}/Background.o: nbproject/Makefile-${CND_CONF}.mk Background.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Background.o Background.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fishy

# Subprojects
.clean-subprojects:
