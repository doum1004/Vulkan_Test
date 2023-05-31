@echo off
SET target_build=build
mkdir %target_build%
cd %target_build%

SET target_folder=test1
mkdir %target_folder%
cd %target_folder%
mkdir install

::@echo on
echo %target_build%/%target_folder%
echo %1
IF "%1" == "generate" (
    cmake -G "Visual Studio 16 2019" -A x64 -T host=x64 ../../%target_folder% -DCMAKE_INSTALL_PREFIX=./install
)
IF "%1" == "open" (
    cmake --open ./
)
IF "%1" == "build" (
    cmake --build . --target install --config Debug
)
IF "%1" == "install" (
    cmake --install . --config Debug
)

@echo off
cd ..
cd ..
