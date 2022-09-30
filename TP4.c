#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_buffer.h"

void halfSoundLevel(const char *file);
void addEcho(const char *file, float delay, float attenuation);


int main() {
    halfSoundLevel("../sound/input.f32le");
    addEcho("../sound/input.f32le", 10, 2.0f);

    return 0;
}

void halfSoundLevel(const char * file){
    /*
     * Half the volume of a f32le file
     */

    // open file
    FILE *f = fopen(file, "r");
    FILE *res = fopen("../sound/result.f32le", "w");
    if (f == NULL){
        printf("Error opening file %s", file);
        exit(1);
    }

    for(;;){
        float sample;
        unsigned long n = fread(&sample, sizeof(float), 1, f);
        if (n == 0){
            break;
        }
        sample /= 2;
        fwrite(&sample, sizeof(float), 1, res);
    }

    fclose(f);
    fclose(res);
}

void addEcho(const char *file, float delay, float attenuation) {
    /*
     * Create echo in audio file
     */
    //open files
    FILE *f = fopen(file, "r");
    FILE *res = fopen("../sound/echoed.f32le", "w");

    if (f == NULL){
        printf("Error opening file %s", file);
        exit(1);
    }

    //read file and write to result file with echo
    struct circular_buffer cb;
    initialize_circular_buffer(&cb, delay);
    for(;;){
        float sample;
        unsigned long n = fread(&sample, sizeof(float), 1, f);
        if (n == 0){
            break;
        }
        float echo = read_sample(&cb);
        sample += attenuation * echo;
        write_sample(&cb, sample);
        fwrite(&sample, sizeof(float), 1, res);
    }

    fclose(f);
    fclose(res);
    free_circular_buffer(&cb);

}