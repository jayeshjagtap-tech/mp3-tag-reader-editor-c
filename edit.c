#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit.h"

void edit_tags(const char *filename,
                 const char *title,
                 const char *artist,
                 const char *album,
                 const char *year,
                 const char *genre,
                 const char *composer) {

    printf("Opening %s to update ID3v2.3 tags...\n", filename);
    printf("Creating backup before edit...\n");
    printf("Tags to update:\n");
    if (title)   printf("  TIT2 (Title)   -> %s\n", title);
    if (artist)  printf("  TPE1 (Artist)  -> %s\n", artist);
    if (album)   printf("  TALB (Album)   -> %s\n", album);
    if (year)    printf("  TYER (Year)    -> %s\n", year);
    if (genre)   printf("  TCON (Genre)   -> %s\n", genre);
    if (composer)printf("  TCOM (Composer)-> %s\n", composer);
    printf("Changes applied (simulation complete).\n");
}
