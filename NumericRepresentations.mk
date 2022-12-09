##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=NumericRepresentations
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/julia/Dropbox/GitHub/NumericRepresentations
ProjectPath            :=C:/Users/julia/Dropbox/GitHub/NumericRepresentations
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=julia
Date                   :=07/12/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=bin/Debug
OutputFile             :=bin/Debug/NumericRepresentations
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="NumericRepresentations.txt"
PCHCompileFlags        :=
MakeDirCommand         :=C:/msys64/usr/bin/mkdir.exe
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  -static-libstdc++ -static-libgcc -static -m64 
IncludePath            := $(IncludeSwitch)C:/msys64/mingw64/include $(IncludeSwitch)C:/msys64/mingw64/include/c++ $(IncludeSwitch)C:/msys64/mingw64/include/c++/12.2.0 $(IncludeSwitch)C:/msys64/mingw64/include/c++/12.2.0/backwards $(IncludeSwitch)C:/msys64/mingw64/include/c++/12.2.0/x86_64-w64-mingw32 $(IncludeSwitch)C:/msys64/mingw64/include/fmt $(IncludeSwitch)C:/msys64/mingw64/include/boost $(IncludeSwitch)C:/msys64/mingw64/include/eigen3 $(IncludeSwitch)C:/msys64/mingw64/include/eigen3/eigen  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)C:/msys64/mingw64/lib  $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/mingw64/bin/ar.exe rcu
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -m64 -g -std=gnu++23 -fconcepts-diagnostics-depth=512 -fconstexpr-loop-limit=100000000 -Wall  $(Preprocessors)
CFLAGS   :=  -m64 -g -std=gnu++23 -fconcepts-diagnostics-depth=512 -fconstexpr-loop-limit=100000000 -Wall  $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Users\julia\Dropbox\GitHub
Objects0=$(IntermediateDirectory)/src_pruebas_dig_t.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_pruebas_dig_t.cpp$(ObjectSuffix): src/pruebas_dig_t.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia/Dropbox/GitHub/NumericRepresentations/src/pruebas_dig_t.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_pruebas_dig_t.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_pruebas_dig_t.cpp$(PreprocessSuffix): src/pruebas_dig_t.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_pruebas_dig_t.cpp$(PreprocessSuffix) src/pruebas_dig_t.cpp

##
## Clean
##
clean:
	$(RM) -r ./Debug/


