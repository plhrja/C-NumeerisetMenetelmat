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
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/mutils.o \
	${OBJECTDIR}/src/myeigen.o \
	${OBJECTDIR}/src/w1/exc101.o \
	${OBJECTDIR}/src/w1/exc102.o \
	${OBJECTDIR}/src/w1/exc104.o \
	${OBJECTDIR}/src/w1/exc104.o \
	${OBJECTDIR}/src/w1/exc105.o \
	${OBJECTDIR}/src/w2/exc201.o \
	${OBJECTDIR}/src/w2/exc202.o \
	${OBJECTDIR}/src/w2/exc203.o \
	${OBJECTDIR}/src/w2/exc204.o \
	${OBJECTDIR}/src/w2/exc205.o \
	${OBJECTDIR}/src/w3/exc302.o \
	${OBJECTDIR}/src/w3/exc303.o \
	${OBJECTDIR}/src/w3/exc304.o \
	${OBJECTDIR}/src/w3/exc305.o \
	${OBJECTDIR}/src/w4/exc401.o \
	${OBJECTDIR}/src/w4/exc403.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c-numeerisetmenetelmat

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c-numeerisetmenetelmat: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c-numeerisetmenetelmat ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/mutils.o: src/mutils.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mutils.o src/mutils.cpp

${OBJECTDIR}/src/myeigen.o: src/myeigen.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/myeigen.o src/myeigen.cpp

${OBJECTDIR}/src/w1/exc101.o: src/w1/exc101.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc101.o src/w1/exc101.c

${OBJECTDIR}/src/w1/exc102.o: src/w1/exc102.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc102.o src/w1/exc102.c

${OBJECTDIR}/src/w1/exc104.o: src/w1/exc104.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc104.o src/w1/exc104.c

${OBJECTDIR}/src/w1/exc104.o: src/w1/exc104.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc104.o src/w1/exc104.cpp

${OBJECTDIR}/src/w1/exc105.o: src/w1/exc105.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc105.o src/w1/exc105.c

${OBJECTDIR}/src/w2/exc201.o: src/w2/exc201.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc201.o src/w2/exc201.cpp

${OBJECTDIR}/src/w2/exc202.o: src/w2/exc202.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc202.o src/w2/exc202.cpp

${OBJECTDIR}/src/w2/exc203.o: src/w2/exc203.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc203.o src/w2/exc203.cpp

${OBJECTDIR}/src/w2/exc204.o: src/w2/exc204.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc204.o src/w2/exc204.cpp

${OBJECTDIR}/src/w2/exc205.o: src/w2/exc205.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc205.o src/w2/exc205.cpp

${OBJECTDIR}/src/w3/exc302.o: src/w3/exc302.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc302.o src/w3/exc302.cpp

${OBJECTDIR}/src/w3/exc303.o: src/w3/exc303.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc303.o src/w3/exc303.cpp

${OBJECTDIR}/src/w3/exc304.o: src/w3/exc304.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc304.o src/w3/exc304.cpp

${OBJECTDIR}/src/w3/exc305.o: src/w3/exc305.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc305.o src/w3/exc305.cpp

${OBJECTDIR}/src/w4/exc401.o: src/w4/exc401.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/exc401.o src/w4/exc401.cpp

${OBJECTDIR}/src/w4/exc403.o: src/w4/exc403.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/exc403.o src/w4/exc403.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c-numeerisetmenetelmat

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
