#!/bin/bash

# change the binary files to txt files
echo using binary files: $filename
#only need this top portion of code in order to convert txt to root files.. (although this step is not entirely necessary either..)
#an exampe of a case-if statement checking values #this could also be used to store count values for the cases..
for i in $filename
do
    #seems like root file is smart enough to not need this step as processing these on sipm data ignores first line and creates good ntuples..
    case "$i" in
	*".bin") #for any file that is a bin file
	    echo "creating txt file from: $i"
	    #this passes the i arguement to the root command..
	    #want to run: "create_root.cc(\"file_name\")"
	    ./basic $i
	    ;;
    esac
done

# change the txt files to root files
filename=$(ls *.txt)
# filename=$(ls *ip4_tranloc_8020_muon_bitcount2.txt)
echo using text files: $filename
#only need this top portion of code in order to convert txt to root files.. (although this step is not entirely necessary either..)
#an exampe of a case-if statement checking values #this could also be used to store count values for the cases..
for i in $filename
do
    #if you want to erase all of the first lines of a file perform:
    #tail -n +2 $filename > "tmp.txt" && mv "tmp.txt" $filename
    #seems like root file is smart enough to not need this step as processing these on sipm data ignores first line and creates good ntuples..
    case "$i" in
	*".txt") #for any file that is a txt file
	    echo "creating root file from: $i"
	    #this passes the i arguement to the root command..
        #want to run: "create_root.cc(\"file_name\")"
	    root -l -q -b "create_root.cc(\"$i\")"
	    ;;
    esac
done

# script to run the iterate function over all of the different root files in a particular directory..
rootname=$(ls *.root)
echo $rootname
#an exampe of a case-if statement checking values #this could also be used to store count values for the cases..
for i in $rootname
do
    case "$i" in
	*".root") #for any file that is a root file
	    echo "creating root file from: $i"
	    #this passes the i arguement to the root command..
	    root -l -q -b "pixCamera2DHist.cpp(\"$i\")"
	    ;;
    esac
done
