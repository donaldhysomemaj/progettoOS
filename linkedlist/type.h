#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct Type{
    int info;
}Type;

Type* new_type(int info){
    Type *t = malloc(sizeof(Type));
    t->info=info;
    return t;
}

void print_type(void *item){
    printf("%d - ", ((Type*)item)->info);
}

void *getType(){
    return print_type;
}

