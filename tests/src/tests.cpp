#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C"
{
#include "max.h"
#include "list.h"
}

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("max")
{
   
    int numbers1[] = {5, 10, 20, 6, 10, -1, 9};
    REQUIRE(max(numbers1, 7) == 20);

    int numbers2[] = {5, 1, 4};
    REQUIRE(max(numbers2, 3) == 5);

}

TEST_CASE("size")
{
    node *l = (node *) malloc(sizeof(node));
    l->next=NULL;
    REQUIRE(size(l)==0);

    l->next = (node*) malloc(sizeof(node));
    l->next->next=NULL;
    l->next->data=10;

    REQUIRE(size(l)==1);

    l->next->next=(node*) malloc(sizeof(node));
    l->next->next->next = NULL; 
    l->next->next->data = 20; 

    REQUIRE(size(l)==2);

}

TEST_CASE("largest")
{
    node *l = (node*) malloc(sizeof(node));
    l->data=0;
    l->next = NULL;
    
    l->next = (node*) malloc(sizeof(node));
    l->next->next=NULL;
    l->next->data=0;
    REQUIRE(largest(l)==0);
    
    node *p;
    for (int i=10; i>0; i--) {
        p = l;
        while (p->next!=NULL) {
            p= p->next;
        }
        p->next = (node*) malloc(sizeof(node));
        p=p->next;
        p->next=NULL;
        p->data = i;
    }
    REQUIRE(largest(l)==10);

    l->next->next->next->data = 100;

    REQUIRE(largest(l)==100);

}


