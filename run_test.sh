#!/bin/sh

# Removing cmake prebuilt files
rm -rf CMakeFiles

# compiling the file again
cmake CMakeLists.txt 1> /dev/null 2>/dev/null
make -j8 1> /dev/null 2>/dev/null

#Testing script
## test 01-1
echo "test 01: mytest.txt motif:3 random:1000 undirected" > result.txt
echo "test 01: mytest.txt motif:3 random:1000 undirected" 
./nemolib test_samples/mytest.txt 3 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 3 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 3 1000 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 01-2
echo "test 02: mytest.txt motif:5 random:1000 undirected" >> result.txt
echo "test 02: mytest.txt motif:5 random:1000 undirected" 
./nemolib test_samples/mytest.txt 5 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 5 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 5 1000 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 01-3
echo "test 03: mytest.txt motif:3 random:1500 undirected" >> result.txt
echo "test 03: mytest.txt motif:3 random:1500 undirected" 
./nemolib test_samples/mytest.txt 3 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 3 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 3 1500 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 01-4
echo "test 04: mytest.txt motif:5 random:1500 undirected" >> result.txt
echo "test 04: mytest.txt motif:5 random:1500 undirected" 
./nemolib test_samples/mytest.txt 5 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 5 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/mytest.txt 5 1500 0 | grep -i "Time" >> result.txt
echo "" >> result.txt
echo "------------------------------------------------------------------" >> result.txt
echo "\n" >> result.txt


## test 02-1
echo "test 01: MIPS_index.txt motif:3 random:1000 undirected" >> result.txt
echo "test 01: MIPS_index.txt motif:3 random:1000 undirected" 
./nemolib test_samples/MIPS_index.txt 3 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 3 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 3 1000 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 02-2
echo "test 02: MIPS_index.txt motif:5 random:1000 undirected" >> result.txt
echo "test 02: MIPS_index.txt motif:5 random:1000 undirected" 
./nemolib test_samples/MIPS_index.txt 5 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 5 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 5 1000 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 02-3
echo "test 03: MIPS_index.txt motif:3 random:1500 undirected" >> result.txt
echo "test 03: MIPS_index.txt motif:3 random:1500 undirected" 
./nemolib test_samples/MIPS_index.txt 3 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 3 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 3 1500 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 02-4
echo "test 04: MIPS_index.txt motif:5 random:1500 undirected" >> result.txt
echo "test 04: MIPS_index.txt motif:5 random:1500 undirected" 
./nemolib test_samples/MIPS_index.txt 5 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 5 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/MIPS_index.txt 5 1500 0 | grep -i "Time" >> result.txt
echo "" >> result.txt
echo "------------------------------------------------------------------" >> result.txt
echo "\n" >> result.txt


## test 03-1
echo "test 01: Dmela20160430_idx.txt motif:3 random:1000 undirected" >> result.txt
echo "test 01: Dmela20160430_idx.txt motif:3 random:1000 undirected" 
./nemolib test_samples/Dmela20160430_idx.txt 3 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 3 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 3 1000 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 02-2
echo "test 02: Dmela20160430_idx.txt motif:5 random:1000 undirected" >> result.txt
echo "test 02: Dmela20160430_idx.txt motif:5 random:1000 undirected" 
./nemolib test_samples/Dmela20160430_idx.txt 5 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 5 1000 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 5 1000 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 03-3
echo "test 03: Dmela20160430_idx.txt motif:3 random:1500 undirected" >> result.txt
echo "test 03: Dmela20160430_idx.txt motif:3 random:1500 undirected" 
./nemolib test_samples/Dmela20160430_idx.txt 3 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 3 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 3 1500 0 | grep -i "Time" >> result.txt
echo "" >> result.txt

## test 03-4
echo "test 04: Dmela20160430_idx.txt motif:5 random:1500 undirected" >> result.txt
echo "test 04: Dmela20160430_idx.txt motif:5 random:1500 undirected" 
./nemolib test_samples/Dmela20160430_idx.txt 5 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 5 1500 0 | grep -i "Time" >> result.txt
./nemolib test_samples/Dmela20160430_idx.txt 5 1500 0 | grep -i "Time" >> result.txt
echo "" >> result.txt
echo "------------------------------------------------------------------" >> result.txt
echo "\n" >> result.txt


