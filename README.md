# learningCPP

##This project/repo is for mxtw to learn and document their C++ studying journey

Instruction on how to make new function: <br>
    1. Make .h with #pragma once + functionName();  <br>
    2. Make .cpp, include the .h previously created, write function <br>
    3. Go to tasks.json in project folder, in args: add "path/to/your/newCPPfile.cpp" (local, i.e. no need for ~/ or @/) <br>
    4. build/run main.cpp <br>
<hr>

Mainly follows the progression of Algorithm book (python).<br>
Chapter 1: Algorithm.<br>
Chapter 2: Searching and Sorting algorithms, Brute force. <br>
Chapter 3: Recursion. <br>
Chapter 4: Divide and conquer. <br>
Chapter 5: Greedy. <br>
Chapter 6: Dynamic programming. <br>
Chapter 7: Basic data structures, Tree. <br>
Chapter 8: Graph's algorithms. <br>
Chapter 9: Brute force + Backtracking.

!!This also includes studying from USACO and VNOI roadmap (reminder to checkout codedream)
!!bro we can code together on ide.usaco.guide
!!exercises: hackerank, leetcode, codeforces, cses,...
!!TryHackMe, GeeksforGeeks

Log:
1. Monday, May 12nd 2025: Created repo/project, finished Chapter 1.
2. Monday, May 19th 2025: Added some more sort algorithms, to be continue.
3. Tuesday, May 20th 2025: Finished merge, quick, heap, shell sort, learned a little bit more about cross-file usage of function + added alot of graph methods files
4. Wednesday, May 21st 2025: finished allPairs(floydWarshall & johnson) & weighted (dijkstra & bellmanFord)
5. Thursday, May 22nd 2025: finished MST(prim and kruskal), shortestPath. starting on solving problems
6. Friday, May 30th 2025: added some .vscode configuration files, did some usaco basic stuff on onlinegdb
7. Monday, June 2nd 2025:
    - to compile, build and run: g++ name.cpp -o name && ./name
    - to input and output for a program: ./name < inp.txt > out.txt
        #include <freopen>
        freopen("inp.txt", "r", stdin); (or problem.inp, problem.out)
        freopen("out.txt", "w", stdout);
    - checkout fastestINOUT.
    - instead of using cout to debug, use cerr instead (output in error stream instead of standard output stream -> online judge wont care) ! use too much = tle
    - #define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl; (use for debug)
    - https://gist.github.com/SansPapyrus683/61b65d4d7ec223b48ebf5c3bb382ba8d (debug data structure)
    - cin.tie(0)->sync_with_stdio(false) instead of ios_base...
    - using ll = long long <=> #define ll long long
    - using str = std::string (this is creating alias)
    - namespace (like iosbase::, etc..) is similar to a class/struct; inline namespace <=> free access without using name::
    - lambda func: [captureList](parameters) -> trailingReturnType {functionBody}
    - []: no capture, [&]: capture everything by reference, [=]: capture everything by copy
    - Finished USACO general! (left some practiced note for rechecking)

