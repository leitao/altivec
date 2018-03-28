#include <altivec.h>
#include <stdio.h>

void print_vec_char(char *s, vector signed char _data){
    int i;

    printf("%s\t:", s);
    for (i = 0 ; i <= 15; i++)
        printf("%3d ", vec_extract(_data, i));
    printf("\n");
}

void print_vec_long(char *s, vector signed long int _data){
    int i;

    printf("%s\t:", s);
    for (i = 0 ; i <= 1; i++)
        printf("%ld ", vec_extract(_data, i));
    printf("\n");
}

int main(){
    vector signed long int output;
    signed char x, y;
    vector signed char _data;
    const vector signed char bits = {120, 112, 104, 96, 88, 80, 72, 64, 56, 48, 40, 32, 24, 16, 8, 0};


    // Initialize the vector _data with the same values
    _data = vec_splat_s8(-1);

    print_vec_char("_data", _data);
    print_vec_char("bits", bits);

    output = vec_vbpermq(_data, bits);
    print_vec_long("output", output);

    y = vec_extract(output, 0);
    x = vec_extract(output, 1);

    printf("First Half  = %x\n", y);
    printf("Second Half = %x\n", x);

}
