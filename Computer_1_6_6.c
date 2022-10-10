#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct values
{
    int num1;
    int num2;
    int num3;
} values;

int assign_nums(values *ptr, int x)
{
    ptr->num1 = floor(x / 100);
    ptr->num2 = floor(x / 10 - ptr -> num1 * 10);
    ptr->num3 = (x - ptr->num1 * 100 - ptr->num2 * 10);
}

void encoding2(values *ptr, int registers[])
{
    registers[ptr->num2] = ptr->num3;
}

void encoding3(values *ptr, int registers[])
{
    registers[ptr->num2] += ptr->num3;
}

void encoding4(values *ptr, int registers[])
{
    registers[ptr->num2] *= ptr->num3;
}

void encoding5(values *ptr, int registers[])
{
    registers[ptr->num2] = registers[ptr->num3];
}

void encoding6(values *ptr, int registers[])
{
    registers[ptr->num2] += registers[ptr->num3];
}

void encoding7(values *ptr, int registers[])
{
    registers[ptr->num2] = registers[ptr->num3];
}

void encoding8(values *ptr, int registers[], int RAM[])
{
    registers[ptr->num2] = RAM[registers[ptr->num3]];
}

void encoding9(values *ptr, int registers[], int RAM[])
{
    RAM[registers[ptr->num3]] = registers[ptr->num2];
}



int main(void)
{
    int count = 0;
    int registers[10];
    for(int i = 0 ; i < 10 ; i++) registers[i] = 0;

    int RAM[1001];
    for(int i  = 0 ; i < 1000 ; i++) RAM[i] = 000;
    RAM[1000] = 100;
    char buffer[100];
    for(int i = 0; i<1000; i++){
    
        fgets(buffer, 100, stdin);

        if (sscanf(buffer, "%d", &RAM[i]) != 1) {
            break;
        }
    }
    int start_of_RAM = 0;
    bool condition = true;

    while(condition)
    {
        values current;
        values *ptr;
        int curr;
        ptr = &current;
        curr = RAM[start_of_RAM];
        count++;

        if (curr == 100)
        {
            condition = false;
        }

        assign_nums(ptr, curr);

    
        if(ptr->num1 == 2)
            encoding2(ptr, registers);
        if(ptr->num1 == 3)
            encoding3(ptr, registers);
        if(ptr->num1 == 4)
            encoding4(ptr, registers);
        if(ptr->num1 == 5)
            encoding5(ptr, registers);
        if(ptr->num1 == 6)
            encoding6(ptr, registers);
        if(ptr->num1 == 7)
            encoding7(ptr, registers);
        if(ptr->num1 == 8)
            encoding8(ptr, registers, RAM);
        if(ptr->num1 == 9)
            encoding9(ptr, registers, RAM);


        registers[ptr->num2] %= 1000;
        for(int i = 0; i < 10; i++) printf("%d: %d ",i ,registers[i]);
            printf("\n");

        start_of_RAM++;
        if(ptr->num1 == 0)
        {
            if(registers[ptr->num3] != 0)
                start_of_RAM = registers[ptr->num2];
            //rintf("%d", start_of_RAM);  
        }

    }
    printf("%d", count);
    return 0;
}