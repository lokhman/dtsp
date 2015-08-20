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
	${OBJECTDIR}/src/dtsp.o \
	${OBJECTDIR}/src/dtsp/aes.o \
	${OBJECTDIR}/src/dtsp/crc32.o \
	${OBJECTDIR}/src/dtsp/isaac.o \
	${OBJECTDIR}/src/dtsp/md5.o \
	${OBJECTDIR}/src/dtsp/tsearch.o \
	${OBJECTDIR}/src/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dtsp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dtsp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dtsp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/dtsp.o: src/dtsp.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dtsp.o src/dtsp.c

${OBJECTDIR}/src/dtsp/aes.o: src/dtsp/aes.c 
	${MKDIR} -p ${OBJECTDIR}/src/dtsp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dtsp/aes.o src/dtsp/aes.c

${OBJECTDIR}/src/dtsp/crc32.o: src/dtsp/crc32.c 
	${MKDIR} -p ${OBJECTDIR}/src/dtsp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dtsp/crc32.o src/dtsp/crc32.c

${OBJECTDIR}/src/dtsp/isaac.o: src/dtsp/isaac.c 
	${MKDIR} -p ${OBJECTDIR}/src/dtsp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dtsp/isaac.o src/dtsp/isaac.c

${OBJECTDIR}/src/dtsp/md5.o: src/dtsp/md5.c 
	${MKDIR} -p ${OBJECTDIR}/src/dtsp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dtsp/md5.o src/dtsp/md5.c

${OBJECTDIR}/src/dtsp/tsearch.o: src/dtsp/tsearch.c 
	${MKDIR} -p ${OBJECTDIR}/src/dtsp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dtsp/tsearch.o src/dtsp/tsearch.c

${OBJECTDIR}/src/main.o: src/main.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dtsp

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
