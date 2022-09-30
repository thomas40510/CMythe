#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Implementation of a circular buffer from circular_buffer.h
 */

struct circular_buffer {
    int size;
    int write_index;
    int read_index;
    float *buffer;
};

void initialize_circular_buffer(struct circular_buffer *cb, int length){
    /*
     * Allocate the buffer array of the struct and initialize other variables
     */
    cb->size = length;
    cb->write_index = 0;
    cb->read_index = 0;
    cb->buffer = malloc(length * sizeof(float));
    // all elements to 0
    memset(cb->buffer, 0.0f, length * sizeof(float));
}

/* Free the buffer array of the struct */
void free_circular_buffer(struct circular_buffer *cb){
    free(cb->buffer);
    cb-> buffer = NULL;
    cb->write_index = 0;
    cb->read_index = 0;
    cb->size = 0;
}

void set_read_index_position(struct circular_buffer *cb, int pos){
    if (pos < 0 || pos >= cb->size){
        printf("Error: invalid position");
        exit(1);
    } else{
        cb->read_index = pos;
    }
}


void write_sample(struct circular_buffer *cb, float sample){
    cb->buffer[cb->write_index] = sample;
    cb-> write_index = (cb -> write_index + 1 >= cb->size) ? 0 : cb->write_index + 1;
}

float read_sample(struct circular_buffer *cb){
    float sample = cb->buffer[cb->read_index];
    cb->read_index = (cb->read_index + 1 >= cb->size) ? 0 : cb->read_index + 1;
    return sample;
}
