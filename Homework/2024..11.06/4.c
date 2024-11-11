#include<stdio.h>

#include<string.h>

struct entry

{

    char word[50];
    char definition[200];

};

void dictionarySort(struct entry dictionary[],int entries)

{

    //该函数用来对字典进行排序
    //dictionary[]为字典数组,entries为字典条目数

    for(int i=0;i<entries;i++){
        for(int j=1;j<entries-i;j++){
            if(strcmp(dictionary[j-1].word,dictionary[j].word) > 0){
                struct entry temp;
                temp = dictionary[j-1];
                dictionary[j-1] = dictionary[j];
                dictionary[j] = temp;
            }
        }
    }

    printf("After sorting them alphabetically.\n");
    for(int entry = 0; entry < entries; entry++){
        printf("%s%s\n",dictionary[entry].word,dictionary[entry].definition);
    }
}

int main()

{

int entry,entries;

scanf("%d",&entries);

struct entry dictionary[entries]; 

for(entry = 0; entry < entries; entry++)

{

scanf("%s:",dictionary[entry].word);

gets(dictionary[entry].definition);

}

dictionarySort(dictionary,entries);    

}