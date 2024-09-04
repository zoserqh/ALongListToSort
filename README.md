# A Long List to Sort
Given a list of 100 million double-type numbers (2.3GB) contained in a file list.txt

The aim is to sort the list in the shortest possible time and make comparisons between the proposed programs.

After building the project

* listGenerator is used to generate list.txt
* stlCPP uses the default sorting algorithm that the C++ stl has
* mtCPP makes use of concurrency in CPU (threads)
* cudaCPP makes use of the GPU (pending implementation)

## Build
After cloning or copying the repository, the first thing you need to do is run the builder file.
    
    bash builder

Then the file list.txt and executables listGenerator, stlCPP and mtCPP will have been generated in /data/ and /bin/ respectively.