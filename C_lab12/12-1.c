#include <stdlib.h>
#include <stdio.h>
struct crops{
    char name[20];
    char type;
    int sowingArea;
    int cropCapacity;
};
int getN(){
    printf("Enter rows count: ");
    int n = scanf_s("%d", &n);
    return n;
}
int main(){
    int n = 3;
    struct crops * structCrops = (struct crops *)malloc(n*sizeof(struct crops));
    for (int i = 0; i < n; ++i) {
        printf("Input name: ");
        scanf("%s", &structCrops[i].name);
        printf("Input type (1 - cereal / 2 - beans): ");
        int options = scanf("%d", &options);
        while (options!=1 && options!=2) {
            printf("\nError. Try again: ");
            scanf("%d", &options);
        }
        if (options == 1) structCrops[i].type = 'c';
        else structCrops[i].type = 'b';
        printf("Input sowing area: ");
        scanf("%d", &structCrops[i].sowingArea);
        printf("Input crop capacity: ");
        scanf("%d", &structCrops[i].cropCapacity);
    }
    for (int j = 0; j<n; j++){
        for (int d = 0; d<n; d++){
            if(structCrops[d].sowingArea>structCrops[d+1].sowingArea){
                struct crops temp = structCrops[d];
                structCrops[d] = structCrops[d+1];
                structCrops[d+1] = temp;
            }
        }
    }
    printf("-------------------------------------------------\n");
    printf("Crops list\n");
    printf("-------------------------------------------------\n");
    printf("| Name\t| Type | Sowing area | Crop capacity |\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| %s | %c | %d\t| %d\t|\n",structCrops[i].name, structCrops[i].type, structCrops[i].sowingArea, structCrops[i].cropCapacity);
        printf("-------------------------------------------------\n");
    }
    printf("c - cereal / b - beans\n");
    return 0;
}