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
Date                   :=10/05/2023
CodeLitePath           :=C:/CodeLite
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
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
MakeDirCommand         :=C:/CodeLite/mkdir.exe -p
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  -static-libstdc++ -static-libgcc -static -m64 
IncludePath            := $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\include\boost $(IncludeSwitch)C:\msys64\mingw64\include\c++\13.1.0  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)C:\msys64\mingw64\lib $(LibraryPathSwitch)C:\msys64\mingw64\lib\gcc $(LibraryPathSwitch)C:\msys64\mingw64\lib\gcc\x86_64-w64-mingw32 $(LibraryPathSwitch)C:\msys64\mingw64\lib\gcc\x86_64-w64-mingw32\13.1.0  $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/mingw64/bin/ar.exe -r
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
Objects0=$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_test_driver.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia/Dropbox/GitHub/NumericRepresentations/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp

$(IntermediateDirectory)/src_test_driver.cpp$(ObjectSuffix): src/test_driver.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia/Dropbox/GitHub/NumericRepresentations/src/test_driver.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_test_driver.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_test_driver.cpp$(PreprocessSuffix): src/test_driver.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_test_driver.cpp$(PreprocessSuffix) src/test_driver.cpp

##
## Clean
##
clean:
	$(RM) -r ./Debug/


