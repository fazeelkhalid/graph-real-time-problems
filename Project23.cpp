#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Graph
{
	int numOfRows;
	int **matrix;
};

typedef struct Graph Graph;

int check(char ***allNodes, char *filename)
{
	char ch;
	FILE *file;
	file = fopen(filename, "r"); // read mode

	if (file == NULL)
	{
		printf("Error .\n");
		exit(EXIT_FAILURE);
	}

	char array[70];
	char *subarray;
	int count = 0;
	int i = 0;
	// Determine the number of nodes
	while (!feof(file))
	{
		fgets(array, 70, file);
		count++;
	}

	fseek(file, 0, SEEK_SET);

	*allNodes = (char **)malloc(count * sizeof(char));
	while (i < count)
	{
		(*allNodes)[i] = (char *)malloc(sizeof(char) * 31);
		if ((*allNodes)[i] == NULL)
			printf("ERROR OUT OF MEMORY\n");
		strcpy((*allNodes)[i], "");

		i++;
	}

	int n = 0;
	// Get the string representation of all the nodes and store it in str_nodes for future references
	while (!feof(file))
	{
		fgets(array, 1001, file);
		subarray = strtok(array, " \n");
		//printf("After tikenize %s \n",);

		strcpy((*allNodes)[n], subarray);
		subarray = strtok(NULL, "\n");
		n++;
	}
	fclose(file);
	return count;
}

int **NewMatrix(int nodes)
{

	int **mat = (int **)malloc(sizeof(int *) * nodes);
	int i = 0;
	while (i < nodes)
	{
		mat[i] = (int *)malloc(sizeof(int) * nodes);
		i++;
	}
	return mat;
}

void createMatrix(char ***nodes, int count, char *filename)
{
	char ch;
	FILE *file;
	file = fopen(filename, "r"); // read mode

	if (file == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	char array[70];
	char *subarray;

	*nodes = (char **)malloc(count * count * sizeof(char));

	int n = 0;
	char *newsubarray;
	int i = 0;
	while (!feof(file))
	{
		fgets(array, 1001, file);
		newsubarray = strtok(array, " ");
		while (newsubarray != NULL)
		{
			strcpy((*nodes)[n], newsubarray);
			newsubarray = strtok(NULL, " ");
		}
		n++;
		//n1=0;
		i++;
	}

	//printf("After tikenize %s \n", newsubarray[1]);
	fclose(file);
	//return newsubarray;
	//printf("After tikenize %s \n", newsubarray);
}

void readFile(Graph **g, char **str_nodes, int count, char *filename)
{
	FILE *fp = fopen(filename, "r");
	char line[1001];
	char *subarray;
	int i = 0;
	while (!feof(fp))
	{
		fgets(line, 1001, fp);
		subarray = strtok(line, " \n");
		while (subarray != NULL)
		{
			if (strcmp(str_nodes[i], subarray) != 0)
			{

				int j = 0;
				//printf("VAlue of j is %d \n",j);
				int z = 0;
				while (z < count)
				{
					if (strcmp(str_nodes[z], subarray) == 0)
						j = z;
					z++;
				}

				(*g)->matrix[j][i] = 1;
				//add_edge(&(*g), j, i);
			}
			subarray = strtok(NULL, " \n");
		}
		i++;
	}

	fclose(fp);
}

int main()
{
	printf("Enter name of a file you wish to see\n");
	char filename[100];
	scanf("%s", filename);
	char **str_nodes;

	int numOfNodes = check(&str_nodes, filename);
	printf("Total Numbers of nodes are:  %d", numOfNodes);

	//Create and Initialize a graph struct
	Graph *graph;
	graph = (Graph *)malloc(sizeof(Graph));
	graph->numOfRows = numOfNodes;
	graph->matrix = NewMatrix(graph->numOfRows);

	int i = 0;
	while (i < numOfNodes)
	{
		int j = 0;
		while (j < numOfNodes)
		{
			graph->matrix[i][j] = 0;
			j++;
		}
		i++;
	}

	//Populate Graph
	readFile(&graph, str_nodes, numOfNodes, filename);

	//Print matrix
	printf("\n\n");
	printf(" Matrix Are: \n");
	printf("   ");
	i = 0;
	while (i < graph->numOfRows)
	{
		printf("%d ", i);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < graph->numOfRows)
	{
		printf(" %d ", i);
		int j = 0;
		while (j < graph->numOfRows)
		{
			printf(" %d", (graph->matrix)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	//free memory
	i = 0;
	while (i < numOfNodes)
		free(str_nodes[i++]);
	free(str_nodes);
	i = 0;
	while (i < graph->numOfRows)
	{
		free(graph->matrix[i]);
		i++;
	}
	free(graph->matrix);

	return 0;
}