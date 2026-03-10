#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "edit.h"

void show_help() {
    printf("Usage:\n");
    printf("  mp3tag [options] <filename>\n\n");
    printf("Options:\n");
    printf("  -t <title>     Change Title (TIT2)\n");
    printf("  -a <artist>    Change Artist (TPE1)\n");
    printf("  -A <album>     Change Album (TALB)\n");
    printf("  -y <year>      Change Year (TYER)\n");
    printf("  -g <genre>     Change Genre (TCON)\n");
    printf("  -c <composer>  Change Composer (TCOM)\n");
    printf("  -h             Show help info\n");
    printf("  -v             Show version info\n\n");
    printf("Examples:\n");
    printf("  ./mp3tag samplefiles/song.mp3\n");
    printf("  ./mp3tag -t \"New Title\" -a \"New Artist\" samplefiles/song.mp3\n");
}

void show_version() {
    printf("mp3tag - Simple MP3 Tag Reader & Editor (ID3v2.3)\n");
    printf("Version 1.0\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Use -h for help.\n");
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0) {
        show_help();
        return 0;
    }
    if (strcmp(argv[1], "-v") == 0) {
        show_version();
        return 0;
    }

    char *title = NULL, *artist = NULL, *album = NULL, *year = NULL, *genre = NULL, *composer = NULL;
    char *filename = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) title = argv[++i];
        else if (strcmp(argv[i], "-a") == 0 && i + 1 < argc) artist = argv[++i];
        else if (strcmp(argv[i], "-A") == 0 && i + 1 < argc) album = argv[++i];
        else if (strcmp(argv[i], "-y") == 0 && i + 1 < argc) year = argv[++i];
        else if (strcmp(argv[i], "-g") == 0 && i + 1 < argc) genre = argv[++i];
        else if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) composer = argv[++i];
        else filename = argv[i];
    }

    if (!title && !artist && !album && !year && !genre && !composer) {
        view_tags(filename);
    } else {
        edit_tags(filename, title, artist, album, year, genre, composer);
    }

    return 0;
}
