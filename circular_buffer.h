// the #ifndef / #define / #endif mecanism is used to prevent recursive inclusion by the preprocessor
#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

struct circular_buffer {
    float *buffer;
    int    size;
    int    write_index;
    int    read_index;
};

// Here we declare the prototype of our functions

/* Allocate the buffer array of the struct and initialize other variables */
void initialize_circular_buffer(struct circular_buffer *cb, int length);

/* Free the buffer array of the struct */
void free_circular_buffer(struct circular_buffer *cb);

void set_read_index_position(struct circular_buffer *cb, int pos);

void write_sample(struct circular_buffer *cb, float sample);

float read_sample(struct circular_buffer *cb);

#endif /* CIRCULAR_BUFFER_H */