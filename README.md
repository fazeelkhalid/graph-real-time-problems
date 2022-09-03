# graph-real-time-problems
Points: 100 Topics: Graphs, topological sort, freedom to decide how to represent data and organize code (while still reading in a graph and performing topological sort) PLAGIARISM/COLLUSION: You should not read any code (solution) that directly solves this problem (e.g. implements DFS, topological sorting or other component needed for the homework). The graph representation provided on the Code page (which you are allowed to use in your solution) and the pseudocode and algorithm discussed in class provide all the information needed. If anything is unclear in the provided materials check with us. You can read materials on how to read from a file, or read a Unix file or how to tokenize a line of code, BUT not in a sample code that deals with graphs or this specific problem. E.g. you can read tutorials about these topics, but not a solution to this problem (or a problem very similar to it). You should not share your code with any classmate or read another classmate's code. Part 1: Main program requirements (100 pts) Given a list of courses and their prerequisites, compute the order in which courses must be taken so that when taking a courses, all its prerequisites have already been taken. All the files that the program would read from are in Unix format (they have the Unix EOL). Provided files: ● Grading Criteria ● cycle0.txt ● data0.txt ● data0_rev.txt ● data1.txt - like data0.txt but the order of the prerequisite courses is modified on line 2. ● slides.txt (graph image) - courses given in such a way that they produce the same graph as in the image. (The last digit in the course number is the same as the vertex corresponding to it in the drawn graph. You can also see this in the vertex-to-course name correspondence in the sample run for this file.) ● run.html● data0_easy.txt - If you cannot handle the above file format, this is an easier file format that you can use, but there will be 15 points lost in this case. More details about this situation are given in Part 3. ● Unix.zip - zipped folder with all data files. ● For your reference: EOL_Mac_Unix_Windows.png - EOL symbols for Unix/Mac/Windows Specifications: 1. You can use structs, macros, typedef. 2. All the code must be in C (not C++, or any other language) 3. Global or static variables are NOT allowed. The exception is using macros to define constants for the size limits (e.g. instead of using 30 for the max course name size). E.g. #define MAX_ARRAY_LENGTH 20 4. You can use static memory (on the frame stack) or dynamic memory. (Do not confuse static memory with static variables.) 5. The program must read from the user a filename. The filename (as given by the user) will include the extension, but NOT the path. E.g.: data0.txt 6. You can open and close the file however many times you want. 7. File format: 1. Unix file. It will have the Unix EOL (end-of-line). 2. Size limits: 1. The file name will be at most 30 characters. 2. A course name will be at most 30 characters 3. A line in the file will be at most 1000 characters. 3. The file ends with an empty new line. 4. Each line (except for the last empty line) has one or more course names. 5. Each course name is a single word (without any spaces). E.g. CSE1310 (with no space between CSE and 1310). 6. There is no empty space at the end of the line. 7. There is exactly one empty space between any two consecutive courses on the same line. (You do not need to worry about having tabs or more than one empty space between 2 courses.) The first course name on each line is the course being described and the following courses are the prerequisites for it. E.g. CSE2315 CSE1310 MATH1426 ENGL13018. The first line describes course CSE2315 and it indicates that CSE2315 has 2 prerequisite courses, namely: CSE1310 and MATH1426. The second line describes course ENG1301 and it indicates that ENG1301 has no prerequisites. 9. You can assume that there is exactly one line for every course, even for those that do not have prerequisites (see ENGL1301 above). Therefore you can count the number of lines in the file to get the total number of courses. 10.The courses are not given in any specific order in the file. 8. You must create a directed graph corresponding to the data in the file. 1. The graph will have as many vertices as different courses listed in the file. 2. You can represent the vertices and edges however you want. 3. You do NOT have to use a graph struct. If you can do all the work with just the 2D table (the adjacency matrix) that is fine. You HAVE TO implement the topological sorting covered in class (as this assignment is on Graphs), but you can organize, represent and store the data however you want. 4. For the edges, you can use either the adjacency matrix representation or the adjacency list. If you use the adjacency list, keep the nodes in the list sorted in increasing order. 5. For each course that has prerequisites, there is an edge, from each prerequisite to that course. Thus the direction of the edge indicates the dependency. The actual edge will be between the vertices in the graph corresponding to these courses. E.g. file data0.txt has: c100 c300 c200 c100 c200 c100 Meaning: c100-----> c200 \ | \ | \ | \ | \ | \ | V V c300(The above drawing is provided here to give a picture of how the data in the file should be interpreted and the graph that represents this data. Your program should *NOT* print this drawing. See the sample run for expected program output.) From this data you should create the correspondence: vertex 0 - c100 vertex 1 - c300 vertex 2 - c200 and you can represent the graph using adjacency matrix (the row and column indexes are provided for convenience): | 0 1 2 ----------------- 0| 0 1 1 1| 0 0 0 2| 0 1 0 e.g. E[0][1] is 1 because vertex 0 corresponds to c100 and vertex 1 corresponds to c300 and c300 has c100 as a prerequisite. Notice that E[1][0] is not 1. If you use the adjacency list representation, then you can print the adjacency list. The list must be sorted in increasing order (e.g. see the list for 0). It should show the corresponding node numbers. E.g. for the above example the adjacency list will be: 0: 1, 2, 1: 2: 1, 6. 7. In order for the output to look the same for everyone, use the correspondence given here: vertex 0 for the course on the first line, vertex 1 for the course on the second line, etc. 1. Print the courses in topological sorted order. This should be done using the DFS (Depth First Search) algorithm that we covered in class and the topological sorting based on DFS discussed in class. There is no topological order if there is a cycle in the graph; in this case print an error message. If in DFV-visit when looking at the (u,v) edge, if the color of v is GRAY then there is a cycle in the graph (and therefore topological sorting is not possible). See the Lecture on topological sorting (You can find the date based on the table on the Scans page and then watch the video from that day. I have also updated the pseudocodein the slides to show that. Refresh the slides and check the date on the first page. If it is 11/26/2020, then you have the most recent version.) 8. (6 points) create and submit 1 test file. It must cover a special case. Indicate what special case you are covering (e.g. no course has any prerequisite). At the top of the file indicate what makes it a special case. Save this file as special.txt. It should be in Unix EOL format. Part 2: Suggestions for improvements (not for grade) 1. CSE Advisors also are mindful and point out to students the "longest path through the degree". That is longest chain of course prerequisites (e.g. CSE1310 ---> CSE1320 --> CSE3318 -->...) as this gives a lower bound on the number of semesters needed until graduation. Can you calculate for each course the LONGEST chain ending with it? E.g. in the above example, there are 2 chains ending with c300 (size 2: just c100-->c300, size 3: c100-->c200-->c300) and you want to show longest path 3 for c300. Can you calculate this number for each course? 2. Allow the user the enter a list of courses taken so far (from the user or from file) and print a list of the courses they can take (they have all the prerequisites for). 3. Ask the user to enter a desired number of courses per semester and suggest a schedule (by semester). Part 3: Implementation suggestions 1. Reading from file: (15 points) For each line in the file, the code can extract the first course and the prerequisites for it. If you cannot process each line in the file correctly, you can use a modified input file that shows on each line, the number of courses, but you would lose the 15 points dedicated to line processing. If your program works with the "easy files", in order to make it easy for the TAs to know which file to provide, please name your C program courses_graph_easy.c. Here is the modification shown for a new example. Instead of c100 c300 c200 c100 c200 the file would have: 1 c1003 c300 c200 c100 1 c200 1. that way the first data on each line is a number that tells how many courses (strings) follow after it on that line. Everything is separated by exactly one space. All the other specifications are the same as for the original file (empty line at the end, no space at the end of any line, length of words, etc). Here is data0_easy.txt Make a direct correspondence between vertex numbers and course names. E.g. the **first** course name on the first line corresponds to vertex 0, the **first** course name on the second line corresponds to vertex 1, etc... 2. 3. The vertex numbers are used to refer to vertices. 4. In order to add an edge in the graph you will need to find the vertex number corresponding to a given course name. E.g. find that c300 corresponds to vertex 1 and c200 corresponds to vertex 2. Now you can set E[2][1] to be 1. (With the adjacency list, add node 1 in the adjacency list for 2 keeping the list sorted.) To help with this, write a function that takes as arguments the list/array of [unique] course names and one course name and returns the index of that course in the list. You can use that index as the vertex number. (This is similar to the indexOf method in Java.) 5. To see all the non-printable characters that may be in a file, find an editor that shows them. E.g. in Notepad++ : open the file, go to View -> Show symbol -> Show all characters. YOU SHOULD TRY THIS! In general, not necessarily for this homework, if you make the text editor show the white spaces, you will know if what you see as 4 empty spaces comes from 4 spaces or from one tab or show other hidden characters. This can help when you tokenize. E.g. here I am using Notepad++ to see the EOL for files saved with Unix/Mac/Windows EOL (see the CR/LF/CRLF at the end of each line): EOL_Mac_Unix_Windows.png How to submit Submit courses_graph.c (or courses_graph_easy.c) and special.txt (the special test case you created) in Canvas . (For courses_graph_easy.c you can submit the "easy" files that you created.)Your program should be named courses_graph.c if it reads from the normal/original files. If instead it reads from the 'easy' files, name it courses_graph_easy.c As stated on the course syllabus, programs must be in C, and must run on omega.uta.edu or the VM. IMPORTANT: Pay close attention to all specifications on this page, including file names and submission format. Even in cases where your answers are correct, points will be taken off liberally for non-compliance with the instructions given on this page (such as wrong file names, wrong compression format for the submitted code, and so on). The reason is that non-compliance with the instructions makes the grading process significantly (and unnecessarily) more time consuming. Contact the instructor or TA if you have any questions
cxczx
dasadadsasad
sdadsa
adsdsdadsa
fdsfdsdfs
fdfds
fdds
