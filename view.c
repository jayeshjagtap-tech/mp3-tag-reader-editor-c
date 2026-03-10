#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"

/* Helper structure to store tag info temporarily */
typedef struct {
    char id[5];
    char value[256];
    int found;
} FrameData;

/* Function to read one frame and check if it matches the desired frame ID */
void read_frame(FILE *fp, FrameData *frame) {
    char id[5] = {0};
    unsigned char size_bytes[4];
    unsigned int size = 0;
    long position = ftell(fp);

    if (fread(id, 1, 4, fp) != 4) return;
    if (fread(size_bytes, 1, 4, fp) != 4) return;
    fseek(fp, 2, SEEK_CUR); // skip 2 flag bytes

    size = (size_bytes[0] << 24) | (size_bytes[1] << 16) | (size_bytes[2] << 8) | size_bytes[3];
    if (size == 0 || size > 1000) {
        fseek(fp, size, SEEK_CUR);
        return;
    }

    char *data = (char*)malloc(size + 1);
    fread(data, 1, size, fp);
    data[size] = '\0';

    if (strncmp(id, frame->id, 4) == 0) {
        /* Skip encoding byte and store text */
        strncpy(frame->value, data + 1, sizeof(frame->value) - 1);
        frame->value[sizeof(frame->value) - 1] = '\0';
        frame->found = 1;
    }

    free(data);

    /* Move to next frame */
    fseek(fp, position + 10 + size, SEEK_SET);
}

/* Main function to view tags */
void view_tags(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char header[3];
    fread(header, 1, 3, fp);
    if (strncmp(header, "ID3", 3) != 0) {
        printf("No ID3v2 tag found in %s\n", filename);
        fclose(fp);
        return;
    }

    printf("----- ID3v2.3 TAG INFO -----\n");

    /* Define the six frames you want to read */
    FrameData frames[6] = {
        {"TIT2", "", 0},
        {"TPE1", "", 0},
        {"TALB", "", 0},
        {"TYER", "", 0},
        {"TCON", "", 0},
        {"TCOM", "", 0}
    };

    /* Jump past 10-byte header */
    fseek(fp, 10, SEEK_SET);

    /* Read through tag section for all six frames */
    for (int i = 0; i < 6; i++) {
        long pos = ftell(fp);
        while (1) {
            char id[5] = {0};
            if (fread(id, 1, 4, fp) != 4) break;
            if (id[0] == 0) break; // reached end of tags
            fseek(fp, pos, SEEK_SET);
            read_frame(fp, &frames[i]);
            pos = ftell(fp);
            if (frames[i].found) break;
        }
        rewind(fp);
        fseek(fp, 10, SEEK_SET); // reset to after header for next search
    }

    /* Print all frames (even if not found) */
    for (int i = 0; i < 6; i++) {
        if (frames[i].found)
            printf("%s : %s\n", frames[i].id, frames[i].value);
        else
            printf("%s : (Not Present)\n", frames[i].id);
    }

    printf("----------------------------\n");
    fclose(fp);
}
