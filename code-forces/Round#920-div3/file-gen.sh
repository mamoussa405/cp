#!bin/bash
echo "file name:"
read name
touch $name
cp ../template.cpp $name
