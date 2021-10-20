#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

struct std_info{
	char *std_name;
	int middle_score;
	int final_score;
};

// root tree
struct std_info *root = NULL;

int compare(const void *nameA, const void *nameB){
	return strcmp(((struct std_info *)nameA) -> std_name, (((struct std_info *)nameB) -> std_name));
}

void print_node(const void *nodeptr, VISIT order, int level)
{
	if(order == preorder || order == leaf){
		printf("name : %-5s mid : score : %d final score : %d\n"
				,(*(struct std_info **)nodeptr)->std_name, (*(struct std_info**)nodeptr)->middle_score, (*(struct std_info **)nodeptr)->final_score);
	}
}

int main(){
	int size, i=0;
	printf("input tree size: ");
	scanf("%d",&size);

	// student namespace
	char *std_name_table = (char *)malloc(20 * size);
	
	// node pointer
	struct std_info *std_table = (struct std_info *) malloc (size *sizeof(struct std_info));
	struct std_info **ret;

	printf("name, middle_score, final_score, THE END(CTRL+D)\n");
	while(scanf("%s%d%d",std_name_table, &std_table -> middle_score, &std_table->final_score) != EOF){
		i++;
		std_table->std_name = std_name_table;
		ret = (struct std_info **) tsearch((void *)std_table, (void **) &root, compare);
		printf("%s Student Name\n",(*ret)->std_name);
		if(*ret == std_table){
			printf("Add Tree\n");
		}else{
			printf("Already exists Tree\n");
			i--;
		}std_name_table += strlen(std_name_table) + 1;
		std_table++;
		
		// tree size over
		if ((i+1) > size){
			break;
		}
	}
	
	// node visit
	twalk((void *) root, print_node);
	return 0;
}


