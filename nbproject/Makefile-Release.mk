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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/mutils.o \
	${OBJECTDIR}/src/myplot.o \
	${OBJECTDIR}/src/mysurf.o \
	${OBJECTDIR}/src/testSurf.o \
	${OBJECTDIR}/src/w1/exc101.o \
	${OBJECTDIR}/src/w1/exc102.o \
	${OBJECTDIR}/src/w1/exc104.o \
	${OBJECTDIR}/src/w1/exc104.o \
	${OBJECTDIR}/src/w1/exc105.o \
	${OBJECTDIR}/src/w11/exc1103.o \
	${OBJECTDIR}/src/w11/exc1104.o \
	${OBJECTDIR}/src/w11/exc1105.o \
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
	${OBJECTDIR}/src/w4/exc402.o \
	${OBJECTDIR}/src/w4/exc403.o \
	${OBJECTDIR}/src/w4/exc404.o \
	${OBJECTDIR}/src/w4/exc405.o \
	${OBJECTDIR}/src/w5/exc501.o \
	${OBJECTDIR}/src/w5/exc502.o \
	${OBJECTDIR}/src/w5/exc503.o \
	${OBJECTDIR}/src/w5/exc504.o \
	${OBJECTDIR}/src/w5/exc505.o \
	${OBJECTDIR}/src/w5/exc506.o \
	${OBJECTDIR}/src/w6/exc602.o \
	${OBJECTDIR}/src/w6/exc603.o \
	${OBJECTDIR}/src/w6/exc604.o \
	${OBJECTDIR}/src/w6/exc605.o \
	${OBJECTDIR}/src/w7/exc701.o \
	${OBJECTDIR}/src/w7/exc702.o \
	${OBJECTDIR}/src/w7/exc705.o \
	${OBJECTDIR}/src/w8/exc802.o \
	${OBJECTDIR}/src/w8/exc805.o \
	${OBJECTDIR}/src/w9/exc901.o \
	${OBJECTDIR}/src/w9/exc904.o


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
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mutils.o src/mutils.cpp

${OBJECTDIR}/src/myplot.o: src/myplot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/myplot.o src/myplot.cpp

${OBJECTDIR}/src/mysurf.o: src/mysurf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mysurf.o src/mysurf.cpp

${OBJECTDIR}/src/testSurf.o: src/testSurf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testSurf.o src/testSurf.cpp

${OBJECTDIR}/src/w1/exc101.o: src/w1/exc101.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc101.o src/w1/exc101.c

${OBJECTDIR}/src/w1/exc102.o: src/w1/exc102.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc102.o src/w1/exc102.c

${OBJECTDIR}/src/w1/exc104.o: src/w1/exc104.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc104.o src/w1/exc104.c

${OBJECTDIR}/src/w1/exc104.o: src/w1/exc104.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc104.o src/w1/exc104.cpp

${OBJECTDIR}/src/w1/exc105.o: src/w1/exc105.c 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/exc105.o src/w1/exc105.c

${OBJECTDIR}/src/w11/exc1103.o: src/w11/exc1103.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w11
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w11/exc1103.o src/w11/exc1103.cpp

${OBJECTDIR}/src/w11/exc1104.o: src/w11/exc1104.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w11
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w11/exc1104.o src/w11/exc1104.cpp

${OBJECTDIR}/src/w11/exc1105.o: src/w11/exc1105.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w11
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w11/exc1105.o src/w11/exc1105.cpp

${OBJECTDIR}/src/w2/exc201.o: src/w2/exc201.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc201.o src/w2/exc201.cpp

${OBJECTDIR}/src/w2/exc202.o: src/w2/exc202.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc202.o src/w2/exc202.cpp

${OBJECTDIR}/src/w2/exc203.o: src/w2/exc203.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc203.o src/w2/exc203.cpp

${OBJECTDIR}/src/w2/exc204.o: src/w2/exc204.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc204.o src/w2/exc204.cpp

${OBJECTDIR}/src/w2/exc205.o: src/w2/exc205.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/exc205.o src/w2/exc205.cpp

${OBJECTDIR}/src/w3/exc302.o: src/w3/exc302.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc302.o src/w3/exc302.cpp

${OBJECTDIR}/src/w3/exc303.o: src/w3/exc303.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc303.o src/w3/exc303.cpp

${OBJECTDIR}/src/w3/exc304.o: src/w3/exc304.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc304.o src/w3/exc304.cpp

${OBJECTDIR}/src/w3/exc305.o: src/w3/exc305.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/exc305.o src/w3/exc305.cpp

${OBJECTDIR}/src/w4/exc401.o: src/w4/exc401.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/exc401.o src/w4/exc401.cpp

${OBJECTDIR}/src/w4/exc402.o: src/w4/exc402.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/exc402.o src/w4/exc402.cpp

${OBJECTDIR}/src/w4/exc403.o: src/w4/exc403.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/exc403.o src/w4/exc403.cpp

${OBJECTDIR}/src/w4/exc404.o: src/w4/exc404.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/exc404.o src/w4/exc404.cpp

${OBJECTDIR}/src/w4/exc405.o: src/w4/exc405.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/exc405.o src/w4/exc405.cpp

${OBJECTDIR}/src/w5/exc501.o: src/w5/exc501.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/exc501.o src/w5/exc501.cpp

${OBJECTDIR}/src/w5/exc502.o: src/w5/exc502.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/exc502.o src/w5/exc502.cpp

${OBJECTDIR}/src/w5/exc503.o: src/w5/exc503.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/exc503.o src/w5/exc503.cpp

${OBJECTDIR}/src/w5/exc504.o: src/w5/exc504.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/exc504.o src/w5/exc504.cpp

${OBJECTDIR}/src/w5/exc505.o: src/w5/exc505.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/exc505.o src/w5/exc505.cpp

${OBJECTDIR}/src/w5/exc506.o: src/w5/exc506.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/exc506.o src/w5/exc506.cpp

${OBJECTDIR}/src/w6/exc602.o: src/w6/exc602.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/exc602.o src/w6/exc602.cpp

${OBJECTDIR}/src/w6/exc603.o: src/w6/exc603.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/exc603.o src/w6/exc603.cpp

${OBJECTDIR}/src/w6/exc604.o: src/w6/exc604.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/exc604.o src/w6/exc604.cpp

${OBJECTDIR}/src/w6/exc605.o: src/w6/exc605.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/exc605.o src/w6/exc605.cpp

${OBJECTDIR}/src/w7/exc701.o: src/w7/exc701.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w7
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w7/exc701.o src/w7/exc701.cpp

${OBJECTDIR}/src/w7/exc702.o: src/w7/exc702.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w7
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w7/exc702.o src/w7/exc702.cpp

${OBJECTDIR}/src/w7/exc705.o: src/w7/exc705.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w7
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w7/exc705.o src/w7/exc705.cpp

${OBJECTDIR}/src/w8/exc802.o: src/w8/exc802.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w8/exc802.o src/w8/exc802.cpp

${OBJECTDIR}/src/w8/exc805.o: src/w8/exc805.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w8/exc805.o src/w8/exc805.cpp

${OBJECTDIR}/src/w9/exc901.o: src/w9/exc901.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w9/exc901.o src/w9/exc901.cpp

${OBJECTDIR}/src/w9/exc904.o: src/w9/exc904.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w9/exc904.o src/w9/exc904.cpp

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
