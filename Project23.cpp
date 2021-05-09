#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_LENGTH 20
#define MAX_SUB_LENGTH 20
#define MAX_ARRAY_LENGTH 20
static char filename[MAX_ARRAY_LENGTH]; 
struct Graph{
int countes;
int** matrix;
};
typedef struct Graph* GB;

int cheack(char ***str_nodes){
   char ch;
   FILE *file;
   file = fopen(filename, "r"); // read mode

   if (file == NULL)
   {
      printf("Error .\n");
      exit(EXIT_FAILURE);
   }

   
	char array[70];
	char*  subarray; 
	int count = 0; 
	int i;
// Determine the number of nodes
	while (!feof(file)){ 
	fgets(array, 70, file); 
	count++;
 	} 
 
 fseek(file, 0 , SEEK_SET);

*str_nodes = (char**) malloc(count* sizeof(char));
 for(i = 0; i < count; i++){
(*str_nodes)[i] = (char*) malloc(sizeof(char) * 31);
if( (*str_nodes)[i] == NULL ) 
	printf("ERROR OUT OF MEMORY\n"); 
	strcpy( (*str_nodes)[i], "" );
	
}	

int n = 0;
// Get the string representation of all the nodes and store it in str_nodes for future references 
while(!feof(file)){
fgets(array, 1001, file);
subarray = strtok(array, " \n");
//printf("After tikenize %s \n",);

strcpy( (*str_nodes)[n], subarray );
subarray = strtok(NULL, "\n"); 
n++;
}


      

   fclose(file);
   return count;	
}



void print_matrix(GB graph){ 
printf("\n\n");
int n; 
printf(" Matrix Are: \n");

printf("   ");
for (int i = 0; i < n; i++){

	printf("%d ", i);
	}


for(int i = 0; i < n; i++){

	printf("	");

}
printf("\n");

for(int i = 0; i < n; i++){
printf(" %d ", i); 
 	for(int j = 0; j < n; j++){
		printf(" %d", (graph->matrix)[i][j] );
	}
printf("\n");
}
}

int** NewMatric(int nodes){ 

int** nmatrix = (int**) malloc(sizeof(int*) * nodes);
 for(int i = 0; i < nodes; i++){
 
	nmatrix[i] = (int*) malloc(sizeof(int) * nodes);
}
 return nmatrix;
} 


void createMatrix(char ***nodes,int count){
	char ch;
   FILE *file;
   file = fopen(filename, "r"); // read mode

   if (file == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
	char array[70];
	char*  subarray; 

*nodes = (char**) malloc(count* count*sizeof(char));;
int n = 0;
char *newsubarray;
for (int i = 0; !feof(file); i++){
	fgets(array, 1001, file);
	newsubarray=strtok(array, " ");
	while( newsubarray != NULL ) {
    strcpy( (*nodes)[n], newsubarray );
     newsubarray = strtok(NULL, " ");
   }
n++;
//n1=0;
}

      
//printf("After tikenize %s \n", newsubarray[1]);
   fclose(file);
	//return newsubarray;
//printf("After tikenize %s \n", newsubarray);
	
}


// Create a new graph data structure 
GB create_new_graph(int nodes){ 
int i,j;
GB temprary;
temprary->countes = nodes;
temprary->matrix = NewMatric(temprary->countes);
for(i = 0; i < nodes; i++) 
{

	for(j = 0; j < nodes; j++)
	{
	  
		temprary->matrix[i][j] =0;
		}
}
return temprary;
}


void readFile( GB* g, char** str_nodes,int countes){ 
FILE* fp = fopen(filename, "r");
char line[1001]; 
char* subarray;


for (int i = 0; !feof(fp); i++){ 
fgets(line, 1001, fp); 
subarray = strtok(line, " \n"); 
while(subarray != NULL){
if( strcmp(str_nodes[i], subarray) != 0 ){
	
int j =0;
//printf("VAlue of j is %d \n",j); 

for(int z = 0; z < countes; z++){
	if( strcmp(str_nodes[z], subarray) == 0 ) 
		j=z;
}




(*g)->matrix[j][i] = 1;
//add_edge(&(*g), j, i);
}
subarray = strtok(NULL, " \n");
}

}

fclose(fp);
}


int main()
{ 
	printf("Enter name of a file you wish to see\n");
   gets(filename);

	char** str_nodes;
 	int c=cheack(&str_nodes);
 	GB graph;
 	printf("Total Numbers of nodes are:  %d",c);
    graph = create_new_graph(c); 
	readFile( &graph, str_nodes,c);
	
    print_matrix(graph);
   return 0;
}
