#!/usr/bin/env bash

#delete previous gencodes
rm src/*.h
rm include/*.h
rm src/*.cxx
rm src/make*

PACKAGE_NAME=$(basename $PWD)
#get the new idl file created
CURRENT_IDL=$(basename ./idl/*.idl .idl)
#get prev idl file 
PREV_IDL=$(head -n 1 gencodes.cache)

#generate codes
cd src
fastrtpsgen -example x64Linux2.6gcc ../idl/*.idl
rm make*

cd ..

# change the main app's filename same as package name
perl -pi -e "s/fastrtps_ros/$PACKAGE_NAME/g" CMakeLists.txt

#change the filenames on CMakeLists based on newly generated codes
perl -pi -e "s/$PREV_IDL/$CURRENT_IDL/g" CMakeLists.txt

#store the previous idl name so the bash file knows what to replace next call
perl -pi -e "s/$PREV_IDL/$CURRENT_IDL/g" gencodes.cache

#move generated header files to include folder
mv src/*.h include