
#include "main.h"

#define READ_BUFF_SIZE     32

static FILE *file   = NULL;
static char *buffer = NULL;

ret_type cleanup_read() {
    if (file) {
        fclose(file);
        file = NULL;
    }
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
    return (OK);
}

ret_type init_read(char *file_name) {
    cleanup_read();
    if ((file = fopen(file_name, "r")) == NULL) {
        printf("ERROR: file \"%s\" doesn't exist\n", file_name);
        return (ERROR);
    }
    buffer = malloc(sizeof(char));
	buffer[0] = '\0';
    return (OK);
}

ret_type remove_space(char **line) {
    char *new_line;
    int   len;
    int   i;

    i = 0;
    len = 0;
    while ((*line)[i] != '\0' && (*line)[i] != '#') {
        if ((*line)[i] != ' ' && (*line)[i] != '\t') {
            len++;
        }
        i++;
    }
    new_line = malloc(sizeof(char) * (len+1));
    i = 0;
    len = 0;
    while ((*line)[i] != '\0' && (*line)[i] != '#') {
        if ((*line)[i] != ' ' && (*line)[i] != '\t') {
            new_line[len++] = (*line)[i];
        }
        i++;
    }
    new_line[len] = '\0';
    free(*line);
    *line = new_line;
    return (OK);
}

ret_type return_line(char **line) {
    char    *old_buffer;
    char    *ptr;
    
    //positionning ptr
    ptr = strchr(buffer, '\n');
    if (!ptr) {
        ptr = buffer + strlen(buffer);
    }

    //malloc new_buffer
    old_buffer = buffer;
    if (*ptr == '\0') {
        buffer = malloc(sizeof(char));
	    buffer[0] = '\0';
    } else {
        buffer = malloc(sizeof(char) * (strlen(ptr+1) + 1));
        strcpy(buffer, ptr+1);
    }

    //malloc line
    *ptr = '\0';
    *line = malloc(sizeof(char) * (strlen(old_buffer) + 1));
    strcpy(*line, old_buffer);

    free(old_buffer);
    remove_space(line);
    return (OK);
}

ret_type read_buffer() {
    char   *new_buffer;
    int     read_size;
    char    read_buffer[READ_BUFF_SIZE+1];

    read_size = fread(read_buffer, sizeof(char), READ_BUFF_SIZE, file);
    if (read_size <= 0) {
        return (READ_EOF);
    }
    read_buffer[read_size] = '\0';
    new_buffer = malloc(sizeof(char) * (strlen(buffer) + read_size + 1));
    strcpy(new_buffer, buffer);
    strcat(new_buffer, read_buffer);
    free(buffer);
    buffer = new_buffer;
    return (OK);
}

ret_type get_new_line(char **line) {
    ret_type  ret;

    ret = OK;
    while (ret == OK) {
        if (strchr(buffer, '\n') != NULL) {
	    	return (return_line(line));
        }
        ret = read_buffer();
    }
    if (buffer[0] != '\0')
		return (return_line(line));
	return (READ_EOF);
}