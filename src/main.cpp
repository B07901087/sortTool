// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2019 fall Algorithm PA1]
//  Modify     [2019/9/6 Cheng-Yun Hsieh]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream>
#include "sort_tool.h"

using namespace std;

void help_message() {
    cout << "usage: NTU_sort -[IS|MS|QS|HS] <input_file> <output_file>" << endl;
    cout << "options:" << endl;
    cout << "   IS - Insersion Sort" << endl;
    cout << "   MS - Merge Sort" << endl;
    cout << "   QS - Quick Sort" << endl;
    cout << "   HS - Heap Sort" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 4) {
       help_message();
       return 0;
    }

    //////////// read the input file /////////////
    
    char buffer[200];
    fstream fin(argv[2]);
    fstream fout;
    fout.open(argv[3],ios::out);
    fin.getline(buffer,200);
    fin.getline(buffer,200);
    int junk,num;
    vector<int> data;
    while (fin >> junk >> num)
        data.push_back(num); // data[0] will be the first data. 
                             // data[1] will be the second data and so on.
    
    //////////// the sorting part ////////////////
    SortTool NTUSortTool; 

    if(!strcmp(argv[1],"-QS")) {
        NTUSortTool.QuickSort(data);
    }
    else if(!strcmp(argv[1],"-IS")) {
        NTUSortTool.InsertionSort(data);
    }
    else if(!strcmp(argv[1],"-MS")) {
        NTUSortTool.MergeSort(data);
    }
    else if(!strcmp(argv[1],"-HS")) {
        NTUSortTool.HeapSort(data);
    }
    else {
        help_message();
        return 0;
    }

    //////////// write the output file ///////////
    fout << "# " << data.size() << " data points" <<endl;
    fout << "# index number" << endl;
    for (int i = 0; i < data.size(); i++)
        fout << i << " " <<data[i] << endl;
    fin.close();
    fout.close();
    return 0;
}
